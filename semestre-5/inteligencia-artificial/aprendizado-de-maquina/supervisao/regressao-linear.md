# Regressão linear

## O que é regressão linear

É uma <mark style="color:blue;">reta que demonstra uma correlação entre as variáveis</mark>, podendo ser usada para descobrir o padrão de relacionamento entre elas e fazer previsões de pontos futuros. Portanto, matematicamente a fórmula da reta possui dois coeficientes.

A melhor reta traçada é aquela que está mais próximos aos pontos, isso matematicamente significa o <mark style="color:blue;">menor erro quadrático</mark>. A margem de erro desta reta é a distância do ponto até ela. Então ficar movendo a reta, vai mudar essa distância e consequentemente mudar o erro quadrático. <mark style="color:blue;">Minimizar o erro quadrático é a forma de aproximar a reta de todos os pontos</mark> de maneira “mais” igual.

<figure><img src="../../../../.gitbook/assets/regressão linear.png" alt="" width="563"><figcaption></figcaption></figure>

Veja que, se movermos a reta vermelha um pouco mais abaixo, ela se aproxima dos pontos inferiores e se distancia dos pontos superiores. A distância simples entre os pontos se mantém a mesma, mas é por isso que usamos o erro quadrático (essa distância elevado ao quadrado).

## Quando utilizar

Usamos quando temos uma <mark style="color:blue;">correlação aproximadamente linear entre duas variáveis</mark>: a variável dependente[^1] Y e a independente X. Além disso, há outras orientações para o uso:

* A variável dependente deve ser contínua (não categórica ou discreta).
* Para modelos simples e interpretáveis.
* Quando não há outliers pois a reta é sensível à eles.

Não podemos utilizar quando <mark style="color:red;">variáveis independentes estão altamente correlacionadas</mark>. Mas caso elas estejam, podemos retrabalhar neste dados para criar uma <mark style="color:purple;">razão entre elas</mark>, isto é, criar uma nova variável que equivale pelas duas. Para isso, podemosusar o PCA, redução de dimensionalidade, etc.

## Overfitting

Se a reta puder fazer curva (overfitting), a predição dela é perfeita pois assim passaria por todos os pontos. Mas uma reta ondulada não condiz muito com a realidade, fazendo com que uma reta preveja o mundo real melhor. Por quê?

Pois a reta ondulada ela apenas <mark style="color:orange;">decorou</mark> por onde passam os pontos, enquanto a reta normal <mark style="color:green;">aprendeu</mark> o seu comportamento. Na hora de tentar prever, quem decorou não vai conseguir a menos que seja copiar e colar o que já tinha, criando uma previsão péssima e ineficáz.

Metaforicamente, esse é o conceito de estudar para uma prova. Quem decorou respostas do gabarito, não consegue desenvolver uma questão se ela for diferente e quem aprendeu consegue.

### Modelo viciado

Esse conceito de decorar os pontos com overfitting cria um modelo viciado.&#x20;

* Esse conceito é interessante para testar o “Treino-teste”, para saber se ele está viciado.
* Validação cruzada.
* Leave one out.

[^1]: É sobre aquele assunto de que, o preço da casa está fortemente correlacionado a área da casa.
