# Criar Dataframes

## Criação básica

Consiste em <mark style="color:blue;">definir as colunas</mark> e terá um dataframe vazio:

```python
df = pd.DataFrame(columns=["Coluna1", "Coluna2", "Coluna3"])
```

## Criar Dataframe de um JSON

Dentro de um JSON, ele pode conter uma estrutura que envolve uma chave. Veja um exemplo com a chave <kbd>nades</kbd>:

<figure><img src="../../../../.gitbook/assets/chaves de um json.png" alt=""><figcaption></figcaption></figure>

#### Se houver chaves

```python
with open("json_file.json", 'r', encoding='utf-8') as arquivo:
    dados = json.load(arquivo)

df = pd.DataFrame(dados['col']) # Sendo "col" o nome da coluna do JSON
```

#### Se não houver chaves

```python
df = pd.read_json("json_file.json")
```

## Inserção de dados

Quando já temos um **dataframe criado** e vamos inserir novos dados, que sejam compatíveis com a estrutura atual, podemos usar de forma simples a atribuição:

```python
dados_em_um_vetor = ["Nome", 34, 1.78]
indice_custom = "AA0"

# Inserir esse vetor como uma nova linha
df.loc[len(df)] = dados_em_um_vetor         # Se índices são numéricos e sequenciais
df.loc[indice_custom] = dados_em_um_vetor   # Se índices são customizados
```

Um índice de um dataframe/serie pode ser um número sequencial ou pode ser um valor customizado, como um ID ou data. A inserção precisa respeitar essa ordem e cada uma das alternativas acima deve ser usada baseada no contexto.

## Acessar elementos

Eles <mark style="color:red;">não podem ser acessados nativamente</mark> apenas definindo o valor de um vetor, como df\[0]. Para isso, temos que usar:

* `iloc` para acessar via posição numérica: `df.iloc[0]`
* `loc` para acessar via o identificador do índice: `df.loc['00A']`
* Qualquer um acima também pode ser combinado em forma de matriz já para pegar um dado isolado, como `df.loc[5, "Coluna A"]`.

Isso resultará na linha com os dados respectivos. Com isso, podemos [especificar a coluna](metodos.md#especificar-coluna) para um dado isolado, por exemplo:

```python
index = df.dividend_date.idxmin()

dados_desse_index = df.loc[index]

# Dados isolados
coluna_ticker = dados_desse_index.ticker
coluna_dividend = dados_desse_index.dividend_date
```
