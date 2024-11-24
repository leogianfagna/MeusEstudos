# Etapas

## Definir classes/partições de entrada e saída

Consiste em <mark style="color:blue;">escrever quais serão as variáveis</mark> que receberão dados e as variáveis que serão retornadas. Todos os dados de entrada são atribuídos à variáveis então elas são as de entrada. Toda função para teste vai retornar um valor então elas são a de saída.

> ### Exemplo:
>
> Classes de Entrada:
>
> * `n1`: Equivale ao valor da nota da primeira prova.
> * `n2`: Equivale ao valor da nota da segunda prova.
>
> \
> Classes de Saída:
>
> * `mediaFinal`: Equivale à média calculada baseada nas duas notas fornecidas.
> * `status`: Mensagem equivalente ao resultado do aluno.

## Definir os domínios

Também conhecido como <mark style="color:purple;">escopo</mark>, os <mark style="color:blue;">domínios são os valores válidos</mark> que as classes definidas acima podem receber ou retornar. Precisamos fazer essa etapa junto com a próxima, a análise BVA.

> ### Exemplo:
>
> Classes de Entrada:
>
> * `n1`: De zero à 10.
> * `n2`: De zero à 10.
>
> \
> Classes de Saída:
>
> * `mediaFinal`: De zero à 10.
> * `status`: Mensagem "APROVADO" ou "REPROVADO".

## Valores típicos (análise BVA)

Análise BVA é a borda[^1] (range) de valores possíveis para os domínios. Os <mark style="color:blue;">valores típicos são uma série de escolha de valores</mark> dentro de cada intervalo para serem usados como teste. Aqui estaremos falando apenas dos **valores de entrada**.

Essa etapa exige <mark style="color:blue;">explicar a decisão dos valores</mark>. As explicações geram em torno de falar o que vai gerar (ou o que se espera) no teste usando aqueles dados e especificar alguns valores bem específicos escolhidos.

> ### Exemplo de análise BVA e depois de Valores Típicos

<table><thead><tr><th width="128">Classe</th><th>Válido</th><th>Não válido</th></tr></thead><tbody><tr><td>n1</td><td>Float positivo <code>0 &#x3C;= n1 &#x3C;= 10</code></td><td><code>n1 &#x3C; 0</code> ou <code>n1 > 10</code> ou qualquer tipo de caractere.</td></tr><tr><td>n2</td><td>loat positivo <code>0 &#x3C;= n2 &#x3C;= 10</code></td><td><code>n2 &#x3C; 0</code> ou <code>n2 > 10</code> ou qualquer tipo de caractere.</td></tr></tbody></table>

<table><thead><tr><th width="128">Classe</th><th>Válido</th><th>Não válido</th></tr></thead><tbody><tr><td>n1</td><td><code>0</code> <code>4</code> <code>8</code> <code>10</code></td><td><code>-3</code> <code>10.01</code> <code>22</code> <code>-0.0</code>1</td></tr><tr><td>n2</td><td><code>0.5</code> <code>3</code> <code>5.5</code> <code>9.9</code></td><td><code>m</code> <code>100</code> <code>*</code> <code>-</code></td></tr></tbody></table>

## Dataset

É uma tabela com diversas linhas, onde cada linha representa um conjunto de valores de entrada que servirão para fazer um teste. Vai existir dois datasets:

