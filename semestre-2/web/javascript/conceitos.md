# Conceitos

## Variáveis

As variáveis `let` e `const` tem funcionalidades diferentes de `var` por não manchar o escopo global. Manchar o escopo significa perder o valor de uma variável global dentro de uma função, que pode acontecer se usarmos `var`.

<figure><img src="../../../.gitbook/assets/variaveis var e let escopo global.png" alt=""><figcaption></figcaption></figure>

Isso quer dizer que `let` e `const` respeitam o <mark style="color:purple;">escopo de bloco</mark>, ou seja, declarado entre chaves, significa que eles valem apenas dentro daquelas chaves.

### Notação de pontos (dot notation)

O ponto é um operador muito importante para acessar um membro de um objeto. Esse membro pode ser propriedades ou métodos.

<figure><img src="../../../.gitbook/assets/javascript dot notation.png" alt=""><figcaption></figcaption></figure>

Neste caso, “console” é o objeto global da linguagem JavaScript que oferece um conjunto de métodos para interagir com o ambiente de execução, como por exemplo, o “log”. Outro exemplo:

<figure><img src="../../../.gitbook/assets/javascript associar propriedades.png" alt=""><figcaption></figcaption></figure>

## Spread Operator

Usado com arrays e objetos, serve para constituir novos valores com base em outros existentes, em outras palavras, unir arrays ou objetos.

#### Exemplos com array

```javascript
const a1 = [1,2,3]
const a2 = [4,5,6]

// Exemplos de Spread Operator
const a3 = [...a1, ...a2]
const a4 = [0, ...a1, 4]
```

#### Exemplos com objetos

```javascript
const carInfo = {
    nome: "Yaris",
    marca: "Toyota",
    ano: 2019
};

const motorInfo = {
    tipo: "flex",
    potencia: 105,
    motor: 1.5
};

const so = {...carInfo, ...motorInfo};
```
