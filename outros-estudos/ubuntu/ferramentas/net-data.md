# Net Data

NetData é uma ferramenta de monitoramento de desempenho em tempo real, projetada para fornecer insights detalhados sobre a saúde e o desempenho de sistemas e aplicativos. Aqui estão algumas de suas principais características e benefícios:

* Monitoramento em Tempo Real: NetData coleta dados de desempenho de sistemas, serviços, aplicativos, bancos de dados e outros componentes em tempo real, permitindo a visualização instantânea de métricas.
* Visualizações Ricas: A ferramenta oferece gráficos interativos e detalhados que ajudam a entender rapidamente o estado e o desempenho do sistema. Isso inclui gráficos de CPU, memória, disco, rede e muito mais.
* Alertas e Notificações: NetData pode ser configurado para enviar alertas e notificações quando certas condições são atendidas (por exemplo, quando o uso da CPU ultrapassa um determinado limite), ajudando a detectar e resolver problemas rapidamente.
* Baixo Impacto no Sistema: NetData é projetado para ser extremamente eficiente, utilizando poucos recursos do sistema, o que significa que não deve afetar significativamente o desempenho do servidor que está monitorando.
* Fácil de Instalar e Configurar: A instalação do NetData é geralmente simples e suporta uma ampla gama de sistemas operacionais, incluindo várias distribuições Linux, Windows e MacOS.
* Open Source: NetData é um projeto de código aberto, o que significa que é gratuito para usar e a comunidade pode contribuir para seu desenvolvimento.

## Instalação

1. Atualizar o Sistema:

```shell
sudo apt-get update
```

2. Instalar Dependências:

```shell
sudo apt-get install -y curl
```

3. Instalar o NetData:

```shell
bash <(curl -Ss https://my-netdata.io/kickstart.sh)
```

4. Acessar a Interface Web: Depois de instalado, você pode acessar a interface web do NetData digitando o endereço IP do seu servidor seguido pela porta 19999 no seu navegador: `http://<endereço_IP_do_servidor>:19999`
