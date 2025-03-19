# Criar Dataframes

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
