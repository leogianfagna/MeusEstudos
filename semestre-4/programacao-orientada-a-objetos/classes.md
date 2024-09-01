# Classes

## Uso de classes para instâncias

Todo programa possui uma <mark style="color:blue;">classe executável</mark>, que por padrão <mark style="color:orange;">possui apenas um método</mark> nela chamada main(). Portanto, vemos qual é a classe executável do projeto através da presença desse método, dessa forma:

```java
public class Main
{
    public static void main(String[] args) {
        // ... Linha de racicínio
    }
}
```

Já as outras classes, servirão de moldes/formar para fazer instâncias (elas não são programadas uma a uma e sim formadas por essa classe). Portanto, quando usamos `new Porta = ...` simboliza que a instância Porta veio do molde de uma classe e que vai ter as características previstas nesta classe.

### Criação de classes de forma segura

Dentro da classe, a definição de atributos seguem depois dos conceitos de <mark style="color:purple;">`private/public`</mark> que controlam se ela poderá ser usada também fora daquela classe. Um atributo sendo público vai implicar que ele poderá ser manipulado de qualquer forma fora daquela classe, o que não é seguro caso o atributo seja uma variável. Caso esse atributo seja uma constante, está tudo bem usar public.

A criação de atributos com variáveis que são privates deverão ter implementadas métodos dentro dela para acessar ou manipular de forma segura as mesmas. Por exemplo, criar métodos `getDia()` ou `setDia()` para manipular o atributo de forma segura, pois esses métodos teriam condições para checar o valor inserido. Caso seja inválido, usamos algo chamado <mark style="color:red;">exception</mark> que vai pedir para redigitar ou parar o programa.

Por fim, o uso de construtores servirão para previnir lixo na memória e não criar atributos com valores vazios, pois ele trabalha para iniciar os atributos de forma automatica na hora de criar o objeto já que ele é um método e exige que forneça os parâmetros. Toda vez que usamos a palavra `New`, estamos criando um novo espaço na memória. Veja todas essas explicações acima na prática:

```java
Data ontem;
ontem = New Data(9,8,2024); // Construtor

ontem.dia = 5; // Erro: nunca mexer diretamente
ontem.setDia(5); // OK
```

> Um objeto zerado significa `null`, o que seria a mesma coisa que apontar para nada.

Por isso, quando trabalhamos com extra classes não veremos uma variável recebendo um valor e sempre métodos, por exemplo:

```java
newMeta.setDisplayName(oldMeta.getDisplayName());
newMeta.setLore(oldMeta.getLore());
```

Construtores possuem o mesmo nome da classe e é `void`, porém não escrevemos void nele, dessa forma:

```java
public /* void */ Data(...)
```

### Membro estático

Esses membros são úteis para implementar funcionalidades globais ou compartilhar estados comuns entre a classe <mark style="color:green;">sem a necessidade de instâncias</mark>. Em Java, membros estáticos são atributos ou métodos pertencentes à classe e que podem ser <mark style="color:blue;">compartilhadas e usadas globalmente dentro dela</mark>.

Os atributos estáticos servem para representar informações compartilhada para toda a classe e os métodos estáticos para implementar funcionalidades que não dependem de nenhuma outra coisa (métodos estáticos não operam em instâncias). Por isso, podem ser chamados diretamente pelo nome da classe, sem a necessidade de instâncias.

#### Exemplo variável estática

Criou a variável estática contador, cujo método `exemplo()` aumenta seu valor toda vez que chamada. Usa esse método duas vezes na classe executável, portanto, sobe o valor de contador duas vezes e ela pode ser imprimida normalmente com saída igual a `2` no final:

```java
public class Exemplo {
    static int contador = 0;

    public Exemplo() {
        contador++;
    }
}

public class Main {
    public static void main(String[] args) {
        Exemplo obj1 = new Exemplo();
        Exemplo obj2 = new Exemplo();
        System.out.println(Exemplo.contador);
    }
}
```

#### Exemplo método estático

Cria-se um método estático chamado `somar()` que vai ser utilizado depois na classe executável:

```java
public class Utilidade {
    public static int somar(int a, int b) {
        return a + b;
    }
}

public class Main {
    public static void main(String[] args) {
        int resultado = Utilidade.somar(3, 5);
        System.out.println(resultado);
    }
}
```

## Palavra THIS

Quando estamos dentro de uma classe, podemos ter as variáveis que são criadas dentro dela e os parâmetros recebidos dentro de uma função. Toda vez que iremos nos referir aos atributos da classe, precisamos usar a palavra this. Podemos sempre pensar que, quando ela aparece, "**estamos falando de mim mesmo**".

