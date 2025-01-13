# Arrow Function

É como se fosse uma função para criar recursos de forma mais simples. Elas são funções anônimas, ou seja, não possuem nome. Quando uma função não possui nome, é omitido as palavras `function nomeDaFuncao`.

Devemos saber como conceito introdutório que podemos atribuir uma função à uma determinada variável, por exemplo: `const sum = function sum (a,b) {...}`. As arrow functions partem do mesmo princípio, a partir de uma variável. Abaixo, temos duas formas que trazem resultados iguais:

```javascript
// Atribuir função à variável, sem arrow function
const sum = function sum (a, b) {
    return a + b;
}

// Arrow funcion, sem "function sum"
const arrowSum = (a,b) => {
    return a + b;
}

console.log(sum(5,5));        // = 10
console.log(arrowSum(5,5));   // = 10
```

## Sintaxe simplificada

Quando temos apenas uma linha de código (ou podemos dizer que a arrow funcion não possui corpo, algo comum), podemos simplificar sem a palavra `return` e também sem as chaves, ficando da seguinte forma:

```javascript
const arrowSum = (a,b) => a + b;
const imprimir = () => console.log("Dizer algo");

console.log(arrowSum(5,5));
imprimir();
```

## Contexto de this

Resumidamente, uma arrow function dentro de um objetivo <mark style="color:orange;">não tem o seu próprio this</mark> como seria no caso de uma função normal. Veja exemplos que guardam funções dentro de um objeto:

<figure><img src="../../../.gitbook/assets/arrow function em objeto.png" alt=""><figcaption></figcaption></figure>

O <mark style="color:blue;">contexto global</mark> seria onde ele está sendo executado. Então ele pode ser uma página HTML, um arquivo, uma função se estiver dentro de uma, etc. Portanto, a arrow function dentro de um objeto tem o mesmo resultado que uma função fora de qualquer objeto, como se fosse uma função normal sendo chamada `fun()` no meio do código.

Isso é importante entender, muito mais em React, pois utiliza-se muito o this em classes de componentes. Isso será visto na página de [React](../react/).
