# Técnicas Clean Code

Javascript pode ser muito difícil de ler as vezes, isso por conta de técnicas de deixar o código mais limpo. Veja alguns exemplos em ocorrências básicas que acontecem e que podem ser substituídas por outros métodos.

## Valores diferentes em IF/ELSE

Se temos um IF/ELSE simples em que, atribui a variável um valor em um caso e outro valor em outro, podemos substituir por um [operador ternário](https://developer.mozilla.org/pt-BR/docs/Web/JavaScript/Reference/Operators/Conditional\_operator). Um operador ternário não necessariamente estará entre <mark style="color:orange;">parênteses</mark>.

```javascript
if (kartodromoSelecionado === 'all') {
    kartFilter = null;
} else {
    kartFilter = kartodromoSelecionado;
}
```

```javascript
kartFilter = kartodromoSelecionado === 'all' ? null : kartodromoSelecionado;
```

## Omissão do método GET

Em fetch, o método GET é o padrão utilizado. Portanto é possível omití-lo deixando mais limpo ainda o código.

```javascript
try {
    const r = await fetch(`http://localhost:3000/kartTracks`, { method: "GET" });
    return await r.json();
}
```

```javascript
try {
    const r = await fetch(`http://localhost:3000/kartTracks`);
    return await r.json();
}
```

## Iteração com reduce

A função [reduce](https://www.w3schools.com/jsref/jsref\_reduce.asp) é usada para iterar sobre todos os elementos do array `classificacoes` e acumular um valor. No primeiro exemplo, estamos usando forEach, sendo que o reduce também poderia fazer o mesmo trabalho.

Com forEach tinhamos que iniciar a variável e além disso contabilizar com i para fazer a média. Com reduce, é possível fazer tudo em uma única linha.

```javascript
const classificacoes = await queryClassificacoes();
let mediaTempoTotal = 0;

classificacoes.forEach((classificacao) => {
    i++;
    mediaTempoTotal += classificacao.tempo.totalEmMs;
});

mediaTempoTotal = mediaTempoTotal / i;
```

```javascript
const classificacoes = await queryClassificacoes();
const mediaTempoTotal = classificacoes.reduce((sum, classificacao) =>
    sum + classificacao.tempo.totalEmMs, 0) / classificacoes.length;
```

## Find para encontrar facilmente

Vamos supor que temos um array de resultados e precisamos encontrar um específco que condizemos com as nossas condições. Podemos usar o mesmo forEach acima para percorrer cada um e abrir um if se encontrado.&#x20;

A função [find ](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global\_Objects/Array/find)busca o **primeiro elemento** do array (no caso "classificacoes") que atenda a uma condição específica. Se encontrado, retorna esse elemento; se não encontrado, retorna `undefined`.

```javascript
const classificacoes = await queryClassificacoes();
let tempoPiloto;

classificacoes.forEach((classificacao) => {
    if (classificacao.nome === document.getElementById('pilot-name').value) {
        tempoPiloto = classificacao.tempo;
    }
});
```

```javascript
const classificacoes = await queryClassificacoes();
const tempoPiloto = classificacoes.find(classificacao =>
    classificacao.nome === document.getElementById('pilot-name').value)?.tempo;
```

## Diversas condições com Operador de coalescência nula

Parecido com o primeiro exemplo mas com várias condições. Em vez de ficar abrindo diversos if/else podemos criar um object. Em caso do valor não ser encontrado (que seria entrar no else), podemos usar o operador de coalescência nula, que tem como intuíto setar um valor caso à esquerda for nulo ou undefinied.

```javascript
function setScore(score) {
    var degrees;
    if (score == 0) {
        degrees = 0;
    } else if (score == 1) {
        degrees = 36;
    } else if (score >= 2) {
        degrees = 72;
    } else if (score == -1) {
        degrees = -36;
    } else if (score <= -2) {
        degrees = -72;
    } else {
        alert("Invalid Score");
    }
    setSpeedometerValue(degrees);
}
```

```javascript
function setScore(score) {
    const degreeMap = { "-2": -72, "-1": -36, "0": 0, "1": 36, "2": 72 };
    setSpeedometerValue(degreeMap[score] ?? 0);
}
```
