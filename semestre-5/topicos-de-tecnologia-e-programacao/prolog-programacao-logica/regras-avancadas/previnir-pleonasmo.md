# Previnir pleonasmo

Se temos uma regra para irmãos que checa se possuem o mesmo pai, teoricamente, se conferirmor se `irmao(X,X)` isso retornaria verdadeiro, já que é o mesmo pai.

As regras precisam incluir que não podemos ser irmãos de nós mesmos, então adicionamos uma **nova condição** que exige que o valor não possa ser igual:

```prolog
irmao(I,X) :- nasceu(I,_,MesmoPai,MesmaMae),nasceu(X,_,MesmoPai,MesmaMae),I\==X.
```

Isso também deve ser feito em diversos casos, como por exemplos primos. Se a gente consultar `primo(eu,meuIrmao)` vai resultar verdadeiro pois são os mesmos avós. Então é necessário uma condição para medir que um parâmetro não seja irmão do outro.
