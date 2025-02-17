# Introdução

Uma arquitetura é um <mark style="color:blue;">modelo de planejamento para definir tomadas de decisões</mark>.

## Definir relações fortes

Como saber se classe/algo tem uma forte relação com outra coisa? Para isso, é analisado o <mark style="color:blue;">nível de</mark> <mark style="color:blue;"></mark><mark style="color:blue;">**dependência**</mark> <mark style="color:blue;"></mark><mark style="color:blue;">e</mark> <mark style="color:blue;"></mark><mark style="color:blue;">**intimidade**</mark> <mark style="color:blue;"></mark><mark style="color:blue;">entre eles</mark>.

* Funções que se chamam e utilizam variáveis globais: impactam em condição de corrida, forte relação (parelelismo).
* APIs: eles não são íntimos, poís não compartilham nada e basta apenhas chamar. Nível baixo de relação.
* Classe que chama uma função enviando todos os parâmetros necessários: forte relação, nível de dependência extremo.
* Classes globais: não implica em dependência, tem suas relações mas não é tão íntimo.

São esses os tipos de pensamentos necessários para entender fortes relações entre "coisas".&#x20;

## Decisões utilização de tecnologia

Tudo depende, precisa levar a perspectiva de bônus e ônus. Boas decisões de arquitetura produzem abstrações de <mark style="color:blue;">design simples e fáceis de refatorar</mark>.
