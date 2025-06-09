# Critérios de validação

Para medir a qualidade de um particionamento podemos seguir duas abordagens.

## Critérios externos

Esse critério funciona <mark style="color:orange;">apenas com dados rotulados</mark> e, como possuímos esses rótulos, podemos encontrar um <mark style="color:purple;">padrão-ouro</mark>, que é uma representação do melhor agrupamento possível que pode ser feito.

Então pegamos o nosso agrupamento e comparamos com esse padrão, para ver se o nosso agrupamento acertou ou errou. Isso é feito dado por dado, por exemplo, conferir se `X` e `Y` formam uma dupla.

### Matriz de confusão

Nisso, juntamos nossos resultados em uma <mark style="color:purple;">matriz de confusão</mark>, que leva algumas variáveis:

* Mesmo grupo no algoritmo e no padrão-ouro: ✅ **True Positive** `TP`
* Grupos diferentes no algoritmo e no padrão-ouro: ✅ **True Negative** `TN`
* Mesmo grupo no algoritmo, grupos diferentes no padrão-ouro: ❌ **False Positive** `FP`
* Grupos diferentes no algoritmo, mesmo grupo no padrão-ouro: ❌ **False Negative** `FN`

A cada ocasião, vai somando para cada variável. Então, se nosso algoritmo acertou a formação de uma dupla, soma +1 para `TP` e assim vai. E então, montamos a nossa matriz:

<figure><img src="../../../../.gitbook/assets/matriz confusão.png" alt="" width="563"><figcaption></figcaption></figure>

Com esses dados prontos, podemos incluir em uma fórmula que melhor se encaixa na nossa situação (existem ainda outras mais complexas):

<table><thead><tr><th width="154">Nome</th><th width="383">Utilização</th><th>Fórmula</th></tr></thead><tbody><tr><td>Precisão</td><td>Mede a relação entre acerto e erro, considerando todos os pares</td><td>a / a + b</td></tr><tr><td>Acurácia</td><td>Mede a relação entre acerto e erro, considerando todos os pares.</td><td>a + d / a + d + b + c</td></tr><tr><td>Sensibilidade</td><td>Mede a capacidade do modelo de identificar corretamente as amostras <a data-footnote-ref href="#user-content-fn-1">positivas</a>.</td><td>a / a + c</td></tr><tr><td>Especificidade</td><td>Mede a capacidade do modelo de identificar corretamente as amostras <a data-footnote-ref href="#user-content-fn-2">negativas</a></td><td>d / d + b</td></tr><tr><td>F1-score</td><td>Média <a data-footnote-ref href="#user-content-fn-3">harmônica</a> entre precisão e sensibilidade</td><td>2 * a / 2 * a + b + c</td></tr></tbody></table>

### Critérios internos/relativo

Os critérios internos avaliam a qualidade dos clusters sem usar rótulos reais (sem padrão-ouro). Eles analisam apenas a estrutura dos dados e os agrupamentos gerados. Os conceitos chaves são:

* Compactação: Quão próximo os elementos estão de outro, dentro de um grupo. Portanto, uma melhor qualidade seria <mark style="color:green;">elementos mais próximos</mark>.
* Separabilidade: Quão distante grupos estão de outros. Portanto, uma melhor qualidade seria <mark style="color:green;">grupos mais distantes</mark>.

Um bom particionamento seria ter alta compactação e alta separabilidade. Nisso, já podemos pensar no <mark style="color:purple;">índice da silhueta</mark> que junta esses conceitos <mark style="color:blue;">avaliando cada ponto</mark> comparando:

* **a**: distância média para os pontos do **mesmo cluster** (coesão)
* **b**: menor distância média para pontos de **outro cluster** (separação)

<figure><img src="../../../../.gitbook/assets/fórmula da silhueta.png" alt=""><figcaption></figcaption></figure>

O índice `s(i)` vai resultar em um valor de -1 até 1, sendo mal agrupado ou perfeitamente agrupado respectivamente. O valor zero indica estar na fronteira do cluster. Repare a necessidade de ter mais de um elemento em um cluster para não haver divisão por zero.

Existe a forma <mark style="color:purple;">Xie-Beni</mark> (outra métrica), que também mede isso. Quanto mais próximo a zero melhor é, pois indica que os grupos estão mais próximos. Ela não tem disponibilidade no sklearn e deve ser implementada manualmente.

[^1]: Útil em problemas onde é mais crítico detectar a classe positiva, como diagnóstico    \
    médico.

[^2]: Essencial quando um falso positivo pode ser problemático (ex: alarme falso de    \
    fraude bancária).

[^3]: É útil quando há um desequilíbrio entre as classes e não queremos favorecer uma    \
    métrica sobre a outra.
