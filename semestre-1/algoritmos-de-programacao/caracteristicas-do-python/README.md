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

## Comportamento da variável em repetição

Quando temos uma repetição do tipo for, a variável que percorre se atribui o valor do elemento da vez, em vez de ser um contador. Isso é muito importante e causa muitas mudanças no código, [veja aqui](../pratico/repeticoes.md#comportamento-do-contador).

## Padrão de escrita

Os padrões de escrita mudam um pouco se comparado com outras linguagens de programação:

* Declaração de <mark style="color:purple;">variáveis</mark> (inclui listas e dicionários) e <mark style="color:purple;">funções</mark>: snake\_case
  * Palavras separadas por underlines
  * Todas as letras minúsculas
  * Ex: `minha_variavel`
* Declaração de classes: PascalCase
  * Iniciais em maíusculas
  * Ex: `MinhaClasse`
