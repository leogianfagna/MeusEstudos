# Reinicialização

Para reiniciar um sistema Ubuntu (ou qualquer sistema Linux), você pode usar o comando `reboot` ou `shutdown` (com mais opções). Isso pode ser feito via SSH ou diretamente no terminal local.

## Reboot

Execute no terminal:

```shell
sudo reboot
```

## Shutdown

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
