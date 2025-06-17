# Memo

Serve para não re-renderizar certos elementos quando as props passadas para ele não mudarem, criando otimização ao <mark style="color:blue;">evitar renderizações desnecessárias</mark>. Se o elemento pai desse elemento ou até componente se renderizar, ele individualmente não irá.

Ele <mark style="color:green;">não é limitado apenas à componentes</mark>. Uma grande seção de simples `input` por exemplo pode ser muito pesado a cada alteração (exemplo de lista virtualizadas, com milhares de inputs). Faz todo sentido usar memo em cada um deles para cada vez que a lista se mexer, não ficar renderizando todos novamente e o custo operacional será praticamente zero.

{% hint style="warning" %}
Para um componente ser memorizado, a lógica por trás é que esse elemento de fato não precisa ser modificado a menos que algum estado mude. Essa é a lógica pura de renderização do React.
{% endhint %}

## Como memorizar

Basta envolver um elemento ou componente em um memo. Isso retornará um novo componente memorizado pronto para ser usado no JSX.

