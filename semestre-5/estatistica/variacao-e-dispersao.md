# Variação e dispersão

Médias não descrevem variabilidade[^1], portanto, existem medidas para calcular **variação ou dispersão**. O dado mais preciso é o **coeficiente de variação**, mas ele é uma fórmula final que utiliza váriais outras fórmulas para chegar nele.

{% hint style="info" %}
Quando trabalhamos com dados agrupados, aparecem novos dados nas fórmulas como **PM** (ponto médio da classe).
{% endhint %}

## Amplitude

Simbolizado com `A`, é a <mark style="color:blue;">Diferença entre o valor máximo e mínimo</mark>, ou seja, são apenas dois dados e o restante é descartado. Por conta disso, falta sensibilidade, o que é um fator ruim considerar apenas amplitude.

<figure><img src="../../.gitbook/assets/formula amplitude.png" alt="" width="375"><figcaption></figcaption></figure>

## Desvio

É calculado o <mark style="color:blue;">desvio de cada dado</mark>, por isso simbolizamos com um `i` o desvio de cada um.

Existem **vários tipos de desvios**, criados um para corrigir a eficácia do outro. Cada tipo de desvio pode ser utilizado em uma outra fórmula, como **variância**. Por isso, é necessário saber a fórmula de todos.

Se o dado é uma classe, precisamos utilizar o **ponto médio** desse conjunto de dados.

### Desvio normal

Simbolizado com `d`.

<figure><img src="../../.gitbook/assets/formula desvio.png" alt="" width="563"><figcaption></figcaption></figure>

### Desvio absoluto

Simbolizado com `da`, segue a mesma lógica mas a <mark style="color:blue;">somatória é feita em módulo</mark>. Isso quer dizer que o valor de desvio total aumenta muito conforme o número de dados.

<figure><img src="../../.gitbook/assets/formula desvio absoluto.png" alt="" width="528"><figcaption></figcaption></figure>

### Desvio quadrático

Simbolizado com `dq`, surge para corrigir o fato do desvio absoluto extrapolar o número quando se tem muitos dados. Ele não é feito em módulo e sim ao quadrado, para resultados negativos não anularem positivos.

<figure><img src="../../.gitbook/assets/formula desvio quadratico.png" alt=""><figcaption></figcaption></figure>

### Desvio médio

Simbolizado com `dm`, soma todos os desvios e divide pelo total da amostra.

<figure><img src="../../.gitbook/assets/formula desvio medio.png" alt="" width="563"><figcaption></figcaption></figure>

### Desvio padrão

Simbolizado com `S`, é a <mark style="color:blue;">raíz quadrada da variância</mark>. Como a variância usa desvio quadrático, o desvio padrão foi uma solução para não aumentar muito o valor do dado.

<figure><img src="../../.gitbook/assets/formula desvio padrao.png" alt="" width="351"><figcaption></figcaption></figure>

Esse desvio utiliza muitas variáveis. O número `S` isolado não tem muito significado e pois isso, seguimos para o **coeficiente de variação**.

## Variância

Simbolizado com `S²` (não significa que está ao quadrado), é a média dos desvios quadráticos, ou seja, somar todos os desvios elevados ao quadrado e depois dividir por um número, ao qual pode mudar se estamos trabalhando com [amostra ou população](conceitos-base.md). Na maioria dos casos, iremos dividir sempre por `n`.

Iremos usar `n-1` apenas se for selecionado uma amostra de elementos de toda a nossa coluna de dados. Esse valor -1 serve para corrigir o viés amostral, pois estamos estimando a dispersão da população inteira por apenas um conjunto de amostras.

<figure><img src="../../.gitbook/assets/como calcular variancia.png" alt="" width="563"><figcaption></figcaption></figure>

## Coeficiente de variação

Simbolizado com `CV`, ele obtém um resultado em porcentagem e por isso facilita a visualização da variação. É considerado algo adimencional.

Vai ter como resultado algo parecido com `0,04` por exemplo, e por isso multiplica por `100`, pois assim fica facilmente visualizado como `4%`.

<figure><img src="../../.gitbook/assets/formula coeficiente de variação.png" alt="" width="266"><figcaption></figcaption></figure>

[^1]: Afastamento da referência central.
