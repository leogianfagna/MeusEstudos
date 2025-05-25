# Treino teste

É uma etapa do aprendizado de máquina supervisionado para <mark style="color:blue;">divide os dados para que um</mark> [<mark style="color:blue;">algoritmo</mark>](#user-content-fn-1)[^1] <mark style="color:blue;">possa ser treinado</mark> e testado com justiça. Essa etapa é importante para ensinar o modelo com respostas conhecidas, aprendendo a relação entre elas.

Então essa etapa é apenas a separação de dados para que nosso algoritmo tenha com o que aprender e depois possa ser testado se acertou.

Para montar um treino teste, podemos fazer:

<figure><img src="../../../../.gitbook/assets/treino teste ex 1.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../../.gitbook/assets/treino teste ex 2.png" alt=""><figcaption></figcaption></figure>

As variáveis de saída (`X_train`, `X_test`, etc) serão usadas pelos algoritmos, tanto para treiná-los ou para medir a qualidade de previsões.

* Variáveis X (`X_train`, `X_test)`: O train é para treinar o modelo e o test para testar.
* Variáveis Y (`y_train`, `y_test)`: São os rótulos reais (respostas) que o modelo aprende ou compara.

Elas são usadas desta forma (exemplo com regressão linear):

```python
# Aprender a relação matemática entre as variáveis independentes (X_train) e os
# rótulos (y_train)
linear_regression.fit(X_train, y_train)

# Usa o modelo treinado para fazer previsões com os dados novos (X_test, que ele
# nunca viu antes), aplicando a relação matemática vista acima.
expected_results = lr.predict(X_test)
```

Veja que agora temos os valores obtidos `expected_results` e os valores que deveriam ser obtidos `y_test`, ou seja, podemos comparar um com o outro para calcular o erro!

## Método predict

Esse método vai aparecer em qualquer algoritmo de aprendizado supervisionado, pois é <mark style="color:blue;">responsável por fazer as previsões</mark> com base no modelo de treino-teste criado.

Como visto acima, ele sempre <mark style="color:green;">retorna os resultados esperados</mark> pela previsão. Retornando algo como:

```bash
y_pred = [72.1, 73.5, 74.0, ...]
```

Depois de previsto, esses resultados salvos são usados também para fazer a avaliação do modelo. Esses valores previstos serão comparados com os valores reais, usando qualquer [métrica avaliativa](metricas-avaliativas.md) que seja coerente. Veja nessa página, pois ela é o passo seguinte à predição.

[^1]: Como KNN, regressão linear, etc.
