# Pacotes

## Atualizações disponíveis

Atualizar o sistema no contexto de um sistema operacional como o Ubuntu envolve a atualização dos pacotes de software instalados:

#### 1) Atualização dos Índices de Pacotes:

O sistema precisa instalar as informações mais recentes sobre os pacotes disponíveis dos repositórios configurados. Isso inclui informações sobre versões atualizadas dos pacotes e suas dependências. Este comando não instala ou atualiza nenhum pacote; ele apenas atualiza os índices dos pacotes. Para fazer isso, use:

```shell
sudo apt-get update
```

Índices dos pacotes é apenas uma lista de pacotes disponíveis nos repositórios configurados no sistema que contém informações sobre os pacotes, como nomes, versões, dependências e fontes de download.

#### 2) Atualização dos Pacotes Instalados:

Depois de atualizar os índices dos pacotes, você pode atualizar os pacotes instalados. Este comando instala as versões mais recentes dos pacotes que já estão instalados no seu sistema, desde que essas atualizações não requerem a instalação ou remoção de outros pacotes.

Para verificar os pacotes disponíveis para atualização:

```shell
apt list --upgradable
```

Para atualizar os pacotes, utilize:

```shell
sudo apt-get upgrade
```

#### 3) Atualização Completa dos Pacotes:

Se houver atualizações que requerem a instalação de novos pacotes ou a remoção de pacotes existentes, você pode usar o comando sudo `apt-get dist-upgrade`. Este comando é mais abrangente e lida com as mudanças nas dependências, garantindo que todos os pacotes sejam atualizados conforme necessário.

Revisar atualizações que requerem novos pacotes ou remoção usando:

```shell
sudo apt-get dist-upgrade
```

#### 4) Finalização

Possivelmente uma restart na máquina será necessário após a instalação de tantos pacotes. Veja em **reinicialização do sistema** como fazer.

## Motivos de atualizações

Manter o sistema atualizado é crucial por várias razões:

* **Correções de Segurança:** As atualizações frequentemente incluem correções para vulnerabilidades de segurança, ajudando a proteger o seu sistema contra ataques.
* **Correções de Bugs:** Atualizações podem corrigir problemas e bugs nos pacotes de software.
* **Novos Recursos:** Às vezes, as atualizações trazem novos recursos e melhorias de desempenho.
* **Compatibilidade:** Manter os pacotes atualizados garante a compatibilidade com outros softwares e dependências.
