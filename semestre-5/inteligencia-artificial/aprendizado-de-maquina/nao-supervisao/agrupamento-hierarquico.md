# Agrupamento hierárquico

Enquanto o agrupamento particional quebra os dados em grupos diretamente, o hierárquico cria uma estrutura em árvore para visualizar agrupamento em vários níveis.

Exemplo disso poderia ser divisão de estilos de música, onde um grupo chamado Rock possui vários subgrupos como Rock Clássico, Hard Rock, Punk, etc. Cada música pertence a apenas uma categoria dessas.

Tem como <mark style="color:green;">vantagem</mark> não precisar conhecer a quantidade de grupos e também detectar facilmente outliers.

#### Aglomerativo versus decisivo

São duas maneiras de fazer o agrupamento:

* Aglomerativo: ou bottom-up, onde começamos com um grupo para cada amostra  &#x20;e vamos juntando grupos até termos um único grupo.
* Divisivo: ou top-down, onde começamos com um único grupo com todas as  &#x20;amostras e vamos dividindo esse grupo até termos grupos unitários (ou  &#x20;singletons).

## Matriz distância

É uma ferramenta usada para <mark style="color:blue;">determinar como os dados serão agrupados</mark>. Além dos agrupamentos, ela também mede **quão próximos ou distantes** os pontos estão uns dos outros.

Montar uma matriz que recebe a distância dos pontos para conseguir montar o agrupamento de dados. Primeiro vamos <mark style="color:blue;">preencher toda a matriz com a distância</mark> que os dados se encontram, baseado neste exemplo:

<figure><img src="../../../../.gitbook/assets/agrup ia - matriz distancia.png" alt=""><figcaption></figcaption></figure>

Teremos uma matriz completamente preenchida desta forma:

<figure><img src="../../../../.gitbook/assets/agrup ia - matriz distancia completa.png" alt=""><figcaption></figcaption></figure>

Para formar um agrupamento, usamos algum [método de Linkage](agrupamento-hierarquico.md#metodos-de-linkage) (que será nosso critério de ligação). Podemos escolher alguma dessas metologias para montar os grupos, neste caso, vamos escolher o Single Linkage que é baseado no ponto mais próximo.

Vamos iniciar pegando o ponto mais próximo, equivalente ao menor valor que existe na tabela. Esse valor está vinculando dois dados, então esses valores formarão um novo grupo (que já podemos desenhar a hierarquia no plano).

<figure><img src="../../../../.gitbook/assets/agrup ia - achar menor ligação.png" alt=""><figcaption></figcaption></figure>

Depois de um novo grupo, a matriz precisa ser refeita. As conexões entre os pontos sem relação com o novo grupo mantem a mesma coisa. Já os outros valores que fazem relação com esse grupo são atualizados com a maior distância dele mesmo com o novo grupo.

Para isso, basta com quem do novo grupo o ponto se conecta. Escolher o maior número, desta forma (exemplo para o ponto `C`):

<figure><img src="../../../../.gitbook/assets/agrup ia - atualizar matriz com nova distancia.png" alt=""><figcaption></figcaption></figure>

Então preenchendo com a maior distância temos a matriz atualizada:

<figure><img src="../../../../.gitbook/assets/agrup ia - como achar nova distancia.png" alt=""><figcaption></figcaption></figure>

E depois todo o processo recomeça aqui. Com a nova matriz atualizada, voltamos para a primeira etapa de resgatar o ponto mais próximo e formar um grupo. Porém agora, ao resgatar a menor distância:

* Se for 2 pontos: cria um novo grupo (separado) na hierarquia.
* Se for um ponto com um grupo: cria uma hierarquia maior.

<figure><img src="../../../../.gitbook/assets/agrup ia - grupo que forma nova hierarquia.png" alt=""><figcaption></figcaption></figure>

E apenas repetindo o processo repetidamente...

<figure><img src="../../../../.gitbook/assets/agrup ia - dois grupos separados no plano.png" alt=""><figcaption></figcaption></figure>

Nesse último caso, onde é a distância de um grupo para outro, o raciocínio segue o mesmo: o ponto mais distante de um dado deste grupo até outro dado do outro grupo, que equivale `(DE)` sendo `43`.

<figure><img src="../../../../.gitbook/assets/agrup ia - finalização do agrupamento.png" alt=""><figcaption></figcaption></figure>

## Métodos de Linkage

Será o método escolhido para fazer o agrupamento de dados na abordagem hierarquica, é uma família de algoritmos.&#x20;

Essa família de algoritmos <mark style="color:green;">não precisa da informação da distribuição&#x20;dos pontos</mark> (como o k-means precisava), mas opera apenas com as distâncias relativas entre as amostras.

<table><thead><tr><th width="167">Método</th><th width="155">Premissa</th><th width="182">Resultado</th><th>Desvantagem</th></tr></thead><tbody><tr><td>Single Linkage (usado no exemplo)</td><td>Une com base na <strong>menor distância.</strong></td><td><strong>Clusters mais alongados</strong> e pode formar "cadeias" de pontos.</td><td>Sensível a outliers.</td></tr><tr><td>Complete Linkage</td><td>Une com base na <strong>maior distância.</strong></td><td>Produz <strong>clusters mais compactos e arredondados</strong>.</td><td>Menos sensível a outliers, mas pode quebrar clusters naturais se houver muita variação interna.</td></tr><tr><td>Average Linkage</td><td>Une com base no cálculo da média da distância.</td><td>Agrupamentos geralmente mais naturais.</td><td></td></tr></tbody></table>

<figure><img src="../../../../.gitbook/assets/resultado de linkages.png" alt=""><figcaption></figcaption></figure>

### Bisecting K-Means

O K-Means possui algumas limitações significativas que devem ser consideradas ao aplicá-lo. Um dos principais problemas é a maneira como os centroides são inicialmente selecionados, o que pode impactar consideravelmente o resultado final da análise. Além disso, o algoritmo requer as posições específicas das amostras, o que pode não ser viável em todos os casos. Outra limitação é a tendência do K-Means em formar grupos em formato de globo, o que pode não representar adequadamente a distribuição real dos dados.

Por outro lado, o Bisecting K-Means é uma variação que busca resolver alguns dos problemas associados ao K-Means tradicional. Ele não sofre do "chainning effect", uma situação em que dados que formam uma cadeia ou sequência podem resultar em clusters inadequados.

O metodo bisecting K-Means funciona iterativamente, iniciando com todos os dados agrupados e <mark style="color:blue;">divide o conjunto de dados em partes menores até que o número desejado de clusters seja alcançado</mark>. Isso pode levar a melhores resultados em termos de qualidade dos clusters e pode ser uma abordagem mais robusta em muitos cenários.

<figure><img src="../../../../.gitbook/assets/Bisecting K-Means.png" alt="" width="375"><figcaption></figcaption></figure>
