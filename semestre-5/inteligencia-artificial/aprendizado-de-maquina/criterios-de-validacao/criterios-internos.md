---
description: Ou relativos.
---

# Critérios internos

Os critérios internos avaliam a qualidade dos clusters sem usar rótulos reais (sem padrão-ouro). Eles analisam apenas a estrutura dos dados e os agrupamentos gerados. Os conceitos chaves são:

* Compactação: Quão próximo os elementos estão de outro, dentro de um grupo. Portanto, uma melhor qualidade seria <mark style="color:green;">elementos mais próximos</mark>.
* Separabilidade: Quão distante grupos estão de outros. Portanto, uma melhor qualidade seria <mark style="color:green;">grupos mais distantes</mark>.

Um bom particionamento seria ter alta compactação e alta separabilidade. Nisso, já podemos pensar no <mark style="color:purple;">índice da silhueta</mark> que junta esses conceitos <mark style="color:blue;">avaliando cada ponto</mark> comparando:

* **a**: distância média para os pontos do **mesmo cluster** (coesão)
* **b**: menor distância média para pontos de **outro cluster** (separação)

<figure><img src="../../../../.gitbook/assets/fórmula da silhueta.png" alt=""><figcaption></figcaption></figure>

O índice `s(i)` vai resultar em um valor de -1 até 1, sendo mal agrupado ou perfeitamente agrupado respectivamente. O valor zero indica estar na fronteira do cluster. Repare a necessidade de ter mais de um elemento em um cluster para não haver divisão por zero.

Existe a forma <mark style="color:purple;">Xie-Beni</mark> (outra métrica), que também mede isso. Quanto mais próximo a zero melhor é, pois indica que os grupos estão mais próximos. Ela não tem disponibilidade no sklearn e deve ser implementada manualmente.
