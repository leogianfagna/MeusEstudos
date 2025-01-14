# Truthy e Falsy values

Um valor é considerado **truthy** se ele é avaliado como verdadeiro em um contexto booleano, como em uma condição e é considerado **falsy** se ele é avaliado como falso em um contexto booleano.

Os valores **falsy** em JavaScript são:

* `false`
* `0`
* `""` (string vazia)
* `null`
* `undefined`
* `NaN`

Qualquer outro valor, como `true`, números diferentes de `0`, strings não vazias, objetos e arrays, são **truthy**.

## Exemplo com object

```javascript
const usuarios = [
    {nome: "Leonardo", status: true},
    {nome: "Matheus", status: false},
    {nome: "Lucas", status: true}
];

if (user.status) {
    ...
}

if (user.status === true) {
    ...
}
```

1. **`user.status`** é avaliado diretamente:
   * Se `user.status` for `true`, a expressão será **truthy**, e o filtro incluirá o item.
   * Se `user.status` for `false`, a expressão será **falsy**, e o filtro o ignorará.
2. **`user.status === true`** verifica explicitamente se o valor é exatamente igual a `true` (um booleano). Isso não só avalia a "verdade" do valor, mas também garante que ele seja do tipo booleano.

Ambas as versões funcionam porque:

* No caso de `user.status`, o valor é tratado como truthy/falsy automaticamente.
* No caso de `user.status === true`, você está explicitamente verificando o valor booleano.
