# Programação orientada à objetos

Aprendizado da linguagem Java e técnicas de qualquer outra linguagem orientada a objetos.

## Sumário

* [Regras de nomenclatura](regras-de-nomenclatura.md): como nomear classes, variáveis, métodos, etc.
* [Instâncias e objetos](instancias-e-objetos.md): explicação inicial de como entender o conceito de peça.
  * [Entendendo instâncias](instancias-e-objetos.md#o-que-sao-instancias)
  * [Entendendo objetos como um ponteiro](instancias-e-objetos.md#o-que-sao-objetos)
  * [Criação prática de uma instância](instancias-e-objetos.md#criacao-pratica)
  * [Primeiro contato com instância chamante](instancias-e-objetos.md#instancia-chamante)
* [Classes:](classes/) conceito de ser um molde para instâncias
  * [A classe executável](classes/#uso-de-classes-para-instancias)
  * [Criação de classes seguras](classes/#criacao-de-classes-de-forma-segura)
    * Uso de qualificadores private/public
    * Métodos getters e setters
    * Objetivo do construtor
  * [Primeiro contato com membros estáticos](classes/#membro-estatico)
  * [Classe object:](classes/#classe-object) a classe onde todas herdam e precisa de re-implementações.
    * [toString](classes/tostring.md)
    * [equals](classes/equals.md)
    * [hashCode](classes/hashcode.md)
    * [compareTo](classes/compareto.md)
      * Carteirinha Comparable
    * clone
* [Classes Wrapper:](classes-wrapper.md) conceito de embrulhar um tipo primitivo e disponibilizar métodos.
  * Comodidade na automatização de objetos
  * Conceito de boxed e unboxed
* [Classes parametrizadas:](classes-parametrizadas.md) direcionar o modo de funcionamento.
  * Classes genéricas
  * [Conjuntos homogêneos e heterogêneos](classes-parametrizadas.md#conjuntos-heterogenios)
* [Instância oca:](instancia-oca.md) criar instância de classes com apenas atributos estáticos
* [Atributos e métodos estáticos:](atributos-e-metodos-estaticos.md) qualificador static
  * Entende o significa encapsulamento
  * [Objeto chamante](atributos-e-metodos-estaticos.md#objeto-chamante)
  * Conceito de classe não replicável
  * [Chamadas dentro da própria classe](atributos-e-metodos-estaticos.md#chamando-dentro-da-propria-classe)
* [Digitação de dados:](digitacao-de-dados.md) classe auxiliar para ler dados em formato de string.
  * Lendo strings e convertendo para outros tipos de dados
  * [Variáveis na inicialização](digitacao-de-dados.md#variaveis-na-inicializacao)
  * [Funcionamento do try-catch](digitacao-de-dados.md#funcionamento-do-try-catch)
* [Heranças:](herancas.md) classe herda atributos e métodos de outra
  * Palavra extend
  * [Qualificador protected](herancas.md#novo-qualificador-protected)
  * [Palavra super](herancas.md#palavra-super)
  * [Importações](herancas.md#anotacoes-de-importacoes)
* [Javadoc:](javadoc.md) ferramenta para gerar uma documentação do código em HTML.
  * Detalhes de como usar
  * Notações usadas
* [Outros:](outros/)
  * [Resuminho básico](outros/resuminho.md)
  * [Expressões regulares:](outros/expressoes-regulares.md) validação sofisticada de dados.
    * Compilação de expressões
    * Uso prático
