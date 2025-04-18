# Métodos arrays

Métodos de arrays podem ser chamados através dele mesmo, então `nomeArray.metodo()`. Existe uma [documentação para todos os métodos](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/at). Mostrada abaixo os métodos mais importantes para o uso de React.

O método utiliza uma <mark style="color:blue;">função lambda iterando todo o array e cada elemento iterado é recebido como um parâmetro desta função</mark>. Ao receber ele com parâmetros, podemos manipular a função da forma que queremos.

## Usar para objetos

Métodos array não podem ser chamados diretamente em objetos. Contudo, o que é <mark style="color:green;">comum</mark> ser feito no formato de um [array de objetos](#user-content-fn-1)[^1]. Portanto, por ser um array, esses métodos servem para ele.

```javascript
const array = [
  { id: 2, item: "Reservatório" },
  { id: 5, item: "Válcula" },
  { id: 7, item: "Poço" },
  { id: 8, item: "Parafuso" },
  { id: 11, item: "Engrenagem" },
  { id: 14, item: "Escape" }
];
```

#### O que muda na prática

Basicamente nada. A diferença é que o parâmetro recebido na função lambda agora é um objeto e não uma variável simples e então podemos acessar seus atributos.

<figure><img src="../../../.gitbook/assets/metodos array para objetos.png" alt=""><figcaption></figcaption></figure>

## Filter

Serve para filtrar um array existente baseado em uma condição booleana, que resulta em um novo array.

De forma mais profunda, o método funciona iterando cada elemento desse array, recebendo uma cópia desse elemento no parâmetro de uma função. Por isso, leva como base as [arrows functions](arrow-function.md). Ele funciona **criando um novo array com os valores de cada iteração se foi retornado `true`**.

```javascript
const numeros = [ 1, 2, 3, 4, 5, 6, 7 ]

// A variável "numerosAltos" será o novo array após o filtro
// Ela recebe o array "numeros" aplicando o método filter()
const numerosAltos = numeros.filter((num) => {
    if (num > 3) return true; // Inclui pois retornou true
})

console.log(numerosAltos); // Output: [ 4, 5, 6, 7 ]
```

### Simplificações

Recordando o que foi visto em [arrow functions](arrow-function.md) que, caso não tenha corpo, a função vai retornar o que tiver naquela única linha. Então, basta retornar `true` para incluir aquele elemento no novo array. Portanto, podemos substituir o exemplo acima para uma linha somente:

```javascript
const maioresNumeros = numeros.filter((num) => num > 3 );
```

#### Exemplo usando object

O uso de user.status como corpo inteiro da função pode ser feito por conta de como o Javascript lida com expressões booleanas. Isso é explicado em [truthy e falsy values](truthy-e-falsy-values.md).

```javascript
const usuarios = [
    {nome: "Leonardo", status: true},
    {nome: "Matheus", status: false},
    {nome: "Lucas", status: true}
];

// Maneira 1: Com corpo
const usuariosDisponiveis = usuarios.filter((user) => {
    if (user.status === true) {
        return user;
    }
})

// Maneira 2: Simplificada
const usuariosDisponiveis = usuarios.filter((user) => user.status )
```

## Map ou forEach

Ambos os métodos servem para modificar um array, o que muda é se queremos que ele esteja salvo em um novo array ou modifique o array original.

* Use `forEach` para modificar diretamente o array original.
* Use `map` para criar um novo array transformado.

### Map

É necessário retornar o elemento em cada iteração para compor o novo array. Então primeiro, modifique o elemento e depois retorne-o, desta forma:

```javascript
const itens = [
    { nome: "Shorts", valor: 50, categoria: "Roupas" },
    { nome: "Carderno", valor: 14, categoria: "Papelaria" },
    { nome: "Lápis", valor: 2, categoria: "Papelaria" },
    { nome: "Camiseta", valor: 35, categoria: "Roupas" },
];

// Dividir o valor de todos os itens pela metade
const novoMap = itens.map((item) => {
    item.valor *= 0.5;  // Modificação do valor
    return item;        // Retorno do objeto para compor "novoMap"
});
```

### ForEach

Nenhum retorno é necessário aqui e apenas linhas de código que se referem às alterações do que desejado:

```javascript
const itens = [
    { nome: "Shorts", valor: 50, categoria: "Roupas" },
    { nome: "Carderno", valor: 14, categoria: "Papelaria" },
    { nome: "Lápis", valor: 2, categoria: "Papelaria" },
    { nome: "Camiseta", valor: 35, categoria: "Roupas" },
];

// Adicionar um novo item ao objeto chamado onSale se ele for da categoria "Roupas"
itens.forEach((item) => {
    if (item.categoria === "Roupas") {
        item.onSale = true;
    }
});
```

[^1]: Observamos que é um array de uma única posição `[0]`, que dentro dele temos vários objetos.
