# API

É uma comunicação entre aplicações através de uma interface, geralmente as respostas são em JSON. Um projeto/aplicação pode usar várias APIs e outras aplicações. Quando criamos um back-end em node ou qualquer outra linguagem que utilize rotas, configurações, etc, significa que estamos criando uma API para ser utilizada.

É baseado em requisições e respostas, por isso, não possuem telas. Envia um texto em uma requisição e recebe outro de volta em uma resposta através de uma rota. Em web, criaremos APIs com express.

## REST e RESTful

São padrões de arquitetura de como a API deve ser criada, quando uma API cumpre com todos os padrões de aplicação, ela é considerada RESTful.

Alguns exemplos de padrões são respostas uniformes das requisições (seja sucesso, seja erro, etc), sem ligação de estado, cache de respostas e outros. Todos esses padrões estão documentados [neste site da IBM](https://www.ibm.com/think/topics/rest-apis).

Quando criamos um back-end

## SPA

Uma Single Page Application (SPA) é um tipo de aplicação web que se destaca por carregar uma única página HTML, onde o conteúdo é dinamicamente atualizado conforme a interação do usuário, sem a necessidade de recarregar a página completamente quando o usuário navega entre diferentes seções.

Elas são geralmente [<mark style="color:orange;">construídas usando frameworks</mark>](#user-content-fn-1)[^1] JavaScript populares como React, Angular ou Vue.js, que permitem a manipulação efetiva do DOM. SPAs frequentemente utilizam bibliotecas ou soluções de gerenciamento de estado para lidar com dados e manter a consistência da interface do usuário (usam rotas no lado do cliente, o que facilita navegação).

Antes da criação das SPAs, a arquitetura de um projeto era chamada de <mark style="color:purple;">arquitetura monolítica</mark> que significa que o front e o back eram integrados em um mesmo sistema. Na SPA, o front-end é separado do back-end e a comunicação entre os dois é feita através de APIs.

## Verbos HTTP

O que define o local onde os parâmetros são passados é o **protocolo de comunicação** da web, o **HTTP** e esse protocolo possui alguns métodos, que são os verbos. Eles definem qual ação deve ser realizada, como `GET`, `POST`, `PUT`, `DELETE` E `PATCH`.

[^1]: Não quer dizer que React é uma SPA e sim que oferece ferramentas para a construção de uma.
