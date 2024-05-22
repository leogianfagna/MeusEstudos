# Iniciar activity com parâmetros

No caso, estamos em uma activity e queremos navegar para outra passando alguns parâmetros, possivelmente parâmetros que foram obtidos na activity atual. Para isso, temos que usar um <mark style="color:blue;">**Intent**</mark>. Vamos supor que estamos na activity A e vamos navegar para a activity B passando um inteiro 10 como parâmetro.

#### Activity A

```kotlin
val iniciarActivity = Intent(this, BActivity::class.java)
iniciarActivity.putExtra("vendas", "10");
startActivity(iniciarActivity);
```

#### Activity B

```kotlin
val numCliente = intent.getStringExtra("vendas")!!.toInt()
```

Está feito, na activity B a variável numCliente vai assumir o valor 10. O operador `!!` simboliza que esse valor nunca poderá ser nulo, assim, elimina a necessidade de precisar criar condições para verificar isso.

O método `putExtra()` pode ser usado várias vezes e assim, é só ir resgatando pela activity B.
