# Classes

> Todas as classes herdam de [Object](classe-object/).

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

## Criação de um construtor

Construtores possuem o mesmo nome da classe e é `void`, porém não escrevemos void nele, dessa forma:

```java
public /* void */ Data(...)
```

O construtor vai instanciar as variáveis da classe baseado no que foi recebido no parâmetro, mas e se esses parâmetros forem algo equivocado e não servidor, por exemplo, int minutos vale 80? Por conta disso, os dados <mark style="color:orange;">precisam ser validados</mark> antes de atribuir, <mark style="color:orange;">retornando uma exceção</mark> (`Exception`) caso tenha algum erro. Existem várias maneiras de fazer isso.

#### Maneira 1: usar um método estático isValido

Talvez no nosso código precisamos chamar inúmeras vezes o método isValido, por exemplo em cada setter ou em várias funções, pois é necessário verificar se após uma mudança, a instância continua válida, por exemplo horário.

Se o horário for 23:20:14 e mudar as horas para 40 (ficando 40:20:14), isso ficaria muito equivocado, então pode ter esse método para validar sempre. Se esse método existir, podemos usá-lo para validar os parâmetros recebidos antes, desta forma:

```java
public Horario(int horas, int minutos, int segundos) throws Exception {
    if (!Horario.isValido(horas, minutos, segundos))
        throw new Exception("Horário inválido");

    this.horas = horas;
    this.minutos = minutos;
    this.segundos = segundos;
}

//isValido() apenas verifica se hora < 0 || hora > 23 etc...
```

#### Maneira 2: usar os setters

Se a nossa classe possui setters, por exemplo setHorario, setMinutos e setSegundos, esses setters precisam validar o valor chegado, certo? Um setter não pode simplesmente atribuir ao this qualquer valor recebido no parâmetro e ele precisa validar.

Por conta disso, podemos usar os setters para atribuir ao this, já que cada setter vai fazer a validação e vai retornar uma exceção se estiver equivocada.

```java
public Horario(int horas, int minutos, int segundos) throws Exception {
    this.setHora(horas);
    this.setMinutos(minutos);
    this.setSegundos(segundos);
}
```

#### Maneira 3: validação bruta

Se não tivermos os setters e nem uma função isValido, podemos validar de forma bruta no próprio construtor variável por variável. Isso também vai funcionar, mas fazer isso apenas se nenhuma das alternativas acima existirem.

```java
public Horario(int horas, int minutos, int segundos) throws Exception {
    if (horas < 0 || horas > 23) throw new Exception("Horas inválidas");
    if (minutos < 0 || minutos > 59) throw new Exception("Minutos inválidos");
    if (segundos < 0 || segundos > 59) throw new Exception("Segundos inválidos");

    this.horas = horas;
    this.minutos = minutos;
    this.segundos = segundos;
}
```

#### Maneira 4: sem validação

Neste caso não, mas supondo uma classe de ângulos onde é aceito qualquer valor, seja negativo ou positivo, do menos infinito ao mais infinito. Este caso não precisa de validação nenhuma e podemos apenas atribuir sem nenhum medo.

```java
public Horario(int horas, int minutos, int segundos) throws Exception {
    this.horas = horas;
    this.minutos = minutos;
    this.segundos = segundos;
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
