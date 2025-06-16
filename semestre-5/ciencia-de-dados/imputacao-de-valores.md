# Imputação de valores

Trata-se de <mark style="color:blue;">arrumar os dados de uma base</mark>, seja dados nulos ou outliers, para encontrar padrões e criar modelos de machine learning. Qualquer dado ausente ou fora de proporção, dificulta encontrar padrões. Muitos algoritmos de IA, como redes neurais, não funcionam com dados faltantes.

<figure><img src="../../.gitbook/assets/tipo de problemas de imputação.png" alt=""><figcaption></figcaption></figure>

Uma boa imputação de valores <mark style="color:green;">não mudam as métricas estatísticas</mark>. Então, é preciso calcular [métricas estatísticas](#user-content-fn-1)[^1] antes e depois da imputação para fazer comparativos. Isso pode ser feito de forma simples com `describe` e comparar os valores de saída.

## Encontrar valores

Para encontrar todos os registros que possuam algum dado nulo em alguma coluna, podemos usar:

```python
df_null = df[df.isnull().any(axis=1)]
```

## Remoção de valores

Cabe aqui para casos específicos ou **apenas como exemplo**, pois a solução <mark style="color:red;">não pode estar limitada em apenas remover os dados</mark> em que possuem ausências ou discrepâncias, pois esses dados podem fazer falta tornando a amostra artificial. Imagine que 15% dos dados estão com informações ausentes.

É necessário conhecer quais são os valores fora de padrão para conseguir removê-los. Para isso, vemos em [estatística descritiva](estatistica-descritiva.md) que podemos usar desvio padrão para dados simétricos e distância interquartílica para dados assimétricos (na pratica, IQR pode ser usado para ambos).

Vamos supor a seguinte base de dados de vendas:

```python
vendas = pd.read_csv("vendasRuido.csv", header=None)
vendas.columns = ['hora','prod1','prod2']
```

<figure><img src="../../.gitbook/assets/bd - base de dados de vendas ex.png" alt=""><figcaption></figcaption></figure>

### Pela distância interquartílica

Quando temos uma distribuição **assimétrica**, podemos usar os [métodos de distância interquartílica](estatistica-descritiva.md#distancia-interquartilica) para descobrir quem são os dados fora de padrão. Esses dados encontrados podem ser dropados da nossa base.

Nesse exemplo, esse dataframe `vendas` agora possui todas as linhas que tem alguma coluna que seja outlier, ou seja, não são todos os dados mas sim alguma variável da linha.

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

### Pelo desvio padrão

Quando temos uma distribuição **simétrica**, ainda sob essa perspectiva de usar alguma medida de amplitude para medir valores anormais, podemos utilizar o desvio padrão. Vimos nos [métodos de desvio padrão](estatistica-descritiva.md#interpretacao-para-desvio-padrao) que 3 desvios simbolizam nossos dados anormais.

Iremos filtrar fora todas as amostras que estão a 3 desvios padrões da média, para mais ou para menos.

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

Vamos supor uma base de pessoas que incluem crianças. Uma criança de 1.05m está sem pesagem e a média de peso da base de dados está valendo 75kg. Fazendo uma imputação desta forma, temos uma criança com um peso absurdo.&#x20;

Por conta disso, existem diversos métodos que podem ser utilizados para essa situação com [mais eficácia](#user-content-fn-2)[^2].

### Imputação por vizinhança (método de aprendizagem)

Quando imputamos por vizinhança, nossa suposição é que amostras similares têm características similares. Vamos entender como fazer, usando como exemplo uma base de dados de pessoa com pesos e alturas.

Vamos primeiro colocar os dados em pontos dispersos em um gráfico. Vamos supor que no nosso dado nulo não temos a altura, consequentemente, não é possível imprirmir o ponto em um gráfico altura x peso. Por conta disso, dispersamos os pontos em um gráfico peso x peso.

<figure><img src="../../.gitbook/assets/image (2).png" alt="" width="539"><figcaption></figcaption></figure>

{% hint style="warning" %}
## Necessidade de normalização e redução de dimensionalidade antes da dispersão

Na imputação por vizinhança, é necessário [normalizar a base de dados](normalizacao-e-padronizacao.md) quando temos mais de duas colunas na dispersão. Isso porque, a distância fica afetada quando não normalizamos por conta da diferença de magnitude dos dados, causando **problemas no algoritmo de distância**.

Quando temos **grandes dimensionalidades**, isso gera problemas do tipo: pontos muito próximos entre si causando dificuldade para descobrir os vizinhos e variáveis irrelevantes causando ruído. Nesse caso, é também importante [aplicar o PCA](pca.md).
{% endhint %}

Vamos ver quem é o nosso ponto que possui um dado nulo que precisa de imputação e vamos encontrar `x` vizinhos através da <mark style="color:purple;">distância euclidiana</mark>. (No nosso exemplo, o ponto nulo é o 7).

```python
from scipy.spatial.distance import pdist
from scipy.spatial.distance import squareform

# Encontrar a distância euclidiana do ponto nulo (o 7) dos demais
# Isso vai criar um dataframe que armazena cada distância de um ponto ao outro
# Portanto, usar dm[7] é a distância do ponto 7 até um determinado ponto (para todos)
Y = pdist([[x] for x in pessoas2['peso'].values], 'euclidean')
dist_matrix = squareform(Y)
dm = pd.DataFrame(dist_matrix)
dm[7].sort_values()

# Calcular a média da ALTURA dos vizinhos de 7 e imputaremos como a altura dele
qtd_vizinhos = 3
altura_somada = 0
vizinhos = []

# Resgatar a altura de cada vizinho mais próximo:
# Usar dm[7].sort_values().index[i] vai pegar a distância do ponto 7 até o ponto "i"
# que está sendo iterado. Esse ponto começará do mais próximo até o mais distante.
# Como a range só vai até 3, vai pegar os 3 mais próximos. Inicia em 1 para ignorar
# ele mesmo
for i in range(1, qtd_vizinhos + 1):
    idxVizinho = dm[7].sort_values().index[i]
    vizinhos.append(idxVizinho)
    altura_vizinho = pessoas2.iloc[idxVizinho]['altura']
    altura_somada = altura_somada + altura_vizinho

# Finaliza o cálculo da média com os dados dos vizinhos e imputa esse valor
# no índice 7, coluna da altura
altura_media_calculada = altura_somada / qtd_vizinhos
pessoas2.loc[7, 'altura'] = altura_media_calculada
```

Agora que nosso novo dataframe contém valores em ambas as colunas, podemos plotar o gráfico com os dados da forma correta (altura x peso) e ver como ficou a distribuição:

```python
# Definir as cores para cada ponto em um vetor para ser usado no scatter()
cores = []
for idx in pessoas2.index:
    if idx == 7:
        cores.append('r')
    elif vizinhos.__contains__(idx):
        cores.append('k')
    else:
        cores.append('b') 
    
# Plotar o gráfico com as cores de cada ponto    
pessoas2.plot.scatter('alt', 'peso', color=cores)
plt.show()
```

<figure><img src="../../.gitbook/assets/imputação por vizinhança completo.png" alt=""><figcaption></figcaption></figure>

Deu para ver que o ponto está muito próximo de onde "deveria estar", ou seja, este ponto foi muito <mark style="color:green;">bem colocado</mark> na dispersão dos dados. No caso foi escolhido 3 vizinhos que gerou uma ótima escolha. Contudo, menos vizinhos deixa mais sensível à outliers e menos robusto. É uma boa prática testar diferentes parâmetros de vizinhos em bases grandes.

É possível perceber que existe um ponto azul ainda mais próximo que os vizinhos (pontos pretos). Isso é só uma questão de escala e a forma como a distância euclidiana trabalha, que não será aprofundado aqui.

### Imputação para grande escala de dados

```python
import pandas as pd
import numpy as np
from sklearn.impute import SimpleImputer, KNNImputer, IterativeImputer
from sklearn.metrics import mean_absolute_error
```

Agora vamos pensar em grandes dados. Como dito, existem os métodos que utilizaremos para calcular os dados faltantes, tais como:

<table><thead><tr><th width="189">Nome do método</th><th>Como funciona</th></tr></thead><tbody><tr><td><code>SimpleImputer</code></td><td>Substitui o valor faltante usando uma medida simples (média, mediana ou moda) da coluna.</td></tr><tr><td><code>IterativeImputer</code></td><td>Faz imputação <strong>multivariada</strong>, modelando a coluna faltante como uma função das outras colunas (ex: regressão iterativa).</td></tr><tr><td><code>KNNImputer</code></td><td>Usa os valores dos k vizinhos mais próximos (baseado na distância) para preencher o valor faltante (<strong>exemplo da vizinhança</strong>).</td></tr></tbody></table>

#### Ideia de uso

Definir o imputador `imp` com `fit`, que recebe uma função que <mark style="color:blue;">aprende e descobre</mark> quais serão os valores dos dados imputados. Depois, gerar os resultados preenchidos `out` com `transform`, que guarda os valores encontrados (ainda não atualiza o dataframe antigo).

```python
# Exemplo de imp com 3 métodos de imputação
imp = SimpleImputer(strategy='mean')
imp = IterativeImputer(max_iter=10)
imp = KNNImputer(n_neighbors=5)
```

```python
# Exemplo de out desses métodos. Dataframe de dados chamado "dados"
out = imp.transform(dados)

# Inserindo os dados nulos de volta nesse dataframe original, levando em conta que
# idx_alc e idx_pro são os índices das posições nulas
dados[['coluna_com_nan_1', 'coluna_com_nan_2']] = out[:, [idx_alc, idx_pro]]
```

### KNNImputer

```python
for k in [2, 5, 10]:
    imp = KNNImputer(n_neighbors=k)
    imp.fit(df_wine)
    
    out = imp.transform(sample_missing)
    
    mae_alc = mean_absolute_error(y_true_alc, out[:, sample_missing.columns.get_loc('alcohol')])
    mae_pro = mean_absolute_error(y_true_prol, out[:, sample_missing.columns.get_loc('proline')])
    
    results.append(('KNNImputer', f'n_neighbors={k}', mae_alc, mae_pro))

```

### SimpleImputer

```python
results = []

for strategy in ['mean', 'median', 'most_frequent']:
    imp = SimpleImputer(strategy=strategy)
    imp.fit(df_wine[['alcohol', 'proline']])
    
    out = sample_missing.copy()
    out[['alcohol', 'proline']] = imp.transform(out[['alcohol', 'proline']])
    
    mae_alc = mean_absolute_error(y_true_alc, out['alcohol'].values)
    mae_pro = mean_absolute_error(y_true_prol, out['proline'].values)
    
    results.append(('SimpleImputer', f'strategy={strategy}', mae_alc, mae_pro))
```

### IterativeImputer

```python
for it in [5, 10]:
    imp = IterativeImputer(max_iter=it, random_state=0)
    imp.fit(df_wine)
    
    out = imp.transform(sample_missing)
    
    mae_alc = mean_absolute_error(y_true_alc, out[:, sample_missing.columns.get_loc('alcohol')])
    mae_pro = mean_absolute_error(y_true_prol, out[:, sample_missing.columns.get_loc('proline')])
    
    results.append(('IterativeImputer', f'max_iter={it}', mae_alc, mae_pro))

```

[^1]: Todas elas, como média, mediana, percentil, desvio, etc.

[^2]: Não quer dizer que o método acima seja ruim, ele pode ser muito útil quando a distribuição de dados é simétrica.
