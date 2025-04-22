# If-then

Permite fazer a prática de uma estrutura de controle condicional caso um predicado seja verdadeiro ou falso:

```prolog
(condicao)
 -> 
    se true
 ;  
    se false
)
```

A condição precisa ser necessariamente um predicado que possa retornar true ou false. Já as demais estruturas são flexíveis, mas permitem também predicados, exemplo:

```prolog
somar_ocupacao([Lista], CodHotel, Data, Total) :-

    (intervalo_data(Data, DataEntrada, DataSaida) % Condição
     ->
    	% Se sim:
        Total is TotalOcupacao + SomaResto
     ;
    	% Se não:
        somar_ocupacao(OcupRestantes, CodHotel, Data, Total)
    ).
```
