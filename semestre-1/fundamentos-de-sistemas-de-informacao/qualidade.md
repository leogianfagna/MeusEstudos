# Qualidade

## Métricas de qualidade

Valores e métodos usados para medir a qualidade de um software.

A qualidade pode ser separa por dois externos:

* Externos: aquilo que o usuário percebe ou reporta
* Internos:podem ser medidos pelos programadores

### Fan-in e Fan-out

Ambos esses termos são usados para determinar métricas e conseguir medir uma qualidade em uma lógica ou em um softare. São eles:

* Fan-out: <mark style="color:blue;">**setas saindo**</mark>; simbolizam o número de funções que uma dada função chama. Valor alto <mark style="color:red;">**significa complexidade**</mark> na função, pois começa a embolar.
* Fan-in: <mark style="color:blue;">**setas entrando**</mark>; número de vezes que essa função é chamada por outra. Valor alto <mark style="color:red;">**significa impacto**</mark> na mudança.

Portanto, para checar a função mais complexa, é apenas verificar qual possui o maior valor fan-out. Quando há uma função com inúmeros fan-out, a melhoria seria reestruturar para que essas funções que estão sendo chamadas, chamem outras funções também ao invés de apenas uma chamar todas.&#x20;

### Acoplamento

Acoplamento corresponde ao grau de <mark style="color:blue;">**interdependência entre dois componentes**</mark> de um software. Quando há um baixo acoplamento, um componente consegue operar de forma praticamente independente do outro. Alto acoplamento já implica em uma conexão forte entre os dois, que pode torná-los até indistinguíveis.

Quanto maior o nível de acoplamento, pior. Isso pois está muito ligado com a coesão, quanto maior o acoplamento simboliza menor coesão.

<figure><img src="../../.gitbook/assets/image (4).png" alt=""><figcaption></figcaption></figure>

### McCabe

É uma métrica usada para medir a complexidade de um programa (classe, método, rotina etc). Ela indica a dificuldade de se construir testes de unidade em um determinado código uma vez que ela mede a <mark style="color:blue;">**quantidade de caminhos linearmente independentes**</mark> neste código.

<figure><img src="../../.gitbook/assets/image (2) (1).png" alt=""><figcaption></figcaption></figure>



Essa métrica possui uma fórmula que resulta em um número. A fórmula usa a quantia de elementos acima para chegar em seu resultado e pode ser representada por (respectivamente: a complexidade do programa é igual ao número de arestas menos o número de grafos somado com duas vezes o número de regiões):

$$
V(G)=E−N+2P
$$

#### Exemplos básicos de fluxos

Vemos abaixo um exemplo prático, onde começa na primeira linha e depois abre condições. No caso do **IF/ELSE** abre um fluxo para cada lado, cada lado simbolizando ou o IF ou o ELSE. É importante saber que o <mark style="color:orange;">**IF é representado para a DIREITA**</mark> e o <mark style="color:purple;">**ELSE para a ESQUERDA**</mark>.

<figure><img src="../../.gitbook/assets/image (3) (1).png" alt=""><figcaption></figcaption></figure>

É importante lembrar que existe a possibilidade da <mark style="color:red;">**inexistência do ELSE**</mark>. Sendo apenas com IF, não há dois lados para ir e apenas uma linha única com uma ramificação, por exemplo:

<figure><img src="../../.gitbook/assets/image (4) (1).png" alt=""><figcaption></figcaption></figure>

Mesmo sem a existência do ELSE, como regra, o IF ainda sim é representado para a direita. Dentro dos círculos, em um exemplo foi escrito apenas o "IF" e em outro foi escrito as etapas, como "1" e "2".

#### Exemplo de fluxo com return em condições

Vamos supor que o programa possa se encerrar dentro de uma condição, em vez de passar por todas as etapas primeiro. A representação disso é bem fácil, como um **círculo que simboliza o status final do programa**. Então, se em alguma condição o programa finalizar com um return, puxa uma seta desse estado ligando até o estado final, e assim simbolizamos seu fim. Por exemplo:

<figure><img src="../../.gitbook/assets/image (8).png" alt=""><figcaption></figcaption></figure>



#### Lógica composta

A lógica composta simboliza quando temos mais de uma condição, um caso desse tipo:

```python
# Exemplo usando duas condições em um IF, mas poderia ser em WHILE

if [condiçãoUm] and [condiçãoDois] and [condiçãoTrês]:
 # ...

if [condiçãoUm] or [condiçãoDois] or [condiçãoTrês]:
 # ...
```

<mark style="color:orange;">**Apenas logicamente falando**</mark>, em uma linha de programação, passa primeira pela <mark style="color:purple;">**condiçãoUm**</mark> e a partir daí tem dois caminhos:

* Em casos de AND:
  * Se condiz: segue para a <mark style="color:purple;">**condiçãoDois**</mark> e assim sucessivamente
  * Se falso: já sai daquele IF ali mesmo
