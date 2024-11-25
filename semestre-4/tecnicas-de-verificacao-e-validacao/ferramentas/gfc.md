# GFC

Quando o teste é sobre caixa branca, isso significa que temos acesso ao código fonte. Por conta disso, validamos o <mark style="color:blue;">fluxo do processamento</mark>. O fluxo de execução do código pode ser representado como um diagrama de fluxo para fins de teste.

Esse diagrama vai ser comparado com o verdadeiro fluxo que acontece durante a execução do teste. Basicamente, compara se o que está no diagrama acontece de fato no teste. As representações sobre estruturas de controle já foram estudadas [aqui](../../../semestre-1/fundamentos-de-sistemas/qualidade.md#mccabe), quando vimos sobre McCabe. Para o GFC, existem algumas diferenças.

## Numeração dos blocos

Cada linha de código vai ser representada por um número onde tal número será representado por um nó no diagrama. A numeração inicia com zero e os números mudam somente em [<mark style="color:purple;">estruturas de decisão</mark>](#user-content-fn-1)[^1].

### **Numeração zero**

Tudo até a primeira estrutura de decisão é numerado como zero. Por exemplo:

<figure><img src="../../../.gitbook/assets/gfc numeração de blocos.png" alt=""><figcaption></figcaption></figure>

### **Numeração em decisões**

Cada tipo de decisão ter a sua forma de numerar. Segue abaixo os exemplos:

```python
# IF Simples: Numera a estrutura e segue para a lógica dentro da condição.
0 ...
1 if (var > 10):                
2    status = 'É maior que 10'
2    var += 5
3 ...

# IF com ELSE: O "else" não recebe uma numeração e sim o que está dentro dele.
# Repare que a linha de código "calc" recebe uma nova numeração mesmo estando dentro
# de um if, isso porquê está depois de um else.
0 ...
1 if (var >= 5): 
2    if (freq >= 75):
3        status = 'aprovado'
     else:
4        status = 'reprovado'

5    calc = var + freq * 0.1

else:
6    status = 'reprovado'
7 ...

# ELIF: O "else" passa a ser um "if" então é numerado. Em um grafo, o nó que seria
# um else agora será um nó de "if", já puxando as condições abaixo.
0 ...
1 if (var > 5): 
2     status = 'acima média'    
3 elif (var == 5):
4    status = 'na média'
5 else:
6    status = 'abaixo média'
7 ...


# WHILE: Numera a estrutura e segue para a lógica dentro da condição.
0 ...
1 while var < 100:
2    var += 1;
2    print(var)
3 ...

# FOR: Recebe um detalhe importante. O fechamento do for recebe uma numeração (onde
# supostamente ficaria o fecha chaves).
0 ...
1 for var in range(6):
2    freq = freq + var
2    print(var)
3
4 ...

# DO-WHILE: A linha da estrutura "do" não recebe numeração, mas sim o conteúdo e o
# "while" logo após. Não existe do-while em Python então foi feito em JavaScript.
0 var i = 1;
  do {
1     i++;
2 } while (i < 50);
3 console.log("Fim");
```

### Numeração não definida

\[ TO - DO]

## Desenho do grafo

O desenho dos grafos são baseados na numeração feita no código. Dentro de protocolos de teste, deve inserir tanto o grafo quanto a numeração. Cada estrutura pode ser representada pelos seguintes diagramas:









**Numeração em if/else:** As estruturas de decisões colocam números na primeira linha mas não no else. Além disso, numeram a linha do if e de dentro do if também. O número a seguir do IF é o que está dentro do else.&#x20;

Podemos numerar o else logo após o if (como está no exemplo) mas também podemos numerar em sequência sem problema (professor fez assim). Veja abaixo um exemplo de numeração dessas estruturas:

<figure><img src="../../../.gitbook/assets/gfc numeração de blocos ifelse.png" alt=""><figcaption></figcaption></figure>

**Numeração em while:** Uma simples numeração onde a estrutura de decisão recebe um número e o que está abaixo recebe o seguinte.

<figure><img src="../../../.gitbook/assets/while em gfc.png" alt=""><figcaption></figcaption></figure>

**Numeração em for:** Aqui existe uma diferença pois exige um nó noov para simbolizar o fim do for, no qual ele não aparece na linha de código explicitamente, ele seria o fecha chaves.

<figure><img src="../../../.gitbook/assets/for em gfc.png" alt=""><figcaption></figcaption></figure>

### Desenho dos blocos

Tudo começa com um cabeçalho do que o que aquele programa faz, já apontando para o nó inicial, o zero.

Por **norma**, <mark style="color:red;">não pode agrupar</mark> mais de dois elementos em um nó somente. Portanto, um resultado do if/else nesse composto não pode já apontar para o nó seguinte, ele tem que apontar para um <mark style="color:purple;">nó não definido</mark>.

Veja um exemplo completo:

<figure><img src="../../../.gitbook/assets/gfc.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/gfc de while prático.png" alt=""><figcaption></figcaption></figure>

No primeir exemplo, se não houvesse uma linha de else, o nó 4 seria substituído por um nó ND, mas a estrutura continuaria a mesma, exatamente o que acontece no segundo exemplo.

## Fluxos

No teste de caixa branca, precisamos mostrar no relatório linha por linha que o código está seguindo a sequência de teste válido. Essa sequência é o caminho que passa baseado nos dados fornecidos. Dados essas variáveis, o exemplo acima teve o seguinte progresso:

<figure><img src="../../../.gitbook/assets/linhas de execução gfc.png" alt=""><figcaption></figcaption></figure>

Então, apenas seguimos as linhas e montamos a linha de execução:

```
0 1 3 5 ND 6
```

#### Simplificação da numeração do fluxo

No segundo exemplo já foi inserido a numeração na imagem. Mas vimos que existe um while que se repete três vezes de forma igual. Isso pode ser simplificado desta forma:

<figure><img src="../../../.gitbook/assets/numeração processo gfc.png" alt=""><figcaption></figcaption></figure>

> Lembrando que todos esses fluxos são previsíveis pois é um teste de caixa branca, que temos o código e os valores de entrada, então podemos saber exatamente por onde o código deve passar.

[^1]: São exeplos `if`, `while`, `for` e qualquer outra que exista uma condição que possa alterar o fluxo de execução do código.
