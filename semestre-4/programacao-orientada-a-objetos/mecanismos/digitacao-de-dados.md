# Digitação de dados

A digitação de dados não é simples, é melhor criar uma nova classe (chamaremos de Teclado) para ajudar nisso, essas classes precisam das importações:

```java
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
```

## Classes auxiliares e seu uso

A classe chamada <mark style="color:purple;">**BufferedReader**</mark> vai ajudar a ler os dados. Ela possui métodos como readLine() e que transforma automaticamente em strings os dados digitados, além de transformar os dados digitados nos tipos que queremos. Portanto para começar, é necessário um <mark style="color:blue;">objeto dessa classe</mark>.

A classe BufferedReader pode ler dados de diversas fontes. A <mark style="color:blue;">fonte lida é o que entra no construtor</mark>, no caso: `new InputStreamReader(System.in)`. **Neste caso**, a fonte simboliza o **teclado**, mas ela poderia ser um arquivo, por exemplo.

Por conta que a fonte é o teclado, sabemos que <mark style="color:green;">não teremos erros</mark> e isso explica o `catch` vazio. Mas, temos a possibilidade de colocar vários catch e, neste código foi usado um catch para `NumberFormatException` pois pode acontecer do usuário digitar um dado equivocado (letras em tipos numéricos, por exemplo). Por isso a conversão está dentro do `try`.

```java
private static BufferedReader teclado = new BufferedReader(
    new InputStreamReader(System.in)
);

public static long getUmLong() throws Exception {
    long ret = 0L;

    try {
        // Usa uma wrapper para receber o método parseLong em cima do que foi
        // digitado, que é capturado com o método readLine() que falamos acima.
        ret = Long.parseLong(teclado.readLine());
    } 
    catch (IOException erro) {}
    catch (NumberFormatException erro) {
        throw new Exception("Long inválido");
    }
    
    return ret;
}
```

Continuando para o boolean, o método parseBoolean não deixa exceções e por isso esse método vai ser construído de forma diferente. Basicamente, **faz validações** antes de tranformar em boolean e guardar. Funciona o mesmo para o char, que também precisa das validações.

```java
public static boolean getUmBoolean() throws Exception {
    boolean ret = false;

    try {
        String str = teclado.readLine();

        // Confere antes de converter se está correto
        if (str == null)
            throw new Exception("Boolean inválido.");
        if (!str.equals("true") && !str.equals("false"))
            throw new Exception("Boolean inválido.");

        ret = Boolean.parseBoolean(str);
    } catch (IOException erro) {}

    return ret;
}

public static char getUmChar() throws Exception {
    char ret = ' ';

    try {
        String str = teclado.readLine();
        
        if (str == null) throw new Exception("Char inválido.");
        if (str.length() != 1) throw new Exception("Char inválido.");

        ret = str.charAt(0); // Não usa parse, pega o primeiro e único char

    } catch (IOException erro) {}

    return ret;
}
```

## Comunicação com a main (lendo dados)

A forma de comunicação dessa nossa classe criada com a main é <mark style="color:blue;">chamando os métodos</mark> da classe. Como são [static](../introducao/atributos-e-metodos-estaticos.md), fazemos dessa forma:

```java
System.out.println("Digite um long: ");
long longRecebido = Teclado.getUmLong();

System.out.println("Digite um byte: ");
byte byteRecebido = Teclado.getUmByte();
```

Como esses métodos retornam exceções, devemos mudar um pouco a lógica colocando eles dentro de `try-catch` para caso o que for digitado seja equivocado. Basicamente, está pronto e basta adaptar o código conforme necessário.

## Variáveis na inicialização

Ao escrever zero para uma variável, o Java assume que é do tipo int, dando erro de compilação ao atribuir a uma variável que não seja int. Para isso, cada uma das funções precisam ser iniciadas com a sua variável usando <mark style="color:purple;">**type cast**</mark> para converter. Toda conversão toma um tempo de processamento.

```java
short ret   = (short)0;
byte ret    = (byte)0;
long ret    = 0L;
double ret  = 0.0;
float ret   = 0.0F;
char ret    = ' ';
boolean ret = false;
```

## Funcionamento do try-catch

Dentro de um try, quando uma linha de execução dá um erro o código pula direto para o catch. As linhas de código que estão antes do erro são executadas. Isso porque o programa é resistente à falhas, independentemente do que digitar, os try-catch estão ali para não deixar o programa "capotar".

Já foi visto antes mas podem existir diferentes tipos de catch, que são referentes a cada tipo de erro que pode acontecer.
