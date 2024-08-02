---
description: >-
  Fonte:
  https://www.hostinger.com.br/tutoriais/como-proteger-centos-6-vps-com-fail2ban
---

# Fail2Ban

O Fail2Ban é um software de sugerança de servidores Linux, que pode ajudar a proteger seu servidor contra ataques de força bruta, bloqueando IPs após várias tentativas de login falhadas de forma automatica.

Ele pode fornecer regras customizáveis para banir os IPs corretos e até fornecer suporte por email.

## Instalação

```bash
sudo apt-get install fail2ban
sudo systemctl enable fail2ban
sudo systemctl start fail2ban
```

Depois de realizar esses comandos, alguns serviços precisam ser reiniciados. O próprio sistema já mostra o menu de reincialização automática após a instalação.

## Após instalação

O Fail2Ban já está configurado para procurar IPs e bloqueá-los automaticamente, então teoricamente já está instalado e funcionando. Contudo, há diversas configurações que podem ser feitas opcionalmente.

O arquivo de configuração está em `/etc/fail2ban/jail.local`, mas para realizar nossas configurações, devemos copiar esse arquivo e transformá-lo a cópia em `jail.local`. Para isso, fazemos:



dsadasdasdasd

1.  Copiar o arquivo de configuração padrão para um local:

    ```sh
    sudo cp /etc/fail2ban/jail.conf /etc/fail2ban/jail.local
    ```
2.  Abrir o arquivo local para inserir nossas configurações:

    ```sh
    sudo nano /etc/fail2ban/jail.local
    ```
3.  Adicionar nossas configurações manualmente. Veja esse exemplo onde traz novas opções para a seção sshd. Lembrando que não especificar alguma delas vai fazer com que o programa utilize o que está pré configurado no arquivo `.conf`:

    ```
    [sshd]
    enabled = true
    port = ssh
    filter = sshd
    logpath = /var/log/auth.log
    maxretry = 3
    bantime = 3600
    ```
4. Salvar e fechar as mudanças (usando Ctrol + X)
5.  Reinciar o Fail2Ban para aplicar as mudanças:

    ```sh
    sudo systemctl restart fail2ban
    ```
6.  Verificar o status para conferir se está funcionando corretamente:

    ```sh
    sudo fail2ban-client status
    sudo fail2ban-client status sshd
    ```

## Conferindo status do programa

Os comandos da etapa 6 acima vão retornar as seguintes mensagens:

<figure><img src="../../../.gitbook/assets/historico do fail2ban.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/fail2ban protegendo sshd.png" alt=""><figcaption></figcaption></figure>

O failed na primeira imagem simboliza tentativas de login ineficazes. O número de prisões na segunda imagem simboliza quantos serviços estão habilitados, que no caso é apenas o sshd.

O fato de `sshd` estar na lista de jails significa que o Fail2ban está ativamente protegendo o serviço SSH contra acessos não autorizados. Se você tivesse outros serviços que deseja proteger, poderia configurar jails adicionais para esses serviços, e eles também apareciam na lista de jails ativos quando estivessem em funcionamento.

> Assim como todos os programas instalados, podemos conferir o status dele usando `sudo systemctl status fail2ban`

<figure><img src="../../../.gitbook/assets/status do fail2ban.png" alt=""><figcaption></figcaption></figure>
