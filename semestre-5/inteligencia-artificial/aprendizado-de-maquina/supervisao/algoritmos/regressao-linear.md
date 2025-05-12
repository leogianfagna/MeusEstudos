# Regressão linear

## O que é regressão linear

É uma <mark style="color:blue;">reta que demonstra uma correlação entre as variáveis</mark> de um conjunto de dados, podendo ser usada para descobrir o padrão de relacionamento entre elas e fazer previsões de pontos futuros. Portanto, matematicamente a fórmula da reta possui **dois coeficientes**.

### Quem são as variáveis

O primeiro coeficiente é o rótulo, aquele que queremos descobrir e o segundo coeficiente é a variável que compõe a base de dados. Pode ser apenas uma única variável ou um conjunto de colunas que juntas vão formar o coeficiente como um todo.

<figure><img src="../../../../../.gitbook/assets/colunas como coeficientes.png" alt=""><figcaption></figcaption></figure>

Isso quer dizer que a **fórmula da regressão linear** é o **`Close`** (coeficiente dependente) como função de `Open`, `High` e `Low` (coeficientes independentes, são os features).

Essa fórmula gera um resultado e ele equivale aos <mark style="color:purple;">pontos no plano cartesiano</mark>. Então os pontinhos que estamos vendo nas imagens abaixo, são os resultados da fórmula. Por isso as variáveis independentes acabam se "fundindo".

## Traçar retas

A melhor reta traçada é aquela que está mais próximos aos pontos, isso matematicamente significa o <mark style="color:blue;">menor erro quadrático</mark>. A margem de erro desta reta é a distância do ponto até ela. Então ficar movendo a reta, vai mudar essa distância e consequentemente mudar o erro quadrático. <mark style="color:blue;">Minimizar o erro quadrático é a forma de aproximar a reta de todos os pontos</mark> de maneira “mais” igual.

<figure><img src="../../../../../.gitbook/assets/regressão linear.png" alt="" width="563"><figcaption></figcaption></figure>

Veja que, se movermos a reta vermelha um pouco mais abaixo, ela se aproxima dos pontos inferiores e se distancia dos pontos superiores. A distância simples entre os pontos se mantém a mesma, mas é por isso que usamos o erro quadrático (essa distância elevado ao quadrado).

## Quando utilizar

Usamos quando temos uma <mark style="color:blue;">correlação aproximadamente linear entre duas variáveis</mark>: a variável dependente[^1] Y e a independente X. Além disso, há outras orientações para o uso:

* A variável dependente deve ser contínua (não categórica ou discreta).
* Para modelos simples e interpretáveis.
* Quando não há outliers pois a reta é sensível à eles.

Não podemos utilizar quando <mark style="color:red;">variáveis independentes estão altamente correlacionadas</mark>. Mas caso elas estejam, podemos retrabalhar neste dados para criar uma <mark style="color:purple;">razão entre elas</mark>, isto é, criar uma nova variável que equivale pelas duas. Para isso, podemos usar o PCA, redução de dimensionalidade, etc.

## Overfitting

Se a reta puder fazer curva (overfitting), a predição dela é perfeita pois assim passaria por todos os pontos. Mas uma reta ondulada não condiz muito com a realidade, fazendo com que uma reta preveja o mundo real melhor. Por quê?

Pois a reta ondulada ela apenas <mark style="color:orange;">decorou</mark> por onde passam os pontos, enquanto a reta normal <mark style="color:green;">aprendeu</mark> o seu comportamento. Na hora de tentar prever, quem decorou não vai conseguir a menos que seja copiar e colar o que já tinha, criando uma previsão péssima e ineficáz.

Metaforicamente, esse é o conceito de estudar para uma prova. Quem decorou respostas do gabarito, não consegue desenvolver uma questão se ela for diferente e quem aprendeu consegue.

<figure><img src="../../../../../.gitbook/assets/overfiting em regressão linear.png" alt=""><figcaption></figcaption></figure>

### Modelo viciado

Esse conceito de decorar os pontos com overfitting cria um modelo viciado.&#x20;

* Esse conceito é interessante para testar o “Treino-teste”, para saber se ele está viciado.
* Validação cruzada.
* Leave one out.

## Gradiente descendente

É um algoritmo de otimização usado para encontrar os **valores ideais dos coeficientes** (ou pesos) do modelo de regressão linear, minimizando o **erro** entre as previsões do modelo e os valores reais. O erro faz um formato de parábola e consequentemente existe o menor ponto dessa curva:

<figure><img src="../../../../../.gitbook/assets/image (3).png" alt="" width="353"><figcaption></figcaption></figure>

Para encontrar o ponto com o menor erro, podemos usar o conceito de <mark style="color:purple;">derivada</mark>. A derivada de uma função pode indicar se a função é crescente ou decrescente (em pontos altos da curva) , então, se o resultado da derivada for zero, isso indica que estamos no ponto mínimo e a derivada forma uma reta. Portanto:

* Se o resultado da derivada for negativo: precisamos andar para frente.
* Se o resultado da derivada for positivo: precisamos voltar.
* Se o resultado for zero: estamos no ponto ideal.

<figure><img src="../../../../../.gitbook/assets/image (4).png" alt=""><figcaption></figcaption></figure>



[^1]: É sobre aquele assunto de que, o preço da casa está fortemente correlacionado a área da casa.
