# Avaliação

São medidas objetivas para avaliar o modelo de predição para rótulos contínuos ou discretos. Lembrando que cada modelo tem o seu critério de avaliação como média dos erros quadráticos, matriz de confusão, entre outras.

## Generalização

> Escrever sobre validação cruzada

## Emsemble

A ideia é usar classificadores simultâneos como KNN e regressão linear e classificar o rótulo final através de um consenso entre esses algoritmos. Se a maioria dos algoritmos está dizendo que o rótulo é "A", portanto, o rótulo será "A".

Se algum classificador tiver alguma medida de certeza (por exemplo, há 60% de certeza que esse rótulo está correto através desse algoritmo), podemos usar esse valor para ponderar a classificação do rótulo entre os algoritmos.

### Stacking

É um <mark style="color:blue;">juíz classificador</mark> como uma alternativa ao concenso. Esse juíz define qual classificador é o melhor modelo para cada caso, aprendendo o peso ideal para os votos no rótulo.&#x20;
