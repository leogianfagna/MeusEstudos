# Estatística descritiva

{% hint style="info" %}
Essa seção utiliza conhecimentos obtidos em estatística, como as [medidas de posição](../estatistica/medidas-de-posicao.md) e [variação e dispersão de dados](../estatistica/variacao-e-dispersao.md).
{% endhint %}

Conhecer os dados (como sua distribuição numérica, como estão organizados, etc) é o primeiro passo para criar um modelo de IA. Uma análise dos dados pode ser:

* <mark style="color:purple;">Univariável</mark>: Analisando um dado isolado de cada vez.
* <mark style="color:purple;">Bivariável</mark>: Analisar vários dados juntos buscando encontrar uma correlação entre variáveis.

## Univariável

A **distribuição de dados** gera gráficos que são usados para calcular a **simetria**. Isso pode dizer muito como os dados estão distribuídos e como trabalhar com eles, por exemplo, se há presença de muitos outliers.

### Simetria

Colocar a distribuição de dados em um gráfico é possível verificar qual o tipo de simetria entre eles, pois vai formar algo desse tipo:

<figure><img src="../../.gitbook/assets/simetria em distribuição de dados.png" alt=""><figcaption></figcaption></figure>

Visualmente é fácil reconhecer. Contudo, para reconhecer isso matematicamente, utilizamos os valores de [média](../estatistica/medidas-de-posicao.md#media-aritmetica), [mediana](../estatistica/medidas-de-posicao.md#mediana) e [moda](../estatistica/medidas-de-posicao.md#moda) e verificamos a proximidade entre eles. Quando aparece como igual `=`, isso quer dizer valores próximos.

### Interpretação para desvio padrão

O cálculo do [desvio padrão](../estatistica/variacao-e-dispersao.md#desvio-padrao) nos ajuda a verificar <mark style="color:blue;">se a distribuição de dados é normal</mark>, mas isso é válido <mark style="color:orange;">apenas se a distribuição for simétrica</mark>, algo visto acima. Caso não seja, não utilizaremos essa técnica.

<figure><img src="../../.gitbook/assets/interpretação para desvio padrao.png" alt="" width="563"><figcaption></figcaption></figure>

Então o gráfico acima mostra como os dados devem estar distribuídos para considerar uma **distribuição normal**. Então por exemplo, se o desvio padrão é 2 e a média é 5, 68% dos dados devem estar entre `3` (que é `5-2`) e `7` (que é `5+2`).

### Interpretação para CV

Lembrando que, se quisermos medir o quão grande é desvio padrão, usamos o [coeficiente de variação](../estatistica/variacao-e-dispersao.md), todos conceitos vistos em estatística.

Se o resultado desse coeficiente for menor que 20%, quer dizer que a mistura é homogênea/interface gráfica consistente (pouca variação).

### Medidas de Posição Relativa

Quartis[^1], decis[^2] e percentis[^3] dividem os dados (que devem estar em ordem crescente) em partes iguais e isso permite relacionar [quantidades de um com outro](#user-content-fn-4)[^4]. Se um se equivale com o outro, vamos optar por **usar percentis** nas métricas.



[^1]: São 3 quartis, que dividem os dados em 4 partes.

[^2]: São 9 decis que dividem os dados em 10 partes.

[^3]: São 99 decis que dividem os dados em 100 partes.

[^4]: Exemplo, 2 quartis (que equivale a 50%) é o mesmo de 5 decis (que também vai equivaler 50%).
