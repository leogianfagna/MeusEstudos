# Caixa branca

Quando o teste é sobre caixa branca, isso significa que temos acesso ao código fonte. Por conta disso, validamos o fluxo do processamento.

## GFC - Grafo de Fluxo de Controle

O fluxo de execução do código pode ser representado como um diagrama de fluxo para fins de teste. Esse diagrama vai ser comparado com o verdadeiro fluxo que acontece durante a execução do teste, basicamente compara se o que está no diagrama acontece de fato no teste.

Todas as representações de operações como IF/ELSE, WHILE, FOR etc podem ser encontradas [aqui](../../semestre-1/fundamentos-de-sistemas/qualidade.md#mccabe), quando estudamos sobre McCabe anteriormente. Para o GFC, existem algumas diferenças. Para construir o processo completo, fazemos:

1. Numerar os blocos. Os números mudam somente em estruturas de decisão.
2. Desenhar os grafos.
3. Numeração do processo

### Numeração dos blocos

**Numeração zero:** Tudo até a primeira estrutura de decisão é numerado como zero. Por exemplo:

<figure><img src="../../.gitbook/assets/gfc numeração de blocos.png" alt=""><figcaption></figcaption></figure>

**Numeração em if/else:** As estruturas de decisões colocam números na primeira linha mas não no else. Além disso, numeram a linha do if e de dentro do if também. O número a seguir do IF é o que está dentro do else. Veja abaixo os padrões de numeração dessas estruturas:

<figure><img src="../../.gitbook/assets/gfc numeração de blocos ifelse.png" alt=""><figcaption></figcaption></figure>

### Desenho dos blocos

Tudo começa com um cabeçalho do que o que aquele programa faz, já apontando para o nó inicial, o zero.

Por **norma**, <mark style="color:red;">não pode agrupar</mark> mais de dois elementos em um nó somente. Portanto, um resultado do if/else nesse composto não pode já apontar para o nó seguinte, ele tem que apontar para um <mark style="color:purple;">nó não definido</mark>.

Veja um exemplo completo:

<figure><img src="../../.gitbook/assets/gfc.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/image (8).png" alt=""><figcaption></figcaption></figure>

No primeir exemplo, se não houvesse uma linha de else, o nó 4 seria substituído por um nó ND, mas a estrutura continuaria a mesma, exatamente o que acontece no segundo exemplo.

### Numeração do processo

No teste de caixa branca, precisamos mostrar no relatório linha por linha que o código está seguindo a sequência de teste válido. Essa sequência é o caminho que passa baseado nos dados fornecidos. Dados essas variáveis, o exemplo acima teve o seguinte progresso:

<figure><img src="../../.gitbook/assets/linhas de execução gfc.png" alt=""><figcaption></figcaption></figure>

Então, apenas seguimos as linhas e montamos a linha de execução:

```
0 1 3 5 ND 6
```

#### Simplificação da numeração do fluxo

No segundo exemplo já foi inserido a numeração na imagem. Mas vimos que existe um while que se repete três vezes de forma igual. Isso pode ser simplificado desta forma:

<figure><img src="../../.gitbook/assets/image (9).png" alt=""><figcaption></figcaption></figure>

> Lembrando que todos esses fluxos são previsíveis pois é um teste de caixa branca, que temos o código e os valores de entrada, então podemos saber exatamente por onde o código deve passar.
