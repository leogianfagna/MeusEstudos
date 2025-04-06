# Definição

Existem situações onde **os dados não são rotulados**. Nesses casos, utilizamos técnicas de aprendizado não supervisionado, que buscam estruturar os dados de maneira útil **sem conhecer as respostas corretas previamente**.

Os dados não rotulados podem ser analisados e organizados por diferentes métodos, incluindo:

* **Visualização**: Antes de aplicar qualquer algoritmo, é útil visualizar os dados, especialmente se for possível representá-los em gráficos. Essa etapa ajuda a identificar padrões, tendências e possíveis agrupamentos.
* **Detecção de Outliers**: São elementos que não seguem o comportamento geral dos dados e podem indicar erros, anomalias ou exceções.
* **Agrupamento (Clustering)**: Técnica que divide os dados em grupos semelhantes. Existem vários métodos de agrupamento, sendo um dos mais comuns o **agrupamento particional**.
* **Regras de Associação**: Buscam identificar padrões de associação entre diferentes elementos nos dados, como ocorre no mercado com a identificação de produtos frequentemente comprados juntos.

## Como os dados estão

Os dados que serão trabalhados precisam estar em um [dataframe](../../../ciencia-de-dados/estruturas/dataframes/). Na prática, podem estar desta forma:

```python
from sklearn.datasets import load_iris

iris = load_iris()
all_data = iris.data
df_iris = pd.DataFrame(all_data, columns=iris.feature_names)

if df_iris.isnull().any().any():
    print("Existem valores nulos no dataset.")
else:
    print("Não existem valores nulos no dataset.")
```

Veja a checagem se existem valores nulos. O uso de `any().any()` primeiro confere se existe alguma coluna nula e depois confere se algum valor dessa coluna (que passa a ser uma serie) está nulo.
