# Switch True

O uso do `switch` em JavaScript é tradicionalmente baseado em valores exatos. No entanto, você pode criar um "switch true" onde cada caso é uma expressão booleana, permitindo que você avalie condições complexas.

```javascript
let valor = 15;

switch (true) {
    case (valor < 10):
        console.log("O valor é menor que 10.");
        break;
    case (valor >= 10 && valor < 20):
        console.log("O valor está entre 10 e 19.");
        break;
    case (valor >= 20 && valor < 30):
        console.log("O valor está entre 20 e 29.");
        break;
    default:
        console.log("O valor é 30 ou maior.");
        break;
}
```

Então podemos criar condições complexas como se fosse dentro de um IF, as quais, caso condizem, vão entrar no caso. Exemplo real no trabalho:

```javascript
var loreItem = "%checkitem_getinfo:mainhand_lorecontains:%";
var tipoLembrancinha;

switch (true) {

    case (loreItem.indexOf("natal") !== -1):
        tipoLembrancinha = "spoilers natal";
        break;
        
    case (loreItem.indexOf("pascoa") !== -1):
        tipoLembrancinha = "spoilers pascoa";
        break;
        
    default:
        break;
}
```
