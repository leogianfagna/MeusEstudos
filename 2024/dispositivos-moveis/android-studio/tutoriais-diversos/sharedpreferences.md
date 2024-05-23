---
description: Salvar variáveis localmente no dispositivo.
---

# SharedPreferences

## Salvar dados

Salvamos dados localmente usando o SharedPreferences. Podemos criar uma função dessa forma:

```kotlin
private fun salvarUserNoSharedPreferences(context: Context, userEscaneado: String) {
    val sharedPref: SharedPreferences = context
        .getSharedPreferences("nomeDeUmaColecao", Context.MODE_PRIVATE)
    
    val editor: SharedPreferences.Editor = sharedPref.edit()
    editor.putString("chaveDaColecao", userEscaneado)
    editor.apply()
}
```

* nomeDeUmaColecao: criamos uma coleção onde criaremos dentro dela chave/valores para armazenar
* chaveDaColecao: vai ser a chave em que vamos guardar o dado
* userEscaneado: é uma variável que vamos guardar, pode ser qualquer uma

Podemos chamar essa função dessa forma:

```kotlin
val nomeCliente = "Exemplo"
salvarUserNoSharedPreferences(this, nomeCliente)
```

## Resgatar dados salvos

Podemos também preparar uma função para ficar mais organizado, dessa forma:

```kotlin
private val nomeCliente = obterNomeDoCliente(this)

private fun obterNomeDoCliente(context: Context): String {
    val sharedPref: SharedPreferences = context
        .getSharedPreferences("nomeDeUmaColecao", Context.MODE_PRIVATE)
    
    val nomeEncontrado = sharedPref.getString("chaveDaColecao", null)

    return nomeEncontrado ?: ""
}
```

O nome da coleção e da chave precisa identificar pela guardada. Nesse caso, a função está retornado o nome encontrado ou retornará uma string vazia, usando o operador Elvis.
