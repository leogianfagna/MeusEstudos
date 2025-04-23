# Trabalho final

O exercício consiste em implementar predicados que usam todo o conhecimento visto nas seções de Prolog, que possibilite encontrar dados de ocupação total e reservas em hotéis.

## Banco de conhecimentos

<figure><img src="../../../../.gitbook/assets/ex base de conhecimentos.png" alt=""><figcaption></figcaption></figure>

## Consultas desejadas

<figure><img src="../../../../.gitbook/assets/ex consultas esperadas.png" alt=""><figcaption></figcaption></figure>

## Principais regras

Pelo exercício são duas regras: `comquem` e `ocupacao`.

### Com quem

A regra `comquem` vai resgatar o nome dos acompanhantes na variável **NomesAcompanhantes**, que é satisfeita no último predicado na hora da conversão.

```prolog
comquem(CodHotel, CodHospede, Data, NomesAcompanhantes) :-
    
    % Resgata todas as ocupações daquele hotel
    hospedagem(CodHotel, ListaOcupacoes),
    
    % Filtra as ocupações com as condições exigidas (CodHospede e Data)
    busca_ocupacao(CodHospede, ListaOcupacoes, Data, CodigosAcompanhantes),
    
    % Converte os códigos em nomes reais
    converter_para_nomes(CodigosAcompanhantes, NomesAcompanhantes).
```

Perceba que temos apenas parâmetros genéricos, e quando isso existe, sabemos que o Prolog vai resgatar todos os fatos que ele conseguir. Em hospedagem, vai utilizar `ListaOcupacoes` como parâmetro genérico e `CodHotel` como parâmetro específico (isso vai retornar todas as hospedagens daquele `CodHotel` definido).

Perceba também que algumas variáveis genéricas são passadas de um para outros predicados:

<figure><img src="../../../../.gitbook/assets/fluxo de predicados.png" alt=""><figcaption></figcaption></figure>

Isso quer dizer que, a variável deixa de ser genérica, assumindo um valor que vai ser usado em outro predicado.

### Ocupacao

A regra `ocupacao` vai resgatar a quantidade de hóspedes em um hotel em uma determinada data na variável **Total**, que é satisfeita no último predicado.

```prolog
ocupacao(CodHotel, Data, Total) :-

    % Resgata todas as ocupações daquele hotel
    hospedagem(CodHotel, ListaOcupacoes),
    
    % Retorna o total calculado para a resposta
    conta_hospedes(ListaOcupacoes, CodHotel, Data, Total).
```

> Aqui se repete o mesmo esquema da regra acima, onde parâmetros genéricos são usados em outros predicados e toda a lista de ocupações é passada como parâmetro para `conta_hospedes`.

## Regras de controle

### Buscar ocupação correta (para comquem)

Esse predicado vai ter todas as ocupações (aqueles functors de ocupa) de um determinado hotel <mark style="color:orange;">em uma lista</mark> pois quem chama `busca_ocupacao` é `comquem` e ele <mark style="color:green;">já passa como parâmetro a lista de todas as ocupações</mark> encontradas no functor `ocupa`, dentro de `hospedagem`.

<figure><img src="../../../../.gitbook/assets/predicado com toda a lista.png" alt=""><figcaption></figcaption></figure>

O objetivo do predicado `busca_ocupacao` é encontrar a ocupação correta, que é:

1. **Código de hospede equivalente:** Como o objetivo é saber os acompanhantes de uma determinada pessoa, essa ocupação precisa ter como hóspede principal o `CodHospede`.
2. **Data equivalente:** É requisito que essa ocupação esteja dentro de um intervalo de uma data, portanto, é necessário conferir se a ocupação encontrada faz parte desse intervalo.

Portanto, podemos fazer o caso base satisfazendo ambas as condições acima. Caso contrário, usamos recursão até que encontremos uma ocupação sendo o hóspede principal equivalente, e depois vemos se ele satisfaz com o caso base.

```prolog
% Caso base: Se o CodHospede for o titular da ocupação e a Data estiver no intervalo
% entre DataEntrada e DataSaida, então retorna os acompanhantes.
busca_ocupacao(CodHospede, [ocupa(CodHospede, _, DataEntrada, DataSaida, Acompanhantes)|_], Data, Acompanhantes) :-
    intervalo_data(Data, DataEntrada, DataSaida).

% Se não for a ocupação certa (o código do hóspede principal ou a data não bate),
% pula para a próxima da lista (OutrasOcupacoes)
busca_ocupacao(CodHospede, [_|OutrasOcupacoes], Data, Acompanhantes) :-
    busca_ocupacao(CodHospede, OutrasOcupacoes, Data, Acompanhantes).
```

Perceba que a recursão vai apenas repetir a checagem do caso base, mas com o próximo elemento da lista:

<figure><img src="../../../../.gitbook/assets/recursão que leva ao caso base.png" alt=""><figcaption></figcaption></figure>

