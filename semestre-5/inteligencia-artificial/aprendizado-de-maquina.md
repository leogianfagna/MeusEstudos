# Aprendizado de máquina

## Tarefa supervisionada

No aprendizado de máquina supervisionado, os algoritmos são treinados para <mark style="color:blue;">**reconhecer padrões**</mark> com base em dados rotulados, ou seja, onde **já sabemos as respostas corretas**. O modelo aprende a prever corretamente novos exemplos a partir do erro cometido nos exemplos anteriores. Isso significa que ele passa por um processo de **acerto e erro**, ajustando-se gradualmente para melhorar seu desempenho.

## Aprendizado não supervisionado

Existem situações onde **os dados não são rotulados**. Nesses casos, utilizamos técnicas de aprendizado não supervisionado, que buscam estruturar os dados de maneira útil **sem conhecer as respostas corretas previamente**.

Os dados não rotulados podem ser analisados e organizados por diferentes métodos, incluindo:

* **Visualização**: Antes de aplicar qualquer algoritmo, é útil visualizar os dados, especialmente se for possível representá-los em gráficos. Essa etapa ajuda a identificar padrões, tendências e possíveis agrupamentos.
* **Detecção de Outliers**: São elementos que não seguem o comportamento geral dos dados e podem indicar erros, anomalias ou exceções.
* **Agrupamento (Clustering)**: Técnica que divide os dados em grupos semelhantes. Existem vários métodos de agrupamento, sendo um dos mais comuns o **agrupamento particional**.
* **Regras de Associação**: Buscam identificar padrões de associação entre diferentes elementos nos dados, como ocorre no mercado com a identificação de produtos frequentemente comprados juntos.

## **Agrupamento Particional**

Esse agrupamento tem o objetivo de encontrar <mark style="color:blue;">grupos relacionados mas distintos</mark>, onde cada amostra pertence **obrigatoriamente a apenas um grupo**.

Exemplo disso poderia ser divisão de estilos de música, onde um grupo chamado Rock possui vários subgrupos como Rock Clássico, Hard Rock, Punk, etc. Cada música pertence a apenas uma categoria dessas.

### Formação de grupos

Para nós humanos, quando os grupos estão sendo mostrados visualmente em um gráfico ou coisa do tipo, identificar padrões e formar grupos pode ser fácil e intuitivo (pois estamos vendo aquilo), mas para os algoritmos não é simples. Algumas dificuldades incluem:

* Como definir os grupos de forma matemática?
* Como lidar com **outliers** que podem distorcer os resultados?
* Como lidar com dados que possuem **mais de duas dimensões**?

### Dimensões de um dado

Um dado possui uma característica chamada dimensão. Cada aspecto deste dado é uma dimensão, como nome, idade, salário, etc. Se temos mais de dois aspectos, isso quer dizer que é mais do que bidimensional, o que implica que não pode ser mais representado em um plano cartesiano.

Os agrupamentos precisam levar todas as dimensões em consideração.

### **Centróide**

Representa o <mark style="color:blue;">ponto médio de um grupo dentro de um conjunto de dados</mark>. No algoritmo <mark style="color:purple;">K-Means</mark>, por exemplo, cada grupo tem um centróide, e os pontos são atribuídos ao grupo cujo centróide está mais próximo. O objetivo do algoritmo é **ajustar a posição dos centroides para minimizar o erro**.

### **Erro Quadrático**

O erro quadrático é uma forma de medir a <mark style="color:blue;">qualidade do agrupamento</mark>. Ele é calculado somando **a distância de cada ponto ao seu centróide** e elevando esse valor [ao quadrado](#user-content-fn-1)[^1].

Se o erro quadrático for zero, significa que todos os pontos do cluster estão exatamente no mesmo local (caso raro na prática). Quanto **menor** o erro quadrático, melhor o agrupamento.

### **Entendendo o Funcionamento do K-Means**

O **K-Means** é um dos algoritmos mais populares para agrupamento particional e segue estes passos:

1. Escolher um valor para `k` (quantidade de clusters).
2. Selecionar aleatoriamente `k` centroides iniciais.
3. Atribuir cada ponto ao centróide mais próximo.
4. Atualizar os centroides recalculando a posição média dos pontos em cada grupo.
5. Repetir os passos 3 e 4 até a convergência (quando os centroides não mudam mais significativamente).

Este processo pode ser influenciado por diferentes inicializações, e algumas variações do algoritmo, como o **K-Means++**, ajudam a melhorar a escolha inicial dos centroides para evitar problemas.

### Escolher quantidade de grupos

Um dos desafios do <mark style="color:purple;">K-Means</mark> é escolher o número ideal de clusters `k`. Para isso, uma técnica comum é o **método do cotovelo (elbow method)**:

1. Executamos o algoritmo para diferentes valores de `k` (por exemplo, de 1 a 10).
2. Calculamos o erro quadrático para cada `k`.
3. Plotamos um gráfico, onde o eixo X representa `k` e o eixo Y representa o <mark style="color:purple;">erro quadrático</mark>.
4. O ponto onde a curva "dobra" como um **cotovelo** indica um valor adequado de `k`.

Esse método ajuda a evitar escolher um número muito baixo (clusters grandes e genéricos) ou muito alto (clusters pequenos e muito específicos).

### **Conclusão**

O aprendizado supervisionado é essencial para modelos que aprendem a partir de **acertos e erros**, enquanto o aprendizado não supervisionado busca estruturar os dados sem rótulos pré-definidos. No contexto de agrupamento, o **K-Means** e suas variações são amplamente utilizados para **descobrir padrões ocultos** em conjuntos de dados de múltiplas dimensões.

A escolha de **k clusters** e o cálculo do **erro quadrático** são fatores críticos para garantir que os grupos identificados sejam coerentes e úteis. Métodos como **o cotovelo (elbow method)** auxiliam nessa escolha, e a inicialização dos centroides pode impactar significativamente os resultados.

[^1]: Elevar ao quadrado enfatiza os erros maiores, garantindo que pequenas mudanças na posição dos centroides tenham um impacto significativo.
