# Tipos de validação

Existem duas abordagens para validar a qualidade de um particionamento, os critérios externos e internos/relativos.

* Critérios externos: Funciona <mark style="color:orange;">apenas com dados rotulados</mark> e, como possuímos esses rótulos, podemos encontrar um <mark style="color:purple;">padrão-ouro</mark>, que é uma representação do melhor agrupamento possível que pode ser feito. Usamos o nosso agrupamento e comparamos com esse padrão, para ver se o agrupamento acertou ou errou. Isso é feito dado por dado, por exemplo, conferir se `X` e `Y` formam uma dupla.
* Critérios internos: Avaliam a qualidade dos clusters sem usar rótulos reais pois não tem (sem padrão-ouro). Eles analisam apenas a estrutura dos dados e os agrupamentos gerados.

Em cada tipo de validação, é importante rever que algumas validações ou métricas de qualidade são usadas para rótulos contínuos e outras para categóricos.
