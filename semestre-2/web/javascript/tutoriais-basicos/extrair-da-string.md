# Extrair da String

Quando temos alguma string e queremos apenas uma parte dela. Por exemplo, tenho um item que possui o nome de uma pessoa em um texto e eu quero <mark style="color:blue;">apenas o nome</mark> da pessoa.

## Método split()

Esse método é melhor em string onde queremos cortar a partir de um ponto e não sabemos o que pode ter no restante da string.

<figure><img src="../../../../.gitbook/assets/resultados placeholders.png" alt=""><figcaption></figcaption></figure>

```javascript
var atual = "De » Marcos";
var partes = atual.split("» "); // Vai cortar a partir disso
var nova = partes[1];

console.log(nova); // Marcos
```

## Método replace()

```javascript
var atual = "De » Marcos";
var nova = atual.replace("De » ", ""); // Troca todo o restante

console.log(nova); // Marcos
```
