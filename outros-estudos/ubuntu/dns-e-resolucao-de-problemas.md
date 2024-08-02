# DNS e resolução de problemas

## O que é?

Vamos imaginar que a Internet é uma cidade enorme cheia de prédios, e cada prédio tem seu próprio endereço (podendo ser um site ou serviço). O **DNS** (Domain Name System) é como se fosse um GPS do prédio que você quer encontrar. Tecnicamente, o que buscamos (prédio) é um endereço de IP.

Quando digitamos "google" na barra de pesquisa, é como se dissessemos ao DNS que queremos visitar aquele prédio e o DNS que procura o caminho e o endereço de IP correspondente. Ele pode precisar perguntar a vários outros guias mais informados para encontrar esse número.

### Função dos servidores DNS configurados

Quando você configura esses IPs de servidores DNS no seu sistema ou na configuração do Docker dentro do Wings, estamos <mark style="color:purple;">direcionando todas as solicitações de DNS</mark> do sistema ou contêineres Docker para esses servidores específicos. Na prática, o servidor DNS procura em seu banco de dados para encontrar o IP associado ao nome de domínio solicitado.

Uma vez que o endereço IP é encontrado, ele é enviado de volta ao seu servidor ou contêiner Docker. Seu sistema então usa esse IP para estabelecer uma conexão direta com o servidor que hospeda o site ou serviço desejado.

Alguns provedores de internet ou redes empresariais podem ter seus próprios servidores DNS que são otimizados para seus clientes, oferecendo melhor desempenho ou recursos de segurança adicionais. É o caso que veremos mais adiante, onde configuramos IP de DNS da própria provedora, substituindo os antigos da Google Cloud.&#x20;

Concluindo, eles são essenciais para ajudar seu sistema a navegar pela internet de maneira eficiente. Essa configuração é uma parte fundamental da infraestrutura de rede que garante que você possa acessar sites e serviços online com rapidez e confiabilidade.

## Problema real de resolução DNS

Vimos em uma situação real em que estive sem acesso ao painel, funções FTP e conexões instáveis com o banco de dados, porém com conexão com a máquina via PowerShell. Esses problemas podem ter sido causados por <mark style="color:orange;">falhas na resolução de DNS</mark>. Isso pode ocorrer por várias razões, principalmente se os servidores DNS anteriores não estavam respondendo rapidamente ou corretamente ou incompatibilidade causada por mudanças na rede ou na infraestrutura de internet.

Para solucionar esse problema, foi necessário <mark style="color:green;">alterar os servidores DNS utilizados pelos contêineres</mark> Docker gerenciados pelo Wings. O problema ocorria pois o DNS é fundamental para a tradução de nomes de domínio para endereços IP. Os contêineres Docker, como os que o Pterodactyl utiliza para rodar jogos ou outros serviços, dependem dessa tradução para se comunicar com a internet ou outros serviços de rede.

Não suficiente, também é necessário fazer essa mesma alteração para o <mark style="color:green;">ambiente host</mark>, que é a rede do próprio servidor. Alterar o endereço DNS para esse ambiente, isso afeta todas as operações de rede realizadas diretamente pelo servidor, não apenas pelos contêineres Docker.

Então, mudando os endereços DNS alteramos os servidores que resolvem essas solicitações abrangidas acima. Esses <mark style="color:blue;">endereços foram fornecidos pela provedora</mark>, o que compactua com a ideia de DNS provido pela própria empresa.

### Mudanças práticas

E como tudo isso foi feito? Fizemos duas mudanças em dois ambientes diferentes, como dito acima: no Docker e na rede.

Começando pelo contâiner, a mudança que fizemos estava localizada em:

```bash
sudo nano /etc/pterodactyl/config.yml
```

Nesse arquivo, encontramos:

```yaml
docker:
  network:
    interface: 172.18.0.1  # Endereço IP da interface de rede do Docker
    dns:
      - 1.1.1.1
      - 1.0.0.1
```

Podemos observar dois endereços de IP já na categoria DNS que eram, até então, os utilizados. A empresa passou dois novos endereços de IPs que foram <mark style="color:orange;">substituídos</mark>. Reinciando o Wings, usando <mark style="color:red;">`sudo systemctl restart wings`</mark>, já aplicamos a primeira mudança, a qual não resolveu o problema logo de cara.

<mark style="color:blue;">Netplan</mark> é uma ferramenta de configuração de rede para sistemas operacionais baseados em Linux (especialmente os que utilizam systemd). Ao editar o arquivo `00-installer-config.yaml`, podemos <mark style="color:blue;">alterar a configuração de DNS usada pelo servidor host</mark>. O arquivo alterado tinha este formato:

```yaml
network:
    ethernets:
        enp3s0f0:
            adresses:
                - ... # Ip da máquina
            gateway4: ... # Ip da hospedagem
            nameservers:
                adresses:
                - 1.1.1.1 # Alteração aqui <--
                search: []
        enp3s0f1:
            dhcp4: true
        enp3s0:
            dhcp4: true
    version: 2
```

Adicionamos os mesmos endereços DNS fornecidos anteriormente. Usando o comando do Netplan, aplicamos as mudanças e o problema foi resolvido!

```bash
sudo netplan apply
```

### Quais eram os endereços antigos?

Os IPs já configurados anteriormente com 1.1.1.1 são de serviços públicos da Google Cloud. Eles pararam de funcionar corretamente de um tempo para outro pelos motivos já citados anteriormente. Nenhum desses endereços foi <mark style="color:red;">reaproveitado</mark> e sim todos substituídos.

### Usar dois IPs DNS

De forma meio óbvia, a utilização do segundo IP seria por questões de segurança caso o primário não esteja disponível ou retorne alguma falha. Isso vai aumentar a disponibilidade e em alguns casos, o uso desses endereços podem ser divididos para equilibrar a carga de uso dos mesmos.

### Considerações finais com os novos endereços

Os endereços recebidos pela hospedagem retornaram alguns avisos de segurança logo depois da sua aplicação:

<figure><img src="../../.gitbook/assets/problema de segurança com endereço dns.png" alt=""><figcaption></figcaption></figure>

Resolver esse problema é possível ajustando as permissões do arquivo para que somente o usuário root possa lê-lo e editá-lo. Isso pode ser feito com o seguinte comando:

```bash
sudo chmod 600 /etc/netplan/00-installer-config.yaml
```
