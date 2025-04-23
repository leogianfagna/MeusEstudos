% ---------------------
% Base de conhecimentos
% ---------------------

% HOTÉIS: hotel(ch,nh)
hotel(1,sahara_ski_station).
hotel(2,siberia_surfing).

% QUARTOS: apto(ch,na,ca)
% Hotel 1
apto(1,101,1).	% livre
apto(1,102,2).	% ocupado
apto(1,103,3).	% ocupado
apto(1,104,4).	% ocupado
apto(1,201,1).	% ocupado
apto(1,202,2).	% ocupado
apto(1,203,3).	% ocupado
apto(1,301,1).	% livre
apto(1,302,2).	% livre
apto(1,303,3).	% livre

% Hotel 2
apto(2,101,1).	% ocupado
apto(2,102,2).	% ocupado
apto(2,103,3).	% ocupado
apto(2,201,1).	% livre
apto(2,202,2).	% ocupado
apto(2,203,3).	% livre
apto(2,301,1).	% livre
apto(2,302,2).	% livre
apto(2,303,3).	% livre

% HÓSPEDES: hospede(ch,nh)
% Hotel 1
hospede(1,jose).
hospede(2,maria).
hospede(3,ana).
hospede(4,fernando).
hospede(5,victor).
hospede(6,janna).
hospede(7,sophia).
hospede(8,manuela).
hospede(9,liz).
hospede(10,heitor).
hospede(11,gael).
hospede(12,davi).
hospede(21,junin).

% Hotel 2
hospede(13,jose).
hospede(14,deborah).
hospede(15,ana).
hospede(16,laura).
hospede(17,alice).
hospede(18,mafagafo).
hospede(19,mafagafão).
hospede(20,mafagafin).

% HOSPEDAGENS:
% 	hospedagem(ch,[o1,o2,...,on])
% 	ocupa(ch,na,de,ds,[ch1,ch2,...,chn])
hospedagem(1, [
    ocupa(4,102,[3,4,2025],[11,4,2025],[5]),
    ocupa(2,202,[8,4,2025],[13,4,2025],[6]),
    ocupa(3,104,[2,4,2025],[10,4,2025],[7,8,9]),
    ocupa(1,203,[1,3,2025],[8,6,2025],[2,4]),
    ocupa(21,201,[1,3,2025],[8,6,2025],[]),
    ocupa(10,103,[2,6,2025],[8,6,2025],[11,12])
]).

hospedagem(2, [
	ocupa(13,103,[1,4,2025],[10,4,2025],[15,14]),
	ocupa(16,102,[3,4,2025],[11,4,2025],[17]),
    ocupa(18,202,[3,4,2025],[11,4,2025],[19]),
    ocupa(20,101,[3,4,2025],[11,4,2025],[])
]).

% ---------------------
% Exercício 1) Predicado de comquem
% ---------------------

% A regra comquem resgata o nome dos acompanhantes em uma lista no parâmetro NomesAcompanhantes, que é
% satisfeita no último predicado na hora da conversão.
% USO: comquem(1,1,[3,4,2025],CQ).
comquem(CodHotel, CodHospede, Data, NomesAcompanhantes) :-
    hospedagem(CodHotel, ListaOcupacoes),
    busca_ocupacao(CodHospede, ListaOcupacoes, Data, CodigosAcompanhantes),
    codigo_para_nome(CodigosAcompanhantes, NomesAcompanhantes).


% Converte todos os nomes até que a lista esteja vazia. Tem como estrutura ([lista_codigos], [lista_nomes])
% Com o código usado "PrimeiroCodigo", resgata o "Nome" de hospede que são concatenados na volta da recursão
% e repete recursão com o restante da lista.
codigo_para_nome([], []).
codigo_para_nome([PrimeiroCodigo|OutrosCods], [Nome|OutrosNomes]) :-
    hospede(PrimeiroCodigo, Nome),
    codigo_para_nome(OutrosCods, OutrosNomes).


% Tem como objetivo resgatar uma lista de "Acompanhantes" de uma certa ocupação. Filtra entre todas as
% ocupações recebidas ("comquem" chama ele passando elas) até condizer com o CASO BASE: CodHospede e
% intervalo_data condizem. Repete recursão até encontrar ocupação desejada.
% Desestrutura apenas o primeiro elemento da lista e ignora o resto _.
busca_ocupacao(CodHospede, [ocupa(CodHospede, _, DataEntrada, DataSaida, Acompanhantes)|_], Data, Acompanhantes) :-
    intervalo_data(Data, DataEntrada, DataSaida).
