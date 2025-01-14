# Destructuring

Recurso utilizado em arrays e objetos com o objetivo de transformar cada um dos elementos em uma variável independente.

## Exemplo com array

Podemos escolher o nome das variáveis deixando em colchetes, como fizemos com `p1`, `p2` e `p3`. Poderia ser qualquer outro nome.

<figure><img src="../../../.gitbook/assets/destructuring com array.png" alt=""><figcaption></figcaption></figure>

## Exemplo com objeto

Fazendo exatamente com o nome do elemento do objeto, vai fazer com que o nome da variável o mesmo nome do elemento. Veja abaixo que o nome do elemento é "nivel", assim como o nome da variável criada.

<figure><img src="../../../.gitbook/assets/destructuring com objeto.png" alt=""><figcaption></figcaption></figure>

Neste caso, podemos escolher um outro nome (opcional), desta forma:

```javascript
const obj = {
    nome: "Rudoulf",
    classe: "Mago",
    nivel: 50
};

const { nome , classe, nivel: nivelMaximoAtingido } = obj;
console.log(`O nível máximo é de ${nivelMaximoAtingido}`); // 50
```

Aqui renomeamos apenas `nivel` para `nivelMaximoAtingido`, poderíamos fazer com todas também.
