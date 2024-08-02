# Uso básico

## Navegação de arquivos

O comando <mark style="color:purple;">`nano`</mark> é utilizado para navegar e abrir arquivos dentro da máquina. Precisamos ter o local em que esse arquivo está localizado, assim, utilizaremos:

```bash
sudo nano /etc/fail2ban/jail.local
```

Você também pode alterara `nano` por `vim`, que é um editor mais avançado e mais complexo.

Para reiniciar um sistema Ubuntu (ou qualquer sistema Linux), você pode usar o comando `reboot` ou `shutdown` (com mais opções). Isso pode ser feito via SSH ou diretamente no terminal local.

## Reinicialização

```shell
sudo reboot
```

Você também pode usar o comando shutdown para reiniciar o sistema. Este comando permite agendar a reinicialização ou desligamento com mais opções

### Reiniciar imediatamente

Mesmo efeito do `sudo reboot`

```shell
sudo shutdown -r now
```

### Programar

```shell
sudo shutdown -r 22:00
```

> `-r` simboliza para reinciar o sistema após desligar.

Depois de executar um dos comandos acima, o sistema iniciará o processo de reinicialização. Isso encerrará todas as sessões ativas e reiniciará o sistema operacional. Dependendo dos serviços em execução no seu servidor, pode levar alguns minutos para que tudo volte ao normal.
