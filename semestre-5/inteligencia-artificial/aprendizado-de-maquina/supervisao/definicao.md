# Definição

Uma <mark style="color:blue;">tarefa supervisionada é treinar um algoritmo</mark> para fazer previsões (<mark style="color:purple;">classificações ou predições</mark>), ou melhor, reconhecer padrões com base em [dados rotulados](../dados-rotulados.md). Os dados estarem previamente rotulados por um especialista é uma obrigação, assim sabemos se nosso algoritmo está acertando ou errando, através de uma <mark style="color:blue;">supervisão humana</mark>.&#x20;

* Classificação usando [meta discreta](#user-content-fn-1)[^1].
* Predição usando [meta continua](#user-content-fn-2)[^2].

Ela tem como objetivo encontrar os rótulos de dados ainda não rotulados. Por isso, exige o treinamento prévio em cima dos dados rotulados.

Trabalhamos com a tabela verdade todo o tempo para descobrir o acerto do algoritmo. Isso significa que o processo de acerto e erro ajuda o algoritmo a **ajustar-se gradualmente**.

<figure><img src="../../../../.gitbook/assets/rótulo de um dado.png" alt="" width="563"><figcaption></figcaption></figure>

[^1]: É um possível dado dentro de um conjunto, tipo booleano (é diabético ou não).

[^2]: Dado que pertence a uma classe contínua (visto em estatística), que é um número que pode variar muito.
