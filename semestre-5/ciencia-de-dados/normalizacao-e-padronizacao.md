# Normalização e padronização

A normalização dos dados podem ser usadas em diversos contextos. Em treinamento de modelos de aprendizagem de máquina, é muito importante normalizar dados antes de aplicar quaiquer técnicas para uma melhor eficiencia.

A normalização é recomendada <mark style="color:blue;">quando os dados não seguem a mesma magnitude</mark> e amplitude. Se uma coluna for um valor em porcentagem e a outra em número inteiro, isso pode pesar muito no algoritmo de distância. Manter os dados na mesma escala vai deixar cálculos mais precisos e não fazer com que uma coluna pese mais que a outra.

## Problema a ser resolvido

Em algoritmos de IA, estamos sempre procurando a distância entre dois dados. Dados que não estão normalizados podem causar valores <mark style="color:orange;">equivocados nesta distância</mark>.

| Análise  | Peso  | Altura |
| -------- | ----- | ------ |
| Pessoa 1 | 50kg  | 52kg   |
| Pessoa2  | 1,60m | 2,00m  |

* Diferença de altura: `2,0-1,6=0,4`. Elevado ao quadrado `0.4²=`<mark style="color:orange;">`0.08`</mark>.
* Diferença de peso: `52-50=2`. Elevado ao quadrado `2²=`<mark style="color:orange;">`4`</mark>.

Veja que a diferença do **peso causou muito mais impacto que a altura**, o que deveria ser o contrário. Nesse exemplo, a altura é o que mais diferencia as pessoas e o peso é muito parecido. Plotando os dados visualmente, podemos ver o porque disso: o dado azul e verde se parecem muito, mas estão dispersados de uma forma que parecem ser diferentes (afetando a distância euclidiana).

<figure><img src="../../.gitbook/assets/dados plotados sem normalização.png" alt=""><figcaption></figcaption></figure>

A segunda imagem mostra eles depois de normalizados. Esse problema afeta muito os algoritmos de classificação de inteligência artificial. Portanto, esse é um processo inicial necessário, principalmente para os algoritmos [KNN](../inteligencia-artificial/aprendizado-de-maquina/supervisao/algoritmos/knn.md) e [Linkage](../inteligencia-artificial/aprendizado-de-maquina/nao-supervisao/agrupamento-hierarquico.md#metodos-de-linkage).

## Solução

Se todos os nossos <mark style="color:blue;">dados estiverem em uma mesma escala</mark>, o impacto causado na avaliação dos dados seria proporcional a diferença entre eles. Portanto, consiste em padronizar todos os dados para uma escalar equivalente e assim eliminamos o problema apresentado acima.

### MinMax

Esse algoritmo coloca o <mark style="color:blue;">maior valor em 1 e o menor valor em zero</mark>, deixando todos os dados dentro desse intervalo. O problema dele é que <mark style="color:red;">outliers vão entrar nessa escala</mark> e achatar os dados, então é bom fazer a remoção de outliers antes de usar essa escala.

Esse método segue uma fórmula, então podemos facilmente fazer de forma bruta a normalização dos dados:

<figure><img src="../../.gitbook/assets/fórmula do minmax.png" alt=""><figcaption></figcaption></figure>

```python
X_std = (X - X.min(axis=0)) / (X.max(axis=0) - X.min(axis=0))
X_scaled = X_std * (max - min) + min
```

### StandartScaler

Transforma os valores deixando a <mark style="color:blue;">média em zero e o desvio padrão em 1</mark>, o que chamamos de distribuição padronizada [z-score](estatistica-descritiva.md#escore-z-1). Essa forma resulta em <mark style="color:green;">outliers não impactarem na normalização</mark> dos dados.

Essa escala vai permitir que encontremos quem são os outliers, devido a [interpretação para o desvio padrão](estatistica-descritiva.md#interpretacao-para-desvio-padrao) visto em estatística descritiva. Aqueles dados fora do intervalo de -3 a 3 são considerados outliers.

Para normalizar, usamos os métodos do **NumPy**, passando como parâmetro um dataframe `df` com as nossas variáveis:

```python
scaler = StandardScaler()             # Cria o objeto para normalização
df_scaled = scaler.fit_transform(df)  # Normaliza os dados
```

Essa normalização dos dados calcula a média e o desvio padrão de cada coluna (com `fit`) e depois aplica a fórmula de normalização (com `transform`).

<figure><img src="../../.gitbook/assets/antes e depois da normalização.png" alt=""><figcaption></figcaption></figure>

#### Exemplo prático com dados diferentes

Vamos supor que nossa base de dados possua colunas de diferentes tipos, como dados financeiros e dados numéricos. Para normalizar, temos que separá-las em diferentes dataframes por conta de terem uma magnitude diferente.

```python
# Separando criando um novo dataframe
X_base = df[['Open', 'High', 'Low']]
X_volume = df[['Volume']]
```

Depois de separado, fazemos o mesmo processo acima. Mas agora como temos dois dataframes, separamos o resultado normalizado:

```python
# Aqui para as primeiras variáveis em X_base, resultando em X_base_scaled
scaler_base = StandardScaler()
X_base_scaled = scaler_base.fit_transform(X_base)

# Aqui para as segundas variáveis em X_volume, resultando em X_vol_scaled
scaler_vol = StandardScaler()
X_vol_scaled = scaler_vol.fit_transform(X_volume)
```

### Observações

Novos valores podem entrar no conjunto de dados depois da normalização, desde que sigam a mesma escala. Se esse valor for menor ou maior, ele fica fora do intervalo de zero e um mas isso não vai afetar, desde que siga a escala.

Isso também quer dizer que podemos ter nossos dados de volta, já que temos os valores mínimos e máximos guardados, podemos recuperar a escala.
