# Supervisão

Aqui temos uma <mark style="color:blue;">supervisão humana</mark>. Tem como objetivo fazer previsões (<mark style="color:purple;">classificações ou predições</mark>), ou melhor, reconhecer padrões com base em [dados rotulados](dados-rotulados.md).

Trabalhamos com a tabela verdade todo o tempo, então sabemos quanto nosso algoritmo está acertando. Isso significa que o processo de acerto e erro ajuda o algoritmo a ajustar-se gradualmente.

<figure><img src="../../../.gitbook/assets/rótulo de um dado.png" alt="" width="563"><figcaption></figcaption></figure>

O treinamento de algoritmo para entender esses padrões se chama tarefa supervisionada. Existem duas abordagens:&#x20;

* Classificação usando [meta discreta](#user-content-fn-1)[^1].
* Predição usando [meta continua](#user-content-fn-2)[^2].

O objetivo é <mark style="color:blue;">transformar dados não rotulados em rotulados</mark>. Para treinar os dados, temos dois algoritmos: KNN e Naive Bayes.

## KNN (K vizinhos mais próximos):

Usa premissa que amostras similares possuem o mesmo rótulo, portanto, vizualiza quem são as amostras mais próximas e rótula a amostra `X` da mesma forma (como se fosse um consenso). Mas tudo isso **depende** de quantos `k` (vizinhos mais próximos) estaremos usando para comparar:

<figure><img src="../../../.gitbook/assets/knn.png" alt="" width="248"><figcaption></figcaption></figure>

* Estamos usando `k = 3`, então a bolinha verde provavelmente será vermelha.
* Mas se `k = 2`, provavelmente a bolinha seria azul por estar ligeiramente mais próxima.
* E se `k = 1` também seria azul pois a bolinha azul é o vizinho mais próximo.

Basicamente, quanto maior o `k`, menor o impacto dos vizinhos mais próximos. Isso também ajuda no fato de que, se os vizinhos mais próximos estavam rotulados de forma errada, aumentar o `k` vai conseguir rotular de forma correta.

Os dados que passaram a ser rotulados não servem como base para rotular novos. Treinar novas amostras (refazer um treino completo) é recomendado apenas quando em média 60% dos nossos dados vieram de dados não rotulados.

### Escolha do k

Através de tentativa e erro até encontrar o melhor valor. Dados rotulados permitem encontrar métricas do tipo acurácia, precisão, etc. Portanto, ao chutar um número de `k`, podemos calcular a acurácia e ver a porcentagem resultante.&#x20;

Se `k = 4` a precisão é de 40%, isso significa que é muito ruim e vamos tentar outro valor até atingir a maior porcentagem possível. O gráfico de k e precisão normalmente faz esse formato, então veja que a partir de um certo ponto, ao aumentar o k a precisão começa a cair, existindo um ponto certo.

<figure><img src="../../../.gitbook/assets/grafico gaussiano.png" alt=""><figcaption></figcaption></figure>

### Pesos na atribuições

O que pode acontecer é entrar em duvida qual rotular. Nisso, existem abordagens de atribuir pesos:

* Ponderação por distância (mais utilizada): Pesos sendo inversamente proporcional à distância.
* O vizinho mais próximo tem peso dois.
* Todos tem o mesmo peso (ou dizer que não há peso).

#### Ponderação por distância

Como dito, os vizinhos mais próximos possuem maior peso daqueles mais distântes. Existe uma fórmula que mede o peso de cada vizinho:

<figure><img src="../../../.gitbook/assets/peso ponderado na distancia.png" alt="" width="563"><figcaption></figcaption></figure>

[^1]: É um possível dado dentro de um conjunto, tipo booleano (é diabético ou não).

[^2]: Dado que pertence a uma classe contínua (visto em estatística), que é um número que pode variar muito.
