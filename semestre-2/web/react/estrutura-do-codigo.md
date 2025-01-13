# Estrutura do código

A estrutura base de um projeto React segue essa formatação:

* `node_modules`: Dependências que não serão alteradas.
* `public`: Assets estáticos (fotos, icons, etc) e HTML de inicialização (HTML básico que o React roda ao iniciar).
* `src`: Programação em react (hooks, componentes, configurações, basicamente tudo).
  * `index.js`: Arquivo de inicialização e instruções do React. Ele que chama o HTML de inicialização.
  * `App.js`: Componente principal da aplicação.
