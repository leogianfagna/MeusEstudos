# Introdução

SQL é uma linguagem de banco de dados. Linguaguem estruturada de consulta.

Elementos de um banco de dados: diagrama, banco de dados, tabelas, colunas e dados.

<details>

<summary>Instalação MySQL</summary>

Download mysql: [https://dev.mysql.com/downloads/installer/](https://dev.mysql.com/downloads/installer/)

Se os bancos (schemas) não estiverem aparecendo na parte lateral esquerda: [https://stackoverflow.com/questions/47645158/mysql-workbench-left-navigator-panel-missing-on-mac](https://stackoverflow.com/questions/47645158/mysql-workbench-left-navigator-panel-missing-on-mac)

#### Executar pelo terminal

Adicionar isso nas variáveis de ambiente.

![](<../../../.gitbook/assets/mysql path.png>)

</details>

## Gerenciando banco

Um banco de dados é a entidade, que fica as tabelas, views, triggers, etc.

```sql
CREATE DATABASE teste;
DROP DATABASE teste;

# Usar o banco criado
USE teste;

# Visualizar todos os bancos
SHOW DATABASES;
```

É possível usar um banco de dados sem estar selecionado com USE, mas não é recomendado. A forma de fazer isso é especificar o nome do banco antes do nome da tabela em um comando, dessa forma:

```sql
SELECT * FROM empresa.funcionarios;
# Empresa = Banco
# Funcionarios = Tabela dentro desse banco
```

## Convenção

Todos comandos de SQL são maíusculos e nomes minúsculos. Nomes compostos são usados com underline, tipo `nome_tabela`. Usar ponto e vírgula.

## Importação de banco de dados

Arquivo pronto que será inserido no SGDB.&#x20;

1. Criei um novo banco de dados.
2. Importar o SQL, duas maneiras:
   1. Fazer com script:
      1. Usei o USE para usar ele.
      2. "Open a SQL script file in a new query tab"
      3. Adicionei o arquivo SQL baixado nele.
      4. Executei ele inteiramente.
   2. Utilizar a opção Server > Data Import
      1. Selecionar o banco desejado
      2. Selecionar o arquivo SQL
      3. Vai em import progress
      4. Clicar em start import
3. Agora importou as tabelas para o banco teste.

É importante saber fazer pelo terminal pois em produção não provavel não vai ter acesso a isso.

## Exportação

A exportação de um banco vira um arquivo `.sql`. ~~Esse comando são todos os scripts de um banco para criação e inserção de tabelas e os dados que havia lá~~ (melhorar). Para fazer isso com comando:

```bash
mysqldump -u root nome_banco > nome_arquivo.sql
```

É possível fazer na página "Server" no Mysql WorkBench.

## Comentários no código

Para linha única usar `--` ou `#`. Para múltiplas linhas igual JavaScript com `/* */`.
