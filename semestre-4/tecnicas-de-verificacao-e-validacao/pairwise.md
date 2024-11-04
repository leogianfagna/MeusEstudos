# Pairwise

Um sistema com o objetivo de criar um dataset (combinação dos valores) de testes com as opções de <mark style="color:blue;">**valores de entrada**</mark>. Podemos usar virtualmente [neste site](https://pairwise.yuuniworks.com/).

A regra do pairwise é combinar os pares de tal forma <mark style="color:blue;">minimizar a repetição deles</mark>. Nunca terá um teste com dois valores idênticos. Quando o teste tem duas entradas, isso não muda nada, mas a partir de 3 entradas, o número já decai.

<figure><img src="../../.gitbook/assets/pairwise na pratica.png" alt=""><figcaption></figcaption></figure>

Esse exemplo acima mostra na **prática** como funciona. O conjunto `{kg: 70, categoria: 3}` poderia aparecer **3** vezes:

* `{kg: 70, categoria: 3, status: none}`
* `{kg: 70, categoria: 3, status: on}`
* `{kg: 70, categoria: 3, status: off}`

Contudo, aparece uma vez apenas. Isso porque as demais opções são excluídas do pairwise para minimizar essa repetição. Um par de valores, independente de qual junção de colunas, aparecerá apenas uma vez no dataset.

No exemplo prático da aula, de 1530 possibilidades de testes (multiplica pela quantidade de valores de entrada de cada opção), diminuiu para 29 possibilidades de testes.
