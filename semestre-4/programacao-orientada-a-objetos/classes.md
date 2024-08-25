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
