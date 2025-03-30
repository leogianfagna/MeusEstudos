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

Quando já temos um **dataframe criado** e vamos inserir novos dados, que sejam compatíveis com a estrutura atual, podemos usar de forma simples a atribuição com vetor:

```python
dados_em_um_vetor = ["Nome", 34, 1.78]
indice_custom = "AA0"

# Inserir esse vetor como uma nova linha
df.loc[len(df)] = dados_em_um_vetor         # Se índices são numéricos e sequenciais
df.loc[indice_custom] = dados_em_um_vetor   # Se índices são customizados
```

Um índice de um dataframe/serie pode ser um número sequencial ou pode ser um valor customizado, como um ID ou data. A inserção precisa respeitar essa ordem e cada uma das alternativas acima deve ser usada baseada no contexto.

### Método concat

Esse [método ](https://pandas.pydata.org/docs/reference/api/pandas.concat.html)serve para combinar series ou dataframes em um dataframe, chamando de forma estática e não através de uma instância, isso quer dizer que usa-se `pd.concat()`.

```python
varias_series = User.get_user_tickers(username)
df_dividend_history = pd.DataFrame(columns=["date", "value", "ticker"])

for serie in varias_series:
    # Transformar a serie em um df com um dataframe com um elemento a mais
    df = serie.reset_index()
    df.columns = ["date", "value"]
    df["ticker"] = "Novo Elemento em texto"
    
    df_dividend_history = pd.concat([df_dividend_history, df], ignore_index=True)

df_dividend_history = df_dividend_history.sort_values(by="date")
```

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

## Manipulação direta

Tentar alterar elementos por atribuíção pode falhar pelo fato da estrutura retornar uma cópia. Para mudar um dado, precisamos fazer desta forma:

```python
df.loc[index, "nome_coluna"] = "valor"
```
