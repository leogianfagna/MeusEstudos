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

Se o resultado desse coeficiente for menor que 20%, quer dizer que a mistura é homogênea e tem interface gráfica consistente (pouca variação).

### Medidas de Posição Relativa

Quartis[^1], decis[^2] e percentis[^3] <mark style="color:blue;">dividem os dados</mark> (que devem estar em ordem crescente) em partes iguais e isso permite relacionar [quantidades de um com outro](#user-content-fn-4)[^4]. Se um equivale ao outro, vamos optar por **usar percentis** nas métricas.

Se os dados são divididos em partes, isso <mark style="color:green;">permite resgatar dados situados em uma determinada posição</mark>, a posição 90 de um percentil.

Na programação, usar `pencentile` retorna o valor que está na casa. Esse valor normalmente <mark style="color:orange;">não é um valor válido no conjunto de dados</mark> (pois se tem mais de 100 dados, mais de um dado vai dividir a mesma casa). Então o dado que representa a casa é um <mark style="color:blue;">resultado de uma interpolação</mark>.

Para conseguir um dado exato que está dentro dessa casa, existem argumentos dentro do método `percentile`, como `interpolation="lower"`.

<figure><img src="../../.gitbook/assets/l para medidas de posição relativa.png" alt="" width="375"><figcaption></figcaption></figure>

Usando a fórmula acima, o percentil `Pk` será:

* Se o valor gerado `L` for inteiro, será a média [da casa](#user-content-fn-5)[^5] respectiva com a próxima.
* Se o valor gerado `L` for quebrado, arredondar para cima e será o valor obtido nesta casa.

<details>

<summary>Exemplo prático</summary>

Encontrar o valor de venda das casas 10% mais caras (o valor que divide):

```python
percentil_90 = df["SalePrice"].quantile(0.90, interpolation="lower")
print(percentil_90)
```

</details>

### Distância interquartílica

É uma métrica de **dispersão**, calculada pela diferença `Q3 - Q1` dos quartis ditos acima usada para <mark style="color:blue;">mostrar onde estão 50%</mark> dos dados e pode ser usada para **detectar outliers**. Enquanto o desvio padrão é usado para distribuições simétricas, a <mark style="color:blue;">distância interquartílica é usada em distribuições não normais</mark> (assimétricas).

Para detectar outliers, procuramos valores fora do intervalo. Valores abaixo de `Q1 - 1.5 * IQR` e acima de `Q3 + 1.5 * IQR` são outliers, sendo Q1 e Q3 as medidas de posição relativa dos dados que estamos explorando. Essa métrica (DI) é resistente aos outliers, por isso é muito boa.

<table><thead><tr><th width="125">Métrica</th><th width="99">Valor</th></tr></thead><tbody><tr><td>min</td><td>10</td></tr><tr><td>25%</td><td>22</td></tr><tr><td>50%</td><td>25</td></tr><tr><td>75%</td><td>28</td></tr><tr><td>max</td><td>80</td></tr></tbody></table>

Esses valores em porcentagem são os nossos quartis. Para IQR explicar metade da nossa base, usamos:

$$
IQR = Q3(75) - Q1(25) = 28-22=6
$$

Então metade da nossa base oscila entre 6 pontos de diferença. Esse valor pode ser usada na detecção de outliers usandos as fórmulas mostradas acima:

$$
OutlierInferior = Q1-1.5*IQR=22-1.5*6=13
$$

$$
OutlierSuperior = Q3+1.5*IQR=28-1.5*6=37
$$

Portanto, valos acima de 13 e abaixo de 37 são os outliers da nossa base, já que os dados que ficam entre esse intervalo são considerados nossa região de dados comuns. Esse valor é tão usado que é padrão em um plot estatístico, o **boxplot.**

{% hint style="success" %}
Mesmo dizendo que é utilizada apenas quando é assimétrica, é de costume utilizar essa fórmula mesmo assim, a qualquer momento.
{% endhint %}

<details>

<summary>Exemplo prático</summary>

#### Calcular a distância interquartílica:

```python
q1 = pd.Series(df["SalePrice"]).quantile(0.75)
q3 = pd.Series(df["SalePrice"]).quantile(0.25)

iqr = q1 - q3
```

#### Calcular quem são os outliers

```python
df_sp = df["SalePrice"]

outliers_low = pd.Series(df_sp).quantile(0.25) - 1.5 * iqr
outliers_high = pd.Series(df_sp).quantile(0.75) + 1.5 * iqr

# Transformando em series
outliers_series_high = df_sp[df_sp > outliers_sale_price_high]
outliers_series_low = df_sp[df_sp < outliers_sale_price_low]

# Concatenar as duas series
df_outlier = pd.concat([
        outliers_sale_price_series_low,
        outliers_sale_price_series_high]).to_frame()

```

</details>

### Escore Z

Uma métrica usada para um único valor para descobrir o quão raro ele é em relação à serie sendo estudada, ou seja, também é possível perceber se é um outlier.&#x20;

Seu resultado será um número e, se o valor resultar **menor que `–2`** ou **maior que `2`**, ele é incomum.

<figure><img src="../../.gitbook/assets/escore z.png" alt="" width="375"><figcaption></figcaption></figure>

<details>

<summary>Exemplo prático</summary>

Amostra = `[ 1, 3, 6, 15, 20, 32 ]`

Lembrando que essa é uma métrica para descobrir algo em relação a um dado apenas. Se queremos saber se `15` é um outlier, substituir:

* X por 15.
* Calcular a média e substituir.
* Calcular o desvio padrão e substituir.
* Descobrir Escore Z

</details>

## Bivariável

Agora as fórmulas recebem variáveis x e y, pois estamos comparando um dado ao outro.

### Coeficiente de associação ou correlação

{% hint style="info" %}
Correlação <mark style="color:red;">não indica casualidade</mark>. Não necessariamente um valor influencia no outro.

Por exemplo, venda de sorvete **tem correlação** com protetor solar, mas um **não é causa** do outro (e sim o verão).

Site exemplo disto: [https://www.tylervigen.com/spurious-correlations](https://www.tylervigen.com/spurious-correlations)
{% endhint %}

<figure><img src="../../.gitbook/assets/coeficiente de associação ou correlação.png" alt=""><figcaption></figcaption></figure>

| Valores de r (+ ou -) | O que significa        |
| --------------------- | ---------------------- |
| 0,00&#xD;             | Ausência de Correlação |
| 0,01 a 0,19 &#xD;     | Correlação muito fraca |
| 0,20 a 0,39&#xD;      | Correlação fraca       |
| 0,40 a 0,69           | Correlação moderada    |
| &#xD;0,70 a 0,89&#xD; | Correlação forte       |
| 0,90 a 0,99&#xD;      | Correlação muito forte |
| 1,00                  | Correlação perfeita    |

Quanto mais próximo de 1 o valor de R, mais visivelmente podemos ver a correlação de dados em um gráfico. O valor de R pode ser negativo, e assim, quer dizer que tem uma correlação negativa (o gráfico está decrescente).

## Métodos estatística descritiva

Leve como `df` sendo um dataframe com dados, mas que poderia também ser uma serie!

```python
media = df['Idade'].mean()
mediana = df['Idade'].median()
moda = df['Idade'].mode() # Retorna uma serie com todas as modas
variancia = df['Idade'].var()
desvio_padrao = df['Idade'].std()
amplitude = max(df['Idade']) - min(df['Idade'])
coeficiente_variacao = df['Idade'].std() / df['Idade'].mean() # * 100 se quiser
```

#### Quartil

A biblioteca Pandas fornece apenas quartil para cálculos e ele é usado para todos os casos (se deseja percentil ou decil).&#x20;

Usa como parâmetro valores de 0 a 1, então calcular percentil 90 seria utilizar `quartil(0.9)`.

```python
df['Idade'].quantile(0.25)

# Retorna vários em uma serie
df['Idade'].quantile([0.25,0.5,0.75,0.90,1])
```

#### Escore Z

```python
import scipy.stats as stats

data = np.array([2.20,2.28,2.23,2.20,2.35,2.28,2.25,2.30,2.37,2])
escore_z = stats.zscore(data)
```

#### Correlação

Agora aparecem dois dados para serem relacionados, chamaremos de x e y que serão duas series.

```python
x = pd.Series([6,8,6,10,8,14,12,14,12,16])
y = pd.Series([8,8,12,12,16,16,20,20,24,24])

correlacao_x = x.corr(y)
correlacao_y = y.corr(x)
```

[^1]: São 3 quartis, que dividem os dados em 4 partes.

[^2]: São 9 decis que dividem os dados em 10 partes.

[^3]: São 99 decis que dividem os dados em 100 partes.

[^4]: Exemplo, 2 quartis (que equivale a 50%) é o mesmo de 5 decis (que também vai equivaler 50%).

[^5]: Em outras palavras, da posição da amostra. Se ele fala da casa/posição 5, quer dizer que é o quinto dado da amostra.