* Dataset válido: Uma tabela gerada usando todos os valores válidos escolhidos na análise acima.
* Dataset inválido: Agrega todos os valores válidos com os valores inválidos depois remove as linhas cujo os valores de entrada [resultariam em um valor válido](#user-content-fn-2)[^2]. Certificar de ao menos um valor de entrada inválido por teste/linha.

O Dataset é gerado com todas as possibilidades de conjuntos com os valores de entrada fornecidos nos valores típicos. Depois, a <mark style="color:blue;">quantidade de resultados deve ser reduzida</mark> usando técnicas, como o [Pairwise](pairwise.md).

> ### Exemplo real dos datasets

<figure><img src="../../.gitbook/assets/exemplo de dataset.png" alt="" width="563"><figcaption></figcaption></figure>

## Definição dos GFC

O GFC é uma técnica válida apenas para testes de caixa branca onde podemos ver o código. A criação do GFC deve seguir os ensinamentos descritos [nesta página](gfc.md). O código com as linhas numeradas deve estar presente.

## Fluxos do GFC

Os [fluxos do GFC](gfc.md) consistem em calcular todos os possíveis caminhos dentro do diagrama gerado na etapa acima. Cada caminho deve ser descrito em uma tabela indicando o que acontece e o que retorna.

Para um trabalho ainda mais completo, pode-se desenhar cada fluxo destacado ao lado da linha de código indicando cada linha que está passando naquele fluxo.

> ### Exemplo real de descrição de fluxo GFC

<table><thead><tr><th width="292">Fluxo</th><th>Descrição</th></tr></thead><tbody><tr><td>1 2 FIM</td><td>Teste para os valores das notas quando um valor de entrada de qualquer uma das notas é não válido. Deve retornar um objeto “-1” e uma mensagem “ERRO NOTAS FORA DO INTERVALO”.</td></tr><tr><td>1 ND 3 4 FIM</td><td>Teste para o valor de entrada do porcentual do projeto integrador, quando ele é inválido. Deve retornar um objeto “-2” e uma mensagem “ERRO PERCENTUAL DE PONDERACAO PARA CALCULO DA MEDIA FINAL”.</td></tr><tr><td>1 ND 3 ND 5 6 7 8 9 ND 15 FIM</td><td>Passa a verificação de dados de entrada inválidos e possuiu alguma das médias abaixo de 5. Neste caso, a nota média teórica é maior que do projeto integrador e então atribui esta nota à média final. Retorna a média final e uma string “REPROVADO”</td></tr><tr><td>1 ND 3 ND 5 6 7 8 10 ND 15 FIM</td><td>Passa a verificação de dados de entrada inválidos e possuiu alguma das médias abaixo de 5. Neste caso, a nota média teórica é menor que do projeto integrador e então atribui a nota do projeto à média final. Retorna a média final e uma string “REPROVADO”.</td></tr><tr><td>1 ND 3 ND 5 6 11 12 13 ND 15 FIM</td><td>Passa a verificação de dados de entrada inválidos e possuiu alguma das médias abaixo de 5. Passa positivamente pela checagem se as duas médias (projeto e teórica) são maiores do que 5, calcula a média final. Retorna a média final e uma string “APROVADO”.</td></tr><tr><td>1 ND 3 ND 5 6 11 12 14 ND 15 FIM</td><td>Passa a verificação de dados de entrada inválidos e possuiu alguma das médias abaixo de 5. Passa positivamente pela checagem se as duas médias (projeto e teórica) são maiores do que 5, calcula a média final e é negado na condição se a média final é maior que 5, assumindo o status de reprovação. Retorna a média final e uma string “REPROVADO”.</td></tr></tbody></table>

## Definir protocolos de teste

Todas as etapas acima devem ser feitas no documento de texto com numeração de cada etapa e título. A partir daqui, será preenchido os protocolos de teste que utilizam e inserem parte das informações acima. Siga os passos sobre [protocolos de teste](protocolos.md).

## Aplicação dos testes

A aplicação dos testes segue como base o protocolo criado. Usando o mesmo formato de folha mas em uma folha nova, a [aplicação dos testes](etapas.md#aplicacao-dos-testes) devem seguir os passos descritos nessa página.

## Apresentar conclusão

Uma breve descrição do que foi feito, basicamente falando que os protocolos foram criados e os testes foram executados. Essa não é sobre as observações nas folhas, mas sim uma conclusão geral final do que foi feito e observado.

[^1]: Lembrar do exemplo do braço mecânico que um plano cartesiano com um círculo no meio mostrada quais eram os valores máximos alcançados, e qualquer coisa fora do círculo estava inválido.

[^2]: Como foi usado válores válidos junto com inválidos, pode haver linhas em que só existem valores válidos para entrada. Isso faria com que o resultado do teste fosse válido. Basta remover essa linha para que fique **ao menos** um valor de entrada inválido por teste.