### Converter nomes (para comquem)

Esse predicado recebe uma lista de códigos e seu segundo parâmetro são os nomes respectivos a esses códigos. Portanto, o segundo parâmetro deve ser genérico para poder resgatar o que queremos.

O caso base é demarcado como uma lista vazia equivale a uma lista vazia, através do pensamento: _**se não tem mais códigos para converter, não há nomes a adicionar**_.

```prolog
converter_para_nomes([], []).
```

O caso recursivo se repete convertendo todos os nomes até que a lista esteja vazia. Ele pega o primeiro elemento da lista e encontra o nome respectivo com o predicado `hospede`. Desta forma:

<figure><img src="../../../../.gitbook/assets/conseguir um nome com predicado hospede.png" alt=""><figcaption></figcaption></figure>

Acima, usamos um exemplo em que o primeiro código da lista seria "3", o que equivale ao nome de "Ricardo", pela existência de um fato `hospede(3, Ricardo)`.

Os nomes encontrados vão sendo concatenados na volta da recursão, quando ela encontra o caso base (comportamento padrão da recursão). Desta forma:

<figure><img src="../../../../.gitbook/assets/conversao para nomes prolog.png" alt=""><figcaption></figcaption></figure>

### Intervalo de data (ambas)

Predicado usado para descobrir se uma determinada data está entre outras duas datas fornecidas. Essa regra fica fácil de entender pois utiliza um outro predicado auxiliar, que recebe uma data e converte para um número.

Tendo um número, usamos ele para fazer a comparação das datas. O predicado é usado para retornar true ou false, caso todas as condições se satisfaçam.

<figure><img src="../../../../.gitbook/assets/data está no intervalo prolog.png" alt=""><figcaption></figcaption></figure>

### Somar ocupação (para ocupacao)

A ideia é contar os hóspedes presentes em uma data específica. A ideia é usar recursão para percorrer cada ocupação, conferir se esta ocupação está no intervalo desta data e, caso esteja, somar a quantidade de hóspedes e acompanhantes.

Baseado na ideia acima, podemos usar uma [estrutura de condição](../regras-avancadas/if-then.md) (tipo operador ternário) no qual se a data for válida (está no intervalo) faz a somatória, mas caso contrário, segue a recursão normalmente.&#x20;

```prolog
somar_ocupacao([], _, _, 0).
somar_ocupacao([ocupa(_, _, DataEntrada, DataSaida, Acompanhantes)|OcupacoesRestantes], CodHotel, Data, Total) :-

    (intervalo_data(Data, DataEntrada, DataSaida) % Condição if-then
     ->
    	% Data válida (condição true): Fazer contagem (hóspede principal é apenas +1)
        somar_acompanhantes(Acompanhantes, TotalAcompanhantes),
        TotalDestaOcupacao is 1 + TotalAcompanhantes,
        somar_ocupacao(OcupacoesRestantes, CodHotel, Data, SomaResto),
        Total is TotalDestaOcupacao + SomaResto
     ;
    	% Data inválida (condição false): Fora do intervalo, apenas seguir recursão
        somar_ocupacao(OcupacoesRestantes, CodHotel, Data, Total)
    ).
```

A ideia na condição verdadeira (aquela que precisamos fazer a somatória) é somar o hóspede mais os acompanhantes de cada ocupação (com `somar_acompanhantes`) e depois seguir recursivamente o resto da lista <mark style="color:blue;">acumulando a contagem total</mark>.

<figure><img src="../../../../.gitbook/assets/prolog somar com dois predicados.png" alt=""><figcaption></figcaption></figure>

### Somar acompanhantes (para ocupacao)

Tem como objetivo resgatar um número, o total de acompanhantes em uma determinada ocupação. Esse predicado recebe no primeiro parâmetro uma lista com os códigos dos acompanhantes, então basta <mark style="color:green;">apenas contar quantos são</mark>.

{% hint style="warning" %}
`somar_acompanhantes` recebe de fato apenas a lista dos acompanhantes como `[2, 15, 56]`, pois o predicado `somar_ocupacao` <mark style="color:blue;">**desestrutura**</mark> todo o functor de ocupação, passando apenas a lista de acompanhantes para cá.
{% endhint %}

Para apenas uma contagem, simplesmente fazer uma recursão com um critério de parada quando a lista for vazia equivalendo a zero. A cada iteração somar 1 no total, desta forma:

```prolog
somar_acompanhantes([], 0).
somar_acompanhantes([_|OutrosAcompanhantes], Total) :-
    somar_acompanhantes(OutrosAcompanhantes, ContagemParcial),
    Total is ContagemParcial + 1.
```

Veja que o código do acompanhante não importa para nós, apenas quantas iterações tiveram. Por isso foi marcado como `_`. Além disso, o que importa na lista é apenas `OutrosAcompanhantes` que é passado como parâmetro da recursão para que ela possa continuar contando, até que o resto da lista seja vazio.