* Em casos de OR:
  * Se condiz: já entra direto na lógica do IF e não confere o restante
  * Se falso: confere a <mark style="color:purple;">**condiçãoDois**</mark> e sucessivamente até encontar um resultado verdadeiro ou não encontrar nenhum

Portanto, se temos duas ou mais condições, precisamos fazer a representação de cada uma delas no fluxo. E é necessário ver essa diferença entre o <mark style="color:red;">**AND**</mark> e o <mark style="color:red;">**OR**</mark>, já que o <mark style="color:red;">AND</mark> vai procurar por todas as condições verdadeiras enquanto o <mark style="color:red;">OR</mark> já sai logo na primeira oportunidade que satisfaça.

A representação disso é usando um nó para cada condição e puxando duas saídas de cada nó: uma em caso de verdadeira e outra em caso de falso. Para cada condição, ir colocando o nó em cadeia. Lembrando que sempre teremos duas opções fora a linha da condição: o código dentro do IF e o código depois do IF (que também pode ser um ELSE).

Também é legal representar com V e F as possíveis saídas para melhorar a visibilidade e ficar mais fácil de fazer, da seguinte forma:

<figure><img src="../../.gitbook/assets/image (1).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/image (2).png" alt=""><figcaption></figcaption></figure>



#### Exemplos grandes guiados

Vamos basear em um seguinte código:

<figure><img src="../../.gitbook/assets/image (9).png" alt=""><figcaption></figcaption></figure>

Cada etapa foi numerada e veja abaixo como deve ser representada cada etapa:

1. Apenas uma representação única por se tratar de declarações de variáveis
2. Tanto as condições quando os repetidores ainda seguem a linha única. Nesse caso, a região dois segue em PARALELO a linha principal. Como existe aqui uma condição, essa etapa pode ter uma seta simbolizando a saída caso a região não seja cumprida
3. Temos uma segunda condição e por isso é necessário representar, já que talvez a primeira satisfaça mas a segunda não. Então, pode haver uma seta saindo da etapa 3 caso essa condição não seja realizada
4. Essa etapa é a linha principal de lógica e codificação, ela segue alinhada logo com a terceira. Essas linhas de codificações são simbolizadas. Um exemplo é a declaração de variáveis na primeira etapa

Até o momento, podemos ter esse diagrama:

<figure><img src="../../.gitbook/assets/image (11).png" alt=""><figcaption></figcaption></figure>

A partir daqui temos nosso primeiro IF, neste caso, se há uma lógica dentro de um IF, uma das setas começa a ser puxada para a difeita. Continuando então temos:

5. Novamente representa uma condição. Então segue a linha em paralelo e vai ter uma saída
6. É a segunda condição do IF, então segue a mesma lógica
7. É a linha lógica de código representante caso a condição do IF seja satisfeita. Baseado no conteúdo, esse método é representado fora da linha paralela no lado direito
8. Representa o que acontece em seguida do IF. Nesse caso, não tem nenhum código, mas logicamente tudo que sai do IF (seja por não satisfazer a condição ou por terminar a lógica acima) irá passar por ele, então deve existir
9. Representa o fim do WHILE. Como representado nos diagramas acimas, o fim do WHILE é representado para receber uma seta que aponta para o início dele, indicando que é uma repetição de código até a condição ser realiza

E assim, essa lógica passa a ficar dessa maneira:

<figure><img src="../../.gitbook/assets/image (12).png" alt=""><figcaption></figcaption></figure>

Para finalizar, ainda temos uma lógica IF/ELSE após esse WHILE que finaliza o nosso sistema. Continuando:

10. Representa a condição de um IF, como tem apenas uma condição, é apenas uma simbolização
11. É a lógica caso a condição do IF seja verdadeira, que é puxada sempre para a direita
12. É a lógica caso a condição do IF seja falsa, que é puxada sempre para a esquerda
13. Fim do sistema, é um print apenas

Finalizando o sistema total, então temos:

<figure><img src="../../.gitbook/assets/image (13).png" alt=""><figcaption></figcaption></figure>

#### Cálculo de regiões

Regiões são áreas do código que são executadas em conjunto sem bifurcações internas. São aquelas sequências de comandos executadas de forma linear, sem desvios de fluxo, portanto, <mark style="color:green;">**cada desvio de fluxo determina uma nova região**</mark>. Essas regiões indicam a complexidade e estrutura do programa. Curiosamente, áreas com mais regiões simbolizam mais facilidade de testar.

Para calcular o número de regiões (ou componentes conexos), precisamos já ter o gráfico construído. Depois identificamos os nós de decisão: eles são as bolinhas. Nós de decisão são aqueles que puxam setas fora da direção linear, ou seja, há uma bifurcação (IF, WHILE, SWITCH)

A região será demarcada do primeiro desvio de fluxo a partir do nó encontrado até um nó que o fluxo volta ao normal. Aqui está um exemplo:

<figure><img src="../../.gitbook/assets/image (3).png" alt=""><figcaption></figcaption></figure>

