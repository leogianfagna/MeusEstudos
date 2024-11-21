# Herança

Herança faz parte dos 3 pilares de orientação à objetos. Uma herança herda todos os atributos, métodos e características. Na classe herdada podemos adicionar e re-implementar métodos. Copiar classes geram necessidades de manutenção em cada classe e não somente na original.

<figure><img src="../../../.gitbook/assets/extends em java.png" alt=""><figcaption></figcaption></figure>

A herança não herda <mark style="color:red;">construtores</mark>. Com a exceção deles, se não re-implementarmos nenhum método ou atributo na nova classe, tudo funcionaria. Em uma classe executável, ao instanciar objeto da nova classe, já podemos [usar os métodos](#user-content-fn-1)[^1] da classe herdada.

## Novo qualificador protected

Além dos qualificadores `private`, `public` e `static`, temos o qualificador `protected` que está relacionado com heranças. Um método declarado como `protected` simboliza que ele poderá ser <mark style="color:blue;">usado nas classes herdadas</mark>, onde o `private` [não serve](#user-content-fn-2)[^2] para elas.

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

A palavra `super` dá o poder de <mark style="color:blue;">chamar o construtor que não foi herdado</mark>, pois o construtor da classe pai deve ser chamado. Podemos lembrar da palavra super pois ele se referencia à "super classe". Atenção para:

* `super` só pode ser usado dentro de um construtor.
* <mark style="color:orange;">Deve ser a primeira linha</mark> do novo construtor. Pode haver mais código depois dele, mas nunca antes.

```java
public AgendaConsultavel(int cap) throws Exception {
    super (cap); // Chama o construtor da super classe passando esse parâmetro
}

// Mesma coisa acontece com o construtor de cópia
public AgendaConsultavel(AgendaConsultavel modelo) {
    super (modelo);
}
```

## Importações

Para herdar, precisamos importar a classe herdada. Para isso, podemos seguir os seguintes padrões:

<figure><img src="../../../.gitbook/assets/importações na herança.png" alt=""><figcaption></figcaption></figure>

Também podemos fazer da seguinte forma para importar tudo:

```java
import agenda.*;
```



[^1]: Podemos chamar os métodos normalmente com `meuMetodo()`, sem a necessidade da palavra `super`.

[^2]: Private é um qualificador exclusivo para a classe que ele está e nem mesmo as herdadas poderiam usar.
