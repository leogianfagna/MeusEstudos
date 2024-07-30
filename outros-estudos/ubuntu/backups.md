# Backups

## Fazer backups

Esses comandos abaixo criam pastas zipadas de certos diretórios para criar backups:

```bash
# Backup dos arquivos de configuração
sudo tar -czvf etc-backup.tar.gz /etc

# Backup dos dados do usuário
sudo tar -czvf home-backup.tar.gz /home

# Backup dos dados do MySQL
mysqldump --all-databases > all-databases-backup.sql

# Backup dos dados do PostgreSQL
pg_dumpall > all-databases-backup.sql

# Backup da lista de pacotes instalados
dpkg --get-selections > package-selections-backup.txt

# Backup do estado atual do sistema
sudo apt-mark showauto > package-auto-backup.txt
sudo apt-mark showmanual > package-manual-backup.txt
```

## Download dos arquivos

Podemos instalá-los na nossa máquina sendo usada atualmente (do Ubuntu para nosso disco) de duas formas, usando scp ou rsync:

| Característica  | scp                       | rsync                                                                                           |
| --------------- | ------------------------- | ----------------------------------------------------------------------------------------------- |
| Funcionalidade  | Simples cópia de arquivos | Sincronização incremental                                                                       |
| Velocidade      | Transferência direta      | Otimizado para transferências incrementais e pode ser mais rápido para grandes volumes de dados |
| Segurança       | Utiliza SSH               | Utiliza SSH (quando configurado)                                                                |
| Uso de recursos | Pode ser menos eficiente  | Mais eficiente em termos de largura de banda e tempo para transferências repetidas              |
| Versatilidade   | Menos opções              | Mais opções para exclusão de arquivos, preservação de atributos, etc.                           |
| Compressão      | Não suporta               | Suporta compressão durante a transferência                                                      |

Portanto, usaremos scp para cópias rápidas, como baixar os arquivos para nosso computador sem a necessidade de algo especial. Dessa forma:

```bash
scp user@seu_servidor:/caminho/para/o/backup.tar.gz /caminho/local/salvar/

# Usando rsync
rsync -avz user@seu_servidor:/caminho/para/o/backup.tar.gz /caminho/local/salvar/
```

Portanto, instalar todos os backups feitos acima, usaremos os seguintes comandos:

```bash
scp user@seu_servidor:/home/user/etc-backup.tar.gz /home/local_user/
scp user@seu_servidor:/home/user/home-backup.tar.gz /home/local_user/
scp user@seu_servidor:/home/user/all-databases-backup.sql /home/local_user/
scp user@seu_servidor:/home/user/package-selections-backup.txt /home/local_user/
scp user@seu_servidor:/home/user/package-auto-backup.txt /home/local_user/
scp user@seu_servidor:/home/user/package-manual-backup.txt /home/local_user/
```

