# Agrupamento particional

Esse agrupamento tem o objetivo de encontrar <mark style="color:blue;">grupos relacionados mas distintos</mark>, onde cada amostra precisa ser **obrigatoriamente atribuída a apenas um grupo**. Essa atribuição se chama <mark style="color:purple;">particionamento</mark>.

Exemplo disso poderia ser divisão de estilos de música, onde um grupo chamado Rock possui vários subgrupos como Rock Clássico, Hard Rock, Punk, etc. Cada música pertence a apenas uma categoria dessas.

## Formação de grupos

Para nós humanos, quando os grupos estão sendo mostrados visualmente em um gráfico ou coisa do tipo, identificar padrões e formar grupos pode ser fácil e intuitivo (pois estamos vendo aquilo), mas para os algoritmos não é simples. Algumas dificuldades incluem:

* Como **definir** os grupos de forma matemática?
* Como lidar com **outliers** que podem distorcer os resultados?
* Como lidar com dados que possuem **mais de** [**duas dimensões**](#user-content-fn-1)[^1]?

### **Algoritmo do K-Means**

Tem como objetivo <mark style="color:blue;">ajustar centroides repetidamente</mark> para posições centrais de grupos e minizar o erro. Um <mark style="color:purple;">centroide</mark> representa o <mark style="color:blue;">ponto médio de um grupo dentro de um conjunto de dados</mark>, ou seja, neste algoritmo cada grupo possui um centroide (também chamado de cluster).

Ele inicia fazendo um posicionamento de `k` centroides de forma aleatória e depois ir ajustando eles para próximos a cada iteração. Para descobrir quantos centroides são (ou seja, o número de k), utiliza-se a <mark style="color:purple;">**técnica do joelho**</mark>.

<figure><img src="../../../../.gitbook/assets/Algoritmo do K-Means.png" alt="" width="357"><figcaption></figcaption></figure>

#### Técnica do cotovelo

Utilizado para saber quantos centroides terão, cria-se um gráfico sendo `X` o número de K e `Y` a variância. Conforme o número de K aumenta, o gráfico vai mudando (pois a variância diminui) podendo criar **uma** curva mais impactante. Essa curva é chamada da **cotovelo**.

Como nem toda mudança de K cria um cotovelo, é possível ver que o gráfico não tem tanta variação assim a partir de um certo ponto, virando quase uma linha contínua. Precisamos analisar o gráfico e encontrar o <mark style="color:blue;">melhor ponto que simboliza o cotovelo</mark>. Veja o exemplo:

<figure><img src="../../../../.gitbook/assets/image.png" alt="" width="563"><figcaption></figcaption></figure>

<mark style="color:green;">A quantidade de centroides que a amostra terá será a posição do eixo x que se encontra o cotovelo</mark>. Nesse exemplo, a melhor opção foi circulada e ela se encontra no `eixo x = 3`. Portanto, nessa amostra de dados, devemos ter 3 centroides.

<details>

<summary>Encontrando K na programação</summary>

* Se quiser um método **simples e direto**, use **o método da segunda derivada** (`np.diff`).
* Para **mais precisão automática**, use [**KneeLocator**](https://pypi.org/project/kneed/).
* Se quiser **confirmar a qualidade dos clusters**, use **o índice de Silhueta**.

</details>



### **Erro Quadrático**

O erro quadrático é uma forma de medir a <mark style="color:blue;">qualidade do agrupamento</mark>. Ele é calculado somando **a distância de cada ponto ao seu centróide** e elevando esse valor [ao quadrado](#user-content-fn-2)[^2].

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

[^1]: Cada aspecto deste dado é uma <mark style="color:purple;">dimensão</mark>, como nome, idade, salário, etc. Se temos mais de dois aspectos, isso quer dizer que é mais do que bidimensional, o que implica que não pode ser mais representado em um plano cartesiano.



    Os agrupamentos precisam levar todas as dimensões em consideração.

[^2]: Elevar ao quadrado enfatiza os erros maiores, garantindo que pequenas mudanças na posição dos centroides tenham um impacto significativo.
