# Deixar apenas números

Em uma função em que no site retorna as variáveis são compostas pelos caracteres **R$**, podemos usar a seguinte função para remover todos os possíveis caracteres e deixando apenas valores:

```javascript
function removeCurrencyFormat(value) {
    return parseFloat(value.replace(/[^\d,]/g, '').replace(',', '.'));
}
```

Nesse caso, também trocamos a vírgula por um ponto, pois apenas assim será considerado um float. No caso desse site, usava vírgulas para separar as casas decimais.
