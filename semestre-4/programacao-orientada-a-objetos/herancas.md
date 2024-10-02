# Heranças

Herança faz parte dos 3 pilares de orientação à objetos. Uma herança herda todos os atributos, métodos e características. Na classe herdada podemos adicionar e re-implementar métodos. Copiar classes geram necessidades de manutenção em cada classe e não somente na original.

<figure><img src="../../.gitbook/assets/image (1).png" alt=""><figcaption></figcaption></figure>

A herança herda praticamente tudo, exceto <mark style="color:red;">construtores</mark>. Com a exceção deles, se não re-implementarmos nenhum método ou atributo na nova classe, tudo funcionaria. Em uma classe executável, ao instanciar objeto da nova classe, já podemos usar os métodos da classe herdada.

## Novo qualificador protected

Além dos qualificadores private, public e static, temos o qualificador protected que está relacionado com heranças. Um método declarado como `protected` simboliza que ele poderá ser <mark style="color:blue;">usado nas classes herdadas</mark>, onde o `private` não serve para elas.

Lembrando que o private é um qualificador exclusivo para a classe que ele está, já o protected vai dar essa liberdade para as herdadas, por exemplo:

```java
public class X {
    private int getUmDez() {
        return 10;
    }
    
    protected int getUmOnze() {
        return 11;
    }
}

public class Y extends X {
    int numDez = getUmDez();    // Erro = não pode ser acessado fora de X
    int numOnze = getUmOnze();  // Correto = protected permite esse acesso
}
```

## Palavra super

Essa palavra também aparece relacionado com heranças. Como dito acima, construtores não são herdados, portanto, deve construir um na nova classe. A palavra `super` dá o poder de <mark style="color:blue;">chamar o construtor que não foi herdado</mark>. Podemos lembrar da palavra super pois ele se referencia à "super classe". Atenção para:

* `super` só pode ser usado dentro de um construtor.
* <mark style="color:orange;">Deve ser a primeira linha</mark> do novo construtor. Pode haver mais código depois dele, mas nunca antes.

```java
public AgendaConsultavel(int cap) throws Exception {
    super (cap); // Chama o construtor da super classe passando esse parâmetro
}
```

Portanto, na implementação da nova classe, CHAMA aquele construtor que não foi herdado. Mesma coisa acontece com o construtor de cópia:

```java
public AgendaConsultavel(AgendaConsultavel modelo) {
    super (modelo);
}
```
