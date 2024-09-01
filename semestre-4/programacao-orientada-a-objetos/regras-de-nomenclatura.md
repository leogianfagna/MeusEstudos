# Regras de nomenclatura

A existência de regras facilita a codificação e compreensão em uma linguaguem "case sensitve", que é o caso de Java. Se as regras não forem seguidas, o compilador vai funcionar corretamente.

#### CLASSES, INTERFACES e PROJETOS:

* Palavras justapostas (sem espaços)
* Apenas iniciais de cada palavra maiúscula
* Ex: MinhaClasse, MinhaInterface, MeuProjeto

#### VARIÁVEIS E MÉTODOS:

* Formato Camel Case
* Ex: setDia, meuMetodo

#### CONSTANTES (palavra final):

* Separação das palavras por UNDERLINE
* Totalmente maiúsculas
* Ex: MAX\_VALUE, MIN\_VALUE, PI

#### SETTERS:

* Iniciar com "set"
* Finalizar com o que é alterado
* Ex: setDia, setMes

#### GETTERS:

* Inicia com "is" se o tipo retornado for boolean
* Inicia com "get" se for qualquer outro tipo
* Finaliza com o que é recuperado
* Ex: isPago, getValor

#### PACOTES (bibliotecas):

* Separação das palavras por pontos
* Todas letras minúsculas
* Ex: java.awt.event