```java
public class Data {
    
    private byte dia, mes;
    private short mes;

    public Data(byte dia, byte mes, short ano) throw Exception {  
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }
    
    // ... Mais código
}
```

Esse código é o construtor da classe Data, que tem como objetivo atribuir os valores recebidos no parâmetro às variáveis da classe. As variáveis da classe são destacadas como `this.dia`, enquanto apenas `dia` é a variável/parâmetro.

### Exemplo mais complexo

```java
// Classe Main
public class AuseventosPlugin extends JavaPlugin {

    @Override
    public void onEnable() {
        DatabaseManager databaseManager = new DatabaseManager(this);
    }
    
    databaseManager.openConnection();
    // ...
}



// Outra classe: DatabaseManager
public class DatabaseManager {

    private JavaPlugin plugin;

    public DatabaseManager(JavaPlugin plugin) {
        this.plugin = plugin;
    }
    
    File dataFolder = plugin.getDataFolder();
    // ...
}
```

A classe Main cria uma nova instância da classe chamada DatabaseManager e passa a palavra this como parâmetro no construtor. Vamos lembrar do conceito: a classe é um molde para a criação da instância, então na linha da criação da nova instância, essa classe está fornecendo o kit completo para criar ela e podemos utilizar ao longo do código.

Quando usamos o this no parâmetro do construtor, estamos passando a própria instância da classe main, isso porque a classe DatabaseManager vai precisar de métodos e informações da classe main para funcionar, como por exemplo, o método getDataFolder().

Se a classe DatabaseManager não precisasse de nenhum método da classe Main, a criação desta instância não seria necessária. Portanto, isso só ocorreu pois na classe main tem métodos importantes que precisam ser utilizados em outras classes (que no caso deste código, eles não foram criados por lá, e sim herdam de JavaPlugin, visto na primeira linha).

#### Por que não extender JavaPlugin na classe DatabaseManager?

Pois não é uma prática recomendada por conta do conceito de responsabilidade onde cada classe deve ter apenas uma função clara e específica. A classe Main é responsável por isso enquanto as outras classes tem as suas próprias responsabilidades que é auxiliar a classe main e não se preocupar com o ciclo de vida do plugin.

#### E se necessário mais parâmetros?

Se o construtor da outra classe precisar de mais parâmetros para receber, basta adicioná-los normalmente. O `this` **não passa automaticamente outras variáveis** e sim a referência à instância do objeto, não as variáveis locais. Portanto, para isso:

```java
public void onEnable() {
    databaseName = "custom_database_name.db";
    DatabaseManager databaseManager = new DatabaseManager(this, databaseName);
}
```

## Classe object

É uma classe onde todas as classes criadas em um projeto Java herdam, diretamente ou indiretamente. Uma classe só pode herdar de uma:

<figure><img src="../../.gitbook/assets/image.png" alt=""><figcaption></figcaption></figure>

Esta classe possui vários métodos, mas existem 3 específicos que não funcionam corretamente na classe herdade, portanto, precisam ser re-implementados na própria classe criada. Um método implementado novamente precisa receber a notação `@Override`. São eles:

* toString()
* equals()
* hashCode()

#### toString()

O uso deste método é <mark style="color:orange;">padronizado</mark> em Java. Quando printamos alguma coisa na tela, o interpretador rodaria isso como se fosse a chamada de função toString sem mesmo a necessidade de chamá-la, por exemplo:

```java
System.out.println(algumaVariavel) -> toString(algumaVariavel)
```

Por conta disso, é muito importante a reimplementar este método pois assim todo print estaria comprometido se não funcionar corretamente. E lembrando que, depois de implementar este método, os prints utilizarão ele automaticamente.

Como estamos fazendo um método do zero e ainda utilizando as mesmas variáveis disponíveis na classe, podemos criá-lo para printar algo do jeito que queremos. Por exemplo, um toString() em uma classe que mostra datas pode ser implementado retornando uma data formatada. Para implementá-lo novamente, podemos fazer algo desta forma:

```java
@Override
public String toString() {
    return this.dia + "/" + this.mes + "/" + this.ano;
}

// Exemplo mais complexo usando operador ternário ([condição] ? [se sim] : [se não])
@Override
public String toString() {
    return (this.dia < 10 ? "0" : "") + this.dia + "/" +
           (this.mes < 10 ? "0" : "") + this.mes + "/" +
           (this.ano < 0 ? (-this.ano + "ac") : this.ano);
}
```

