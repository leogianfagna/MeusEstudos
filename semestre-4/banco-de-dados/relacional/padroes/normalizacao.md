# Normalização

Regras que o banco de dados precisa ter, dividida em vários níveis:

* Colocar uma chave primária.
* **1FN**: Técnica da <mark style="color:purple;">atomicidade</mark>, cada coluna guarda um único valor. Guardar uma coluna com o valor "Rua Joaquina 340" já quebra a regra, onde o número deveria estar separado.
* **2FN**: Separar (responsabilidades) em outras tabelas dados que não pertencem ao tópico central da tabela, exemplo, <mark style="color:purple;">externalizar</mark> endereço do cliente.
* **3FN**: Não ter dados que dependem de outros, por exemplo: salário líquido que é gerado a partir de um cálculo. Esses dados devem ser tratados no back-end.

