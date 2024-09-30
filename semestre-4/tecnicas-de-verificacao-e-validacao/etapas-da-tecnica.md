# Etapas da técnica

## Explicação das etapas

### Identificar as classes/partições de equivalência

Isso significa identificar os <mark style="color:blue;">dados de entrada</mark> do software. No exemplo, o resultado seria:

* Horas trabalhadas `float`
* Salário hora `float`
* Tempo serviço (em meses) `float`
* Número de filhos `int`
* Estado civil `string`

### Identificar as classes/partições de saída

Quais dados e resultados o software vai entregar. No exemplo, o resultado seria:

* Salário bruto `float`
* Desconto INSS `float`
* Abono TS `float`
* Abono filhos `float`
* Salário líquido `float`

Instanciar o tipo dos valores faz parte de uma etapa, portanto, todas as variáveis já estão com o seu tipo demarcado.

### Definir os dados do teste (definir escopo)

Vamos definir quais serão os valores válidos que poderão ser inseridos nas classes de entrada. Esses valores tem que ser suficientes para todos os tipos de funcionários, em outras palavras, esse software abrange os valores válidos para os funcionários não remunerados e o funcionário com maior remuneração da empresa. Basicamente, definir um escopo não é sobre um valor e sim todos os valores.

Para fazer isso, ver os requisitos do software e ver o que tem de informação ali. Por exemplo, não há nada especificado sobre o número de filhos (por exemplo, tem que ser no máximo 5). Então, a definição do escopo não vai ser decidido através do requisito e sim vamos tomar nossa própria decisão. As vezes o requisito especifica esse tipo de informação e ai sim teremos que usar o que está ali.

Classes entrada:

* `0 <= Horas trabalhadas <= 100`
* `9 <= Salário hora <= 50`
* `0 <= Tempo serviço <= 20`
* `0 <= Número filhos <= 5`
* `Estado civil contém [S, C, D, V]`

Classes saída:

* `0 <= Salário bruto`
* `9 <= Desconto INSS`
* `0 <= Desconto IR`
* `200 <= Abono TS`
* `0 <= Abono filhos`
* `200 <= Salário líquido`

### Definir valores de referência

Baseado nos valores válidos de entrada, precisamos decidir quais valores usaremos para inserir no teste. Todos os valores escolhidos devem ser justificados, por exemplo, escolher valores que representam uma semana exata, ou valores dos limites possíveis, valores mais frequentes baseado nas estatísticas da empresa, etc.

<figure><img src="../../.gitbook/assets/image.png" alt="" width="149"><figcaption></figcaption></figure>

### Cortar valores

Com toda essa quantia de valores escolhidos, o número total de testes ficaria extremamente grande. Por cota disso, cortar valores com base em justificativas (que devem estar o relatório) para diminuir o número total de testes sem perder eficácia.

Exemplo de cortes:

* Para número de filhos, a matemática é a mesma independente do número. Portanto, podemos deixar apenas o número zero e o número que representa a média no estograma e cortar todo o resto.
* A partir de um certo valor, a forma de calcular sempre se mantém a mesma. Retirar todos esses valores excedentes.
* Valores limites nem sempre são importantes.

> No caso do nosso relatório, vamos fazer testes com números fixos e limitados. Por conta disso, essa etapa não mudaria nada no resultado final, mas em um relatório com testes reais ela sim seria importante.

### Gerar protocolo de testes

Esse passo consiste em começar a preencher o relatório e ele inicia na montagem dos testes, isto é, definir os valores aleatórios (baseado naqueles possíveis acima) que serão usados nas entradas para cada teste.

Usando esses valores que começamos a preencher o protocolo. Com a ajuda do Excel (ou manualmente se for fácil) podemos preencher os valores de saída esperados.

### Realizar o teste

Agora realizar o teste usando os valores definidos no protocolo. O preenchimento do relatório precisa, de forma explícita, objetiva, clara e compreensível:

* Descrever exatamente o que fazer (desde a abertura do software) em forma de passo a passo para como realizar o teste
* Definir condições de teste: status operacional do software
  * Não pode ter erros de interpretação
  * Identificar todos os campos e dados
* Enviar fotos do progresso
* Inserir resultados e possíveis variações
* Apontar questões relevantes e observações
* Repetir a mesma coisa para valores não válidos
