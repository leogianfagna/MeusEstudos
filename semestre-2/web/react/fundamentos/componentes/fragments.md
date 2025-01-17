# Fragments

São <mark style="color:blue;">exatamente componentes porém com tags vazias</mark>. Servem para ser um recurso pai não alterando a estrutura do HTML, para isso, utilizando tags vazias neste formato: `<> ... </>`. Isso não exige novas regras de CSS.

#### Exemplo 1: Não é um fragmento

Estrutura comum de um componente, localizado dentro de uma div. Ao inserir no App ou em outra estrutura, o pai dos elementos `h1` e `h2` são a `div` circulada do próprio componente.

<figure><img src="../../../../../.gitbook/assets/componente normal react.png" alt=""><figcaption></figcaption></figure>

#### Exemplo 2: Fragments

Remove a tag div do componente deixando apenas uma tag vazia. Ao adicionar no App ou em outra estrutura, o pai dos elementos `h1` e `h2` se torna a `div` que recebeu o componente.

<figure><img src="../../../../../.gitbook/assets/componente fragment react.png" alt=""><figcaption></figcaption></figure>
