# Data

## Conseguir a data atual

Vamos definir a data atual com o método date e depois definir como queremos o formato. Esse formato pode ser alterado baseado na nossa vontade. O retorno precisa incluir a data sendo chamada pelo método <mark style="color:purple;">`format()`</mark> para funcionar.

```kotlin
// import java.util.Calendar

val dataAtual = Calendar.getInstance()
val formato = SimpleDateFormat("dd/MM/yyyy - HH:mm", Locale.getDefault())
return formato.format(dataAtual.time)
```

Já usando isso, podemos adicionar  um tempo nessa data, por exemplo, acrescentar mais minutos, horas, etc:

```kotlin
val dataAtual = Calendar.getInstance()

// Adicionar mais tempo: MINUTE, HOUR_OF_DAY, DAY_OF_YEAR.. Se auto completa
dataAtual.add(Calendar.MINUTE, 5)

// Mesma lógica
val formato = SimpleDateFormat("dd/MM/yyyy - HH:mm", Locale.getDefault())
val i = formato.format(dataAtual.time)
```
