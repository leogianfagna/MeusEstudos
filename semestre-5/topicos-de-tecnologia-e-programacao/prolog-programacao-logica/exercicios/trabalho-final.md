# Trabalho final

## Banco de conhecimentos

<figure><img src="../../../../.gitbook/assets/image.png" alt=""><figcaption></figcaption></figure>

## Consultas desejadas

<figure><img src="../../../../.gitbook/assets/image (1).png" alt=""><figcaption></figcaption></figure>

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

### Buscar ocupação correta

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

### Converter nomes

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

### Intervalo de data

Predicado usado para descobrir se uma determinada data está entre outras duas datas fornecidas. Essa regra fica fácil de entender pois utiliza um outro predicado auxiliar, que recebe uma data e converte para um número.

Tendo um número, usamos ele para fazer a comparação das datas. O predicado é usado para retornar true ou false, caso todas as condições se satisfaçam.

<figure><img src="../../../../.gitbook/assets/data está no intervalo prolog.png" alt=""><figcaption></figcaption></figure>
