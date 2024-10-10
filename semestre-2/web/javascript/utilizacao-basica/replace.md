# Replace

Replace é um métdo que podemos usar para substituir algum caractere/ocorrência na string para algo que queremos usando essa sintaxe:

```javascript
let str = "Esta é uma string com espaços";
let newStr = str.replace('uma string', 'um texto');
```

## Substituindo todas as ocorrências

O exemplo acima vai substituir o <mark style="color:orange;">primeiro caso encontrado e apenas</mark>. Agora, vamos supor que queremos substituir todos os espaços por outra coisa, precisamos usar regex. Assim, para substituir tudo encontrado, o exemplo final ficaria assim:

```javascript
// Remover todos os espaços
let str = "Esta é uma string com espaços";
let newStr = str.replace(/ /g, '');
```
