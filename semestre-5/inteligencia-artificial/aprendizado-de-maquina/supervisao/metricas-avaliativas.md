# Métricas avaliativas

As métricas avaliativas medem o quão distantes estão as previsões do esperado, podendo então avaliar um modelo preditivo.

Quando estamos vendo desvios, vemos eles comparados à média dos dados. Em modelos preditivos, estamos comparando o dado especulado com o dado real, que está disponível durante o nosso treino e teste.

## MAE

Usa como base o [erro absoluto](../../../estatistica/variacao-e-dispersao.md#desvio-absoluto), sendo essa métrica a <mark style="color:blue;">média do erro absoluto</mark> (Mean Absolute Error). Então mostra para nós em média o quanto o modelo está errando fazendo com que valores próximos de zero seja melhores.

Veja abaixo sendo `yr` o valor real e `yr` o valor previsto, um menos o outro será nosso erro absoluto. A fórmula soma todos eles e depois tira a média das `n` amostras.

$$
MAE=1/n*∑∣yr−yp ∣
$$

$$
MAE(exemplo) = (1.0 + 0.5+1.5)/3 = 1
$$

## RMSE

Usa como base o [erro quadrático](../../../estatistica/variacao-e-dispersao.md#desvio-quadratico). Essa métrica é a <mark style="color:blue;">raiz quadrada da média dos erros quadráticos</mark> (Root Mean Squared Error). Isso faz com que ela penalize mais os erros maiores pois eles estarão elevados ao quadrado. Essa penalização maior faz com que essa métrica seja mais útil quando queremos algo mais sensível à qualquer erro grande.

$$
RMSE=√(1/n*∑∣yr−yp ∣)
$$

$$
RMSE(exemplo) = √(1.0² +  0.5² + 1.5²)/3 = √1.17 = 1.08
$$

```python
# Resultados obtidos através de algum modelo (neste caso, KNN)
y_pred_knn = knn.predict(X_test)

# Retorna uma métrica agregada, um valor único do comparativo dos dois parâmetros
rmse = np.sqrt(mean_squared_error(y_test, y_pred_knn))
```

## Coeficiente de determinação

Caracterizado como R², ele é usado para saber <mark style="color:blue;">quanto o modelo explica dos dados</mark>.&#x20;

Resulta em um valor entre zero e um, sendo um o modelo explicando praticamente 100% dos dados. Existe a possibilidade de retornar negativo, mas isso quer dizer que a previsão está péssima.

$$
R²=1−(SomaErrosModelo/MediaSomaErrosModeloNulo)
$$

