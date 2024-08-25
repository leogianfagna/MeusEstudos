# Instâncias e objetos

Uma programação orientada à objetos significa que ela está <mark style="color:blue;">orientada à peças</mark>. O conceito de peça é muito importante para entender como é feita essa linguagem de programação. O nome objeto não é um termo muito correto pois objeto não é peça, mas uma instância é. Veja mais abaixo.

## Conceito de peça (instância)

Muitas coisas são construídas através de peças (como um motor) e outras que não possuem peças e sim seu resultado único (como um prato). Quando um prato quebra ele é varrido e jogado fora, mas quando algo que é montado através de peças quebra, é possível arrumar trocando a peça ou montando novamente.

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

A palavra `new` é um <mark style="color:purple;">**malloc**</mark> das outras linguagens, ela aloca um espaço de memória para essa variável.

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

## Criação prática

Em orientação a objetos, toda instância está obrigatoriamente relacionada a uma classe, pois vamos lembrar que a classe vai servir como um molde para ela. Podemos enxergar a instância como uma cópia concreta da classe.

Portanto, criar uma instância em Java significa criar uma nova peça a partir de uma classe (usando `new`). Então, supondo que vamos criar uma instância de um classe chamada "_Contatos_", a utilização da palavra `new` chama automaticamente o <mark style="color:purple;">**construtor**</mark> que está dentro da classe. Esse construtor possui <mark style="color:orange;">o mesmo da classe</mark>, não retorna nada e tem como objetivo garantir que as instâncias nasçam com atributos válidos.

<figure><img src="../../.gitbook/assets/criação de instâncias vistas em classes.png" alt=""><figcaption></figcaption></figure>

O que estamos vendo: uma variável de referencia nomeada como meuCarro cria uma instância da classe Carro por usar a palavra new, alocando memória e chamando o contrutor (seta laranja) de dentro da classe e inicializa com 3 parâmetros. Esta variável chamada meuCarro é do tipo "Carro", o nome da classe. Demonstrativamente:

<figure><img src="../../.gitbook/assets/definição na criação de instâncias em Java.png" alt=""><figcaption></figcaption></figure>
