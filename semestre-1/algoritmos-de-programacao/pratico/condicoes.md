# Condições

A estrutura de seleção em Python (ou condições) segue a seguinte sintaxe:

```python
# Conferir se o quadrado é quadrilátero ou retângulo

lado1 = float(input("Insira o primeiro valor: "))
lado2 = float(input("Insira o primeiro valor: "))

if lado1 != lado2:
    print("Equilátero")
else:
    print("Quadrado")
```

Os comparadores são equivalentes às outras linguagens, usando símbolos do tipo `==`, `!=` , `>=` e outros.

## Seleção múltipla

Estamos falando de duas condições necessárias para entrar na estrutura. Neste caso, simplesmente usamos <mark style="color:green;">`and`</mark> ou <mark style="color:green;">`or`</mark> para simbolizar uma múltipla condição. Neste exemplo abaixo, já é possível ver uma condição dentro de outra condição.

```python
stringUm = input("Insira a primeira string: ")
stringDois = input("Insira a segunda string: ")

if stringUm == "teste" and stringDois == "teste":
    print("Ambos são.")
else:
    if stringUm == "teste" or stringDois == "teste":
        print("Algum dos dois são.")
    else:
        print("Nenhum é.")
```
