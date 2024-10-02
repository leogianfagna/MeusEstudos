# Expressões regulares

Também podemos chamar de regex, servem para especificar se um dado está certo ou não. Eles ajudam a fazer <mark style="color:blue;">validações sofisticadas</mark>. Começamos com `^` e terminamos com `$`.

```regex
^...$
```

## Classe em Java para usar

Existe um compilador de expressões regulares chamado `Pattern.compile`. Ele é um método estático então não há necessidade de instanciar. Portanto, para usar um regex precisamos declará-lo e depois compilar usando aquela classe que <mark style="color:blue;">retorna um objeto da classe Pattern</mark> e assim guardamos em alguma variável.

Veja um exemplo em que guardamos na variável chamada padraoNome:

```java
private static final String regExNome = "^...$";
private static final Pattern padraoNome = Pattern.compile(Agenda.regExNome);
private String nomeInserido = "Clodoaldo";

if (!Agenda.padraoNome.matcher(nomeInserido).matches()) {
    throw new Exception("Inválido");
}
```

#### Resumo do exemplo:

* Regex definido na variável **regExNome**.
* **padraoNome** vai receber o regex compilado, através do método `Pattern.compile`.
* Método `matcher()` recebe como parâmetro o nome inserido, que vai comparar com a regex compilada em **padraoNome**.
* Método `matches()` confere se o nomeInserido está de acordo com o regex criado retornando verdadeiro ou falso.
