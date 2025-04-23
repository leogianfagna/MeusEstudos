# Imputação de valores

Trata-se de <mark style="color:blue;">arrumar os dados de uma base</mark>, seja dados nulos ou outliers, para encontrar padrões e criar modelos de machine learning. Qualquer dado ausente ou fora de proporção, dificulta encontrar padrões. Muitos algoritmos de IA, como redes neurais, não funcionam com dados faltantes.

<figure><img src="../../.gitbook/assets/tipo de problemas de imputação.png" alt=""><figcaption></figcaption></figure>

Uma boa imputação de valores <mark style="color:green;">não mudam as métricas estatísticas</mark>. Então, é preciso calcular [métricas estatísticas](#user-content-fn-1)[^1] antes e depois da imputação para fazer comparativos. Isso pode ser feito de forma simples com `describe` e comparar os valores de saída.

## Remoção de valores

Cabe aqui para casos específicos ou **apenas como exemplo**, pois a solução <mark style="color:red;">não pode estar limitada em apenas remover os dados</mark> em que possuem ausências ou discrepâncias, pois esses dados podem fazer falta tornando a amostra artificial. Imagine que 15% dos dados estão com informações ausentes.

É necessário conhecer quais são os valores fora de padrão para conseguir removê-los. Para isso, vemos em [estatística descritiva](estatistica-descritiva.md) que podemos usar desvio padrão para dados simétricos e distância interquartílica para dados assimétricos (na pratica, IQR pode ser usado para ambos).

Vamos supor a seguinte base de dados de vendas:

```python
vendas = pd.read_csv("vendasRuido.csv", header=None)
vendas.columns = ['hora','prod1','prod2']
```

<figure><img src="../../.gitbook/assets/bd - base de dados de vendas ex.png" alt=""><figcaption></figcaption></figure>

### Distância interquartílica

Vemos que para o produto 1, temos entre 10 (min) e 80 (max) vendas por hora; mas em 50% das horas amostradas (de 25% até 75%), temos entre 22 e 28 vendas. É intuitivo pensar que, se na metade das horas as vendas oscilam em 6 pontos (nosso IQR), valores que se distanciem em 6 pontos do Q1 e do Q3 sejam bem mais raros.

Em aplicações reais tendemos a ser ainda mais permissivos na nossa margem, **multiplicamos o IQR por 1.5** e adicionamos ou subtraímos de Q3 e Q1 (respectivamente) para definir a nossa região de dados 'comuns'. Esse valor é tão usado que é pradrão em um plot estatístico, o **boxplot.**

> \> (Q3 + IQR\*1.5) - Outlier
>
> < (Q1 - IQR\*1.5) - Outlier

```python
# Calculando IQR e margem 'válida'
IQR = vendas[['prod1','prod2']].quantile(0.75) - vendas[['prod1','prod2']].quantile(0.25)
margemMin = vendas[['prod1','prod2']].quantile(0.25) - IQR * 1.5
margemMax = vendas[['prod1','prod2']].quantile(0.75) + IQR * 1.5

# Filtrando valores anormais/outliers
idx = []
for col in ['prod1','prod2']:
    filtered = vendas[col][(vendas[col] < margemMin[col]) | (vendas[col] > margemMax[col])]
    idx.extend(filtered.index)
    
# Retornar dentro do df vendas apenas os índices que são anormais
vendas.iloc[idx]
```

Esse dataframe `vendas` agora possui todas as linhas que tem alguma coluna que seja outlier, ou seja, não são todos os dados mas sim alguma variável da linha.

### Desvio padrão

Ainda sob essa perspectiva de usar alguma medida de amplitude para medir valores anormais, podemos utilizar o desvio padrão. Sabemos que em amostras simétricas temos 68% das amostras dentro de 1 desvio padrão da média, e quando aumentamos essa margem para 3 desvios padrões temos cerca de 99.7%. Iremos filtrar fora todas as amostras que estão a 3 desvios padrões da média, para mais ou para menos.

```python
# Calculando IQR e margem 'válida'
deviation = vendas[['prod1','prod2']].std()
margemMin = vendas[['prod1','prod2']].mean() - 3 * deviation
margemMax = vendas[['prod1','prod2']].mean() + 3 * deviation

# Filtrando valores anormais/outliers
idx = []
for col in ['prod1','prod2']:
    filtered = vendas[col][(vendas[col] < margemMin[col]) | (vendas[col] > margemMax[col])]
    idx.extend(filtered.index)
    
# Retornar dentro do df vendas apenas os índices que são anormais
vendas.iloc[idx]
```

### Conclusão

O resultado produzido por cada uma das abordagens se manteve parecido, mas não idêntico. Como dito, cada um deles é usado para um caso de simetria.

## Imputando valores

A imputação de valores pode ser tanto para corrigir valores anômalos ou ausentes. É necessário descobrir qual valor precisa ser inserido.

Intuitivamente, podemos definir valores nulos como o valor da média geral, pois isso não afetaria estatísticas como média e mediana, mas afetaria desvios e quartis. Isso porque vai criar grandes anomalias.

Vamos supor uma base de pessoas que incluem crianças. Uma criança de 1.05m está sem pesagem e a média de peso da base de dados está valendo 75kg. Fazendo uma imputação desta forma, temos uma criança com um peso absurdo. Por conta disso, é necessário usar métodos mais eficazes, como a imputação por vizinhança.

:warning: parei aqui

## Dúvidas que ficaram

1. Devemos imputar os outliers?

[^1]: Todas elas, como média, mediana, percentil, desvio, etc.
