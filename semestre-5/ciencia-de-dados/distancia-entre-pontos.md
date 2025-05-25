# Distância entre pontos

## Distância euclidiana

A distância euclidiana é a medida do espaço geométrico entre dois pontos em um plano cartesiano. Vimos aqui como criar [gráficos de dispersão](../estatistica/variacao-e-dispersao.md#dispersao). Ela poder ser a hipotenusa entre dois pontos, mas sabemos que pontos em um gráfico podem ter mais de uma coluna.

Vejamos um exemplo com vários dados e um deles é o nosso rótulo:

<figure><img src="../../.gitbook/assets/exemplo de tabela.png" alt=""><figcaption></figcaption></figure>

O <mark style="color:orange;">rótulo não é contabilizado</mark> para fazer o cálculo da distância. A fórmula da distância é a raíz da <mark style="color:blue;">diferença de cada ponto</mark>, portanto a distância do ponto 1 para o ponto 2 será:

<figure><img src="../../.gitbook/assets/distancia euclidiana com tabela ex.png" alt=""><figcaption></figcaption></figure>

Substituímos os dados do ponto 1 e ponto 2 de respectivas de cada coluna, então temos:

<figure><img src="../../.gitbook/assets/substituindo valores.png" alt=""><figcaption></figcaption></figure>

Continuamos com os cálculos e tiramos a raíz ao final:

$$
d(1,2) = √(1² + (-2)² + 2² + (-4)²) = √25 = 5
$$

Portanto, a distância(1,2) equivale à `5`.

{% hint style="warning" %}
Quando o valor de alguma coluna é nulo ou inválido, ele **não entra no cálculo**. Supondo que a coluna Respiração do Dado 2 seja nulo, essa coluna será ignorada por completo, mesmo que o valor do Dado 1 seja válido.
{% endhint %}



