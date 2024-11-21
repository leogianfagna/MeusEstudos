# Conversão e revelação

Normalmente, quando colocamos o nome de um tipo entre parênteses na frente, isso quer dizer uma conversão de tipo. Mas isso pode ter diferenças importantes dependendo do contexto.

## Conversão de tipo

```java
float number = 54412.0;
int integerNumber = (int) number;
```

<mark style="color:blue;">**Apenas**</mark> <mark style="color:blue;"></mark><mark style="color:blue;">tipos primitivos</mark> podem ser convertidos para outros tipos primitivos usando o <mark style="color:purple;">casting</mark>. Neste caso, uma variável que era float passa a ser int.

## Revelação de tipo

```java
Data d = (Data) minhaData;
```

O objeto `minhaData` sempre foi do tipo _Data_, mas:

* Ele pode ter sido passado no parâmetro como um Object.
* Ele está <mark style="color:blue;">sendo visto de uma forma diferente</mark> pelo compilador. Frequentemente visto em classes parametrizadas.

Portanto, usar o nome da classe em parênteses revela o objeto minhaData como o tipo que ele já era de fato. Isso <mark style="color:red;">não converte</mark>.
