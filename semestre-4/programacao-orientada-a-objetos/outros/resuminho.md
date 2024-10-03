# Resuminho

{% hint style="info" %}
Uma programação orientada a objetos pode exigir muitos conceitos complexos, portanto, esta página é um cronograma resumido de aprendizagem onde o aprofundamento de termos e explicações estão nas sub páginas dessa disciplina.
{% endhint %}

## Definição

Orientação à objetos significa orientação à peças que são instâncias. Instâncias podem ser vistas como um kit com ferramentas que processam dados e possuem algoritmos para esses dados, compostos de métodos (funções ou procedimentos) e atributos (variáveis ou constantes).

Um objeto é nada mais nada menos que uma [renomeação para a instância](../instancias-e-objetos.md#instancia-renomeada), de outra forma, é um ponteiro, que aponta para o conteúdo dela. Nomes dados às instâncias significam que elas poderão ser reutilizadas ao longo do código. Uma instância sem nome só poderá ser usada uma vez no seu ciclo de vida.

Por ser orientado a objetos, toda instância está relacionada a uma classe que tem um construtor com o seu mesmo nome (chamado automaticamente). Assim, a criação da classe se dá de uma <mark style="color:blue;">alocação usando new e o construtor da classe</mark>, dessa forma:

<figure><img src="../../../.gitbook/assets/definição na criação de instâncias (resumida).png" alt=""><figcaption></figcaption></figure>

Existe a classe principal com o método executável e as demais classes que servirão de molde para a criação das instâncias. Como essas extras classes serão usadas o tempo inteiro, há de se cuidar com a segurança de uso delas (ouvimos como "antas" durante as aulas). Isso significa que essas classes possuem variáveis e métodos e que não podemos deixar que eles sejam manipulados livremente através de outras classes.

Isso ocorre pela definição de [private ou public](../classes/#criacao-de-classes-de-forma-segura). Como eles estão privados e só podem ser manipulados dentro da própria classe, isso exige a criação de métodos getters e setters dentro da mesma para serem usados de forma externa. Basicamente, feito desta forma:

```java
public void setMes(byte mes) throw Exception {
  if (!Data.isValida(this.dia, mes, this.ano)) throw new Exception ("Mês inválido");
  this.mes = mes;
}
```

O construtor serve para dar os valores iniciais das variáveis da classe, em outras palavras, nascer com atributos válidos, também servindo como forma de segurança para não ter valores zerados ou equivocados.
