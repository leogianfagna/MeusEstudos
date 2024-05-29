# String contém

## Usando Includes

Vai entrar na condição se <mark style="color:purple;">`includes()`</mark> for **verdadeiro**.

```javascript
// Convertendo ambas as strings para minúsculas
let textoMinusculo = texto.toLowerCase();
let palavraMinusculo = palavra.toLowerCase();

if (textoMinusculo.includes(palavraMinusculo)) {
    console.log(`A palavra "${palavra}" foi encontrada na string.`);
} else {
    console.log(`A palavra "${palavra}" não foi encontrada na string.`);
}
```

## Usando IndexOf

Vai entrar na condição se <mark style="color:purple;">`indexOf()`</mark> retornar algo diferente de **-1**. Algumas plataformas podem não sustentar o Includes, como é a que eu trabalho. Assim:

```javascript
var loreItem = "%checkitem_getinfo:mainhand_lorecontains:%";
var textoMinusculo = loreItem.toLowerCase(); // Se necessário

if (loreItem.indexOf("palavraProcurada") !== -1) {
    // Encontrou
}
```
