# Programação orientada à objetos

Uma programação orientada à objetos significa que ela está <mark style="color:blue;">orientada à peças</mark>. O conceito de peça é muito importante para entender como é feita essa linguagem de programação. O nome objeto não é um termo muito correto pois objeto não é peça, mas uma instância é. Veja mais abaixo.

## Conceito de peça (instância)

Muitas coisas são construídas com através de peças (como um motor) e outras que não possuem peças e sim seu resultado único (como um prato). Quando um prato quebra ele é varrido e jogado fora, mas quando algo que é montado através de peças quebra, é possível arrumar trocando a peça ou montando novamente.

A ideia de criação de novas peças tem que ser muito atentada com:

* Limites: até onde vai algo? Imagine um farol onde a lâmpada é grudada e não pode ser tirada, ao quebrar, precisaria trocar todo o farol
* Misturar coisas que deveriam ser separadas
* Encaixamento: tecnicamente falando, uma instância chamada "aluno" deverá ser chamada assim sempre e não poderá ser chamada como "estudante" por exemplo. Uma função do tipo `void` não pode ser atribuída a uma variável. Se não encaixar, não será compilado.
* Padrão: como as tomadas, todas tem um mesmo padrão para não dar problemas

Cada peça possui um, exclusivamente um propósito. Se em uma explicação do que essa peça faz for utilizado a palavra "e", significa que ela está ruim. A mesma coisa com funções, devem ter apenas um propósito cada uma.

Assim, podemos classificar que Java é uma programação orientada à instâncias onde podemos similar instâncias com essas peças. Elas (as instâncias) possuem esse exato mesmo comportamento das peças.

## O que são instâncias

Instâncias podem ser vistas como um <mark style="color:blue;">kit formado por vários dados e depois algoritmos que processam esses dados</mark> presentes. Por exemplo, uma instância de aluno com vários dados e seguidos temos métodos que mudam esses dados, executam algoritmos, etc. Basicamente, fazem coisas com a peça.

* Dados: chamamos de atributos (variáveis ou constantes)
* Algoritmos: chamamos de métodos (funções ou procedimentos)

Algoritmos que retornam algo são chamados de funções e aqueles que não retornam, do tipo `void`, são chamados de procedimentos. Ficaremos atento pois sempre é chamado também de função, mas ainda sim não é o correto.

## O que são objetos

Nada mais nada menos que é o <mark style="color:blue;">nome que podemos dar para uma instância</mark>. Cada instância pode ter nome, mas não obrigatoriamente. Uma instância sem um nome significa que ela será utilizada uma vez no seu ciclo de execução e nunca mais, já uma instância renomeada será <mark style="color:orange;">reutilizada</mark>.

Falando em reutilizar, a <mark style="color:blue;">reusabilidade em orientação a objetos vale mais que a eficiência</mark>. Levaremos em consideração que é válido sacrificar a eficiência por um bom reuso. Lembrar do exemplo de ter métodos que não utilizamos no código mas poderão ser utilizados em um futuro ou por outra pessoa, não que a eficiência não deve ser levada em consideração!

### Duas instâncias

Neste exemplo usaremos duas instâncias novas (new), sem repetição dela:

```java
System.out.println(new Data(5,8,2024).getMes()); // Uma instância
System.out.println(new Data(5,8,2024).getDia()); // Segunda instância
```

### Instância renomeada

Atribuindo um nome para a instância, podemos usar ela mesma novamente:

```java
Data hoje;
hoje = new Data(5,8,2024);

System.out.println(hoje.getMes()); // Uma instância
System.out.println(hoje.getDia()); // A mesma instância
```

Vendo esses exemplos acima, podemos perceber que o objeto é apenas o nome, o que de fato não importa, o <mark style="color:blue;">importante é o conteúdo dele</mark>. Assim, em termos mais técnicos, o <mark style="color:green;">objeto é um ponteiro</mark> pois ele aponta a algo que tem um conteúdo. O nome dado pode até ter mais de um, usando um exemplo real: uma pessoa chamada Roberto também pode ser chamada de Beto, o que vale é a pessoa em si.

```java
Data amanha;
System.out.println(amanha.getMes()); // Erro
```

Esse exemplo mostra muito como o objeto funciona. Aqui, esse objeto não faz referência a nenhuma instância e possui apenas só um nome. É a mesma coisa que pedir para "Alfredo" fechar a porta, sendo que não tem ninguém com esse nome.

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

...
