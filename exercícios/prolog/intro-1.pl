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
avoPat(A,N) :- nasceu(Pai,m,A,_),nasceu(N,_,Pai,_).
avoMat(A,N) :- nasceu(Mae,f,A,_),nasceu(N,_,_,Mae).
avohPat(A,N) :- nasceu(Alguem,_,_,A),nasceu(N,_,Alguem,_).
avohMat(A,N) :- nasceu(Alguem,_,_,A),nasceu(N,_,_,Alguem).
irmao(I,X) :- nasceu(I,_,MesmoPai,MesmaMae),nasceu(X,_,MesmoPai,MesmaMae),I\==X. % Para não dizer que eu sou irmão de eu mesmo
primo(I,X) :- I \== X, avoPat(MesmoAvo,I), avoPat(MesmoAvo,X).
primo(I,X) :- I \== X, avoMat(MesmoAvo,I), avoMat(MesmoAvo,X).

progenitor(X,Y) :- pai(X,Y);mae(X,Y).
ancestral(X, Y) :- progenitor(X, Y).
ancestral(X, Y) :- progenitor(X, Alguem), ancestral(Alguem, Y).

/*
Querys:
  ancestral(Quem, Gui)
  irmaos(gui,joana).
  avohPaterna(duda,gui).
*/
                                                           
