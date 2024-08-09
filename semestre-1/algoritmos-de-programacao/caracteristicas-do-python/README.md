# Características do Python

Essa página citará características típicas da linguagem Python a respeito de métodos, operações, etc presentes e comuns em quaisquer linguagens de programação, como tipos, operadores, repetições, entre outras. Características comuns como identação, resto de divisão, etc, que são iguais em outras linguagens não serão citadas.

## Características mais importantes

Em Python, não precisamos declarar explicitamente o tipo de uma variável e nem adicionar um identificar de variável antes, como estamos acostumados em diversas linguagens. Em vez disso, Python é uma linguagem de <mark style="color:orange;">tipagem dinâmica</mark>, o que significa que o tipo da variável é determinado automaticamente no momento em que você atribui um valor a ela.

Isso também implica que ele vai entender o tipo da variável por inferência (como em Kotlin) mas também podemos mudar o tipo dela sem nenhum problema. Uma variável que era string pode receber um int e mudar o tipo dela.

A criação de uma nova variável atenta-se apenas em atribuir um valor a ela. Não podemos tentar usar alguma variável que nunca foi atribuída um valor antes, por exemplo:

```python
x = 5 # Nova variável criada

print(x) # 5
print(y) # Erro
```
