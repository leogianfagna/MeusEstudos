# Percorrer elementos

## Através do índice

A forma mais direta para iterar **somente pelos índices** `df.index`:

```python
for idx in df.index:
    print("Índice:", idx)
    print(df.loc[idx])  # acessa a linha inteira
```

## **Usando iterrows** (índice + linha)

Se quiser o índice e os dados da linha juntos podemos usar o método `iterrows()`, contudo, retorna cada linha como uma <mark style="color:orange;">serie</mark>, fazendo com que o acesso de dados seja por `row["coluna"]`.

```python
for idx, row in df.iterrows():
    print("Índice:", idx)
    print("total_price:", row["total_price"])
    print("quantity:", row["quantity"])
```

## **E**stilo tupla

Esse modo é mais rápido (desempenho) e usa estilos **tuplas**, estrutura vista em Python. Veja que cada linha pode ser acessada sendo a coluna um atributo:

```python
for row in df.itertuples():
    print("Índice:", row.Index)
    print("total_price:", row.total_price)
```