busca_ocupacao(CodHospede, [_|OutrasOcupacoes], Data, Acompanhantes) :-
    busca_ocupacao(CodHospede, OutrasOcupacoes, Data, Acompanhantes).


% ---------------------
% Exercício 2) Predicado ocupacao
% ---------------------

% Usa o fato hospedagem para conseguir todas as ocupações (ListaOcupacoes) de um determinado hotel (CodHotel)
% Usa essa lista para somar_ocupacao contar os hospedes de cada ocupacao e retornal o "Total"
% USO: ocupacao(1,[5,6,2025],TOTAL).
ocupacao(CodHotel, Data, Total) :-
    hospedagem(CodHotel, ListaOcupacoes),
    somar_ocupacao(ListaOcupacoes, CodHotel, Data, Total).


% Recebe uma lista de functors ocupa e desestrutura para usar as variáveis da primeira lista (as demais listas
% ficam em "|OcupacoesRestantes". A desestruturação serve para conseguir os "Acompanhantes" da ocupação e usar
% para contar em "somar_acompanhantes" e depois seguir com a recursão com o resto da lista "OcupacoesRestantes".
somar_ocupacao([], _, _, 0).
somar_ocupacao([ocupa(_, _, DataEntrada, DataSaida, Acompanhantes)|OcupacoesRestantes], CodHotel, Data, Total) :-
    (intervalo_data(Data, DataEntrada, DataSaida) % Condição if-then
     ->
    	% Data válida (condição true): Fazer contagem (hóspede principal é apenas +1), retorna quantidade de
    	% acompanhantes no TotalAcompanhantes
        somar_acompanhantes(Acompanhantes, TotalAcompanhantes),
        TotalDestaOcupacao is 1 + TotalAcompanhantes,
        somar_ocupacao(OcupacoesRestantes, CodHotel, Data, SomaResto),
        Total is TotalDestaOcupacao + SomaResto
     ;
    	% Data inválida (condição false): Fora do intervalo, apenas seguir recursão
        somar_ocupacao(OcupacoesRestantes, CodHotel, Data, Total)
    ).


% Recebe LISTA de códigos dos acompanhantes. Basta apenas contar quantas iterações tiveram na recursão
% usando o resto da lista. Critério de parada quando ela estiver vazia.
somar_acompanhantes([], 0).
somar_acompanhantes([_|OutrosAcompanhantes], Total) :-
    somar_acompanhantes(OutrosAcompanhantes, ContagemParcial),
    Total is ContagemParcial + 1.


% Recebe uma data em uma lista e retorna como um número inteiro para fazer comparações.
data_para_num([D, M, A], DataEmNumero) :-
    DataEmNumero is A * 10000 + M * 100 + D.


% Confere se uma data está dentro de um intervalo usando as saídas das datas como números inteiros com
% o predicado "data_para_num". Usa "DataInt", "IntEntrada" e "IntSaida" como variáveis genéricas
% para receber o valor da conversão e comparar com os operadores.
intervalo_data(Data, DataEntrada, DataSaida) :-
    data_para_num(Data, DataEmNumero),
    data_para_num(DataEntrada, DataEntradaNum),
    data_para_num(DataSaida, DataSaidaNum),
    DataEmNumero >= DataEntradaNum,
    DataEmNumero =< DataSaidaNum.

% ---------------------
% Testes
% ---------------------
% comquem(1,1,[3,4,2025],CQ).
% QUEM = [maria, fernando]

% comquem(1,3,[5,4,2025],CQ).
% CQ = [sophia, manuela, liz]
% [7,8,9] ->  [sophia, manuela, liz]

% comquem(2,4,[1,3,2025],CQ).
% false -> o hóspede 4 não está no hotel 2

% comquem(1,21,[2,3,2025],CQ).
% CQ = [] -> o 21 está sozinho na estadia

% comquem(1,21,[2,1,2025],CQ).
% false -> o 21 não está no hotel ainda nessa data

% comquem(2,13,[5,4,2025],CQ).
% CQ = [ana, deborah]

% ocupacao(1,[5,6,2025],TOTAL).
% TOTAL = 7
