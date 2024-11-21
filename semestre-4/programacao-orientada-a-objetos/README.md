# Programação orientada à objetos

Aprendizado da linguagem Java e técnicas de qualquer outra linguagem orientada a objetos.

## Sumário

* [Regras de nomenclatura](introducao/regras-de-nomenclatura.md): como nomear classes, variáveis, métodos, etc.
* [Instâncias e objetos](introducao/instancias-e-objetos.md): explicação inicial de como entender o conceito de peça.
  * [Entendendo instâncias](introducao/instancias-e-objetos.md#o-que-sao-instancias)
  * [Entendendo objetos como um ponteiro](introducao/instancias-e-objetos.md#o-que-sao-objetos)
  * [Criação prática de uma instância](introducao/instancias-e-objetos.md#criacao-pratica)
  * [Primeiro contato com instância chamante](introducao/instancias-e-objetos.md#instancia-chamante)
* [Classes:](estrutura/classes.md) conceito de ser um molde para instâncias
  * [A classe executável](estrutura/classes.md#uso-de-classes-para-instancias)
  * [Criação de classes seguras](estrutura/classes.md#criacao-de-classes-de-forma-segura)
    * Uso de qualificadores private/public
    * Métodos getters e setters
    * Objetivo do construtor
    * Formas de validar dados em construtores
  * [Primeiro contato com membros estáticos](estrutura/classes.md#membro-estatico)
  * [Classe object:](estrutura/classes.md#classe-object) a classe onde todas herdam e precisa de re-implementações.
    * [toString](broken-reference)
    * [equals](broken-reference)
    * [hashCode](broken-reference)
    * [compareTo](broken-reference)
      * Carteirinha Comparable
    * [clone](broken-reference)
      * [Construtor de cópia](broken-reference)
* [Classes Wrapper:](estrutura/classes-wrapper.md) conceito de embrulhar um tipo primitivo e disponibilizar métodos.
  * Comodidade na automatização de objetos
  * Conceito de boxed e unboxed
* [Classes parametrizadas:](estrutura/classes-genericas.md) direcionar o modo de funcionamento.
  * Classes genéricas
  * [Conjuntos homogêneos e heterogêneos](estrutura/classes-genericas.md#conjuntos-heterogenios)
* [Instância oca:](introducao/instancia-oca.md) criar instância de classes com apenas atributos estáticos
* [Atributos e métodos estáticos:](introducao/atributos-e-metodos-estaticos.md) qualificador static
  * Entende o significa encapsulamento
  * [Objeto chamante](introducao/atributos-e-metodos-estaticos.md#objeto-chamante)
  * Conceito de classe não replicável
  * [Chamadas dentro da própria classe](introducao/atributos-e-metodos-estaticos.md#chamando-dentro-da-propria-classe)
* [Digitação de dados:](mecanismos/digitacao-de-dados.md) classe auxiliar para ler dados em formato de string.
  * Lendo strings e convertendo para outros tipos de dados
  * [Variáveis na inicialização](mecanismos/digitacao-de-dados.md#variaveis-na-inicializacao)
  * [Funcionamento do try-catch](mecanismos/digitacao-de-dados.md#funcionamento-do-try-catch)
* [Heranças:](pilares/heranca.md) classe herda atributos e métodos de outra
  * Palavra extend
  * [Qualificador protected](pilares/heranca.md#novo-qualificador-protected)
  * [Palavra super](pilares/heranca.md#palavra-super)
  * [Importações](pilares/heranca.md#anotacoes-de-importacoes)
* [Javadoc:](mecanismos/javadoc.md) ferramenta para gerar uma documentação do código em HTML.
  * Detalhes de como usar
  * Notações usadas
* [Outros:](broken-reference)
  * [Resuminho básico](broken-reference)
  * [Expressões regulares:](mecanismos/expressoes-regulares.md) validação sofisticada de dados.
    * Compilação de expressões
    * Uso prático
