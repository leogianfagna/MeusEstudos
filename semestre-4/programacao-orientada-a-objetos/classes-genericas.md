---
description: >-
  Como criar uma classe genérica, como um conjunto de dados, é mostrado na
  página de "Classes de dados".
---

# Classes genéricas

Podemos ter um parâmetro em classes para influenciar/direcionar no modo de funcionamento:

<figure><img src="../../.gitbook/assets/parametros em classes java.png" alt="" width="375"><figcaption></figcaption></figure>

Neste caso, indicamos que o vetor `v` guardará datas. O parâmetro de uma classe <mark style="color:orange;">deve ser uma outra classe</mark> (Data é uma classe). Já que muitas classes Java são parametrizadas, as **classes Wrapper** servem para esse intuito. Veja um exemplo na main:

```java
public static void main(String[] args) {
    Conjunto<String> linguagens;
    Conjunto<Integer> primos;
    Conjunto<Data> feriados;
    Conjunto<Conjunto<String>> conjuntos;
}
```

Quando uma classe tem parâmetro, ela é chamada de <mark style="color:blue;">genérica</mark>. A classe genérica permite uma única implementação, não precisa criar várias para cada tipo de parâmetro/tipo:

<figure><img src="../../.gitbook/assets/parâmetros em classes java na pratica.png" alt=""><figcaption></figcaption></figure>

Aqui vemos a criação de uma instância da classe **Conjunto** parametrizando uma String. Essa classe conjunto deixa a parametrização como `X`, o que significa que, esse X vai assumir o tipo inserido na hora da instanciação, ou seja, **String**. Então, se o conjunto foi criado com o tipo X sendo uma String, não aceitará (resultará erro) outro tipo, que é o exemplo da linha 3.

## Conjuntos heterogênios

O que foi mostrado acima é classificado como conjunto <mark style="color:blue;">homogênio</mark>. Um conjunto <mark style="color:blue;">heterogênio é quando ele aceita qualquer tipo de dado</mark>. Por exemplo:

```java
Conjunto<Object> tudo = new Conjunto<Object>();
```

Sabemos que Object simboliza tudo, então qualquer tipo pode ser guardado, o que define o conjunto heterogênio. Isso não é tão vantajoso pois a funcionalidade das classes parametrizadas é criar uma segurança nos tipos e ao fazer isso com Object é desvantagem pois pega algo que não sabemos o que é.
