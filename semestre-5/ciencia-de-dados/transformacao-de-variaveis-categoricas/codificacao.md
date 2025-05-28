# Codificação

A codificação é sobre transformar variáveis de texto (variáveis categóricas) para números, pois <mark style="color:red;">modelos de machine learning não entendem textos</mark>, causando erro no código. A codificação correta é muito importante para não afetar algoritmos que usam medidas de distância como o KNN. O dado textual é substituído por um número que o vai representar, podendo usar algumas metodologias para isso.

## Label Encoding

Converte cada categoria em um número inteiro, por exemplo: `vermelho=0`, `azul=1`, `amarelo=2`. Isso é interessante apenas se essa categoria trata-se de [variáveis ordinais](#user-content-fn-1)[^1], pois caso contrário, poderá <mark style="color:orange;">enganar o algoritmo de distância</mark>. Ele engana pois o 2 está mais distante que o 1, mas não necessariamente deveria ser assim.

Se os nossos dados são uma ordem ordinal (tipo ensino médio, graduação, pós, etc), eles são substituídos por uma ordem numérica, ou seja, respectivamente 1, 2 e 3. Isso faz mais sentido e não engana o algoritmo.

<details>

<summary>Exemplo prático</summary>

```python
from sklearn.preprocessing import LabelEncoder

data = ['oliveira', 'coqueiro', 'cerejeira']
encoder = LabelEncoder()

result = encoder.fit_transform(data) # [2 0 1]
```

</details>

## One-Hot Enconding

É ideal para algoritmos de distância e <mark style="color:blue;">evita a imposição de uma ordem</mark> (portanto, não usar quando trata-se de variáveis ordinais). Ele funciona criando uma coluna para cada tipo de categoria[^2] encontrada e o valor dessa coluna sendo um binário, para definir se é ou não é.

<figure><img src="../../../.gitbook/assets/one hot encoding.png" alt=""><figcaption></figcaption></figure>

<details>

<summary>Exemplo prático</summary>

```python
from sklearn.preprocessing import OneHotEncoder
import pandas as pd

ohe = OneHotEncoder(sparse_output=False)
onehot_encoded = ohe.fit_transform(df[['coluna_desejada']])

# Retorna um dataframe com os resultados booleanos
df_onehot_sklearn = pd.DataFrame(
    onehot_encoded,
    columns=ohe.get_feature_names_out(['coluna_desejada'])
)
```

</details>

Como isso faz a criação de novas colunas, se temos 100 tipos de categorias teremos 100 novas colunas. Isso vai exigir espaço e processamento. Portanto, se essa situação ocorrer, deve-se pensar em usar outro método. Essa alta dimensionalidade também pode causar [overfitting](../../inteligencia-artificial/aprendizado-de-maquina/supervisao/algoritmos/regressao-linear.md#overfitting) em modelos que não lidam bem com isso, como regressão linear e KNN).

[^1]: Possuem uma sequência ou hierarquia.

[^2]: É o valor da coluna, como no exemplo: oliveira, coqueiro e cerejeira.
