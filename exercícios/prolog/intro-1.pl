/* Árvore genealógica

 Ana - Bruno       Duda - Edu
     |                  |
    Caio ------------- Fer
               |
            |-----|
            |     |
           Gui   Joana
*/

% Fatos
nasceu(gui,m,caio,fer).
nasceu(joana,f,caio,fer).
nasceu(caio,m,ana,bruno).
nasceu(fer,f,edu,duda).

% Regras
pai(P,F) :- nasceu(F,_,P,_).
mae(M,F) :- nasceu(F,_,_,M).
avoPaterno(A,N) :- nasceu(Alguem,_,A,_),nasceu(N,_,Alguem,_).
avoMaterno(A,N) :- nasceu(Alguem,_,A,_),nasceu(N,_,_,Alguem).
avohPaterna(A,N) :- nasceu(Alguem,_,_,A),nasceu(N,_,Alguem,_).
avohMaterna(A,N) :- nasceu(Alguem,_,_,A),nasceu(N,_,_,Alguem).
irmaos(X,Y) :- nasceu(X,_,PaiComum,MaeComum),nasceu(Y,_,PaiComum,MaeComum).

/* Querys
  irmaos(gui,joana).
  avohPaterna(duda,gui).
*/
                                                           
