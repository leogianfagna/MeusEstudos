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

Quando temos apenas uma linha de código, que é algo comum em arrow functions, podemos simplificar sem a palavra `return` e também sem as chaves, ficando da seguinte forma:

```javascript
const arrowSum = (a,b) => a + b;
const imprimir = () => console.log("Dizer algo");

console.log(arrowSum(5,5));
imprimir();
```

## Contexto de this

