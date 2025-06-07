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

## K-Fold

Para conseguir o melhor aprendizado de máquina, é crucial a [variação de parâmetros](#user-content-fn-2)[^2] e comparação de estatísticas de avaliação. O K-Fold é uma <mark style="color:blue;">técnica para ajudar escolher os melhores parâmetros</mark> que vamos utilizar.

Acontece que é comum utilizar a própria base de dados de treino para ficar treinando o modelo e encontrar os parâmetros, como:

```python
# Variando parâmetros para KNN
for metric in ['euclidean', 'manhattan']:
    for weights in ['uniform', 'distance']:
        for k in range(1, max_k + 1, 2):
            knn = KNeighborsClassifier(n_neighbors=k, weights=weights, metric=metric)
            
            # Treinando com os dados de treino e validando com os de teste
            knn.fit(X_train, y_train)
            y_pred = knn.predict(X_test)
            
            # Salva a estatística obtida
            acc = accuracy_score(y_test, y_pred)
```

Utilizar toda essa base pode dar uma falsa acurácia. Talvez, toda essa base com essa combinação[^3] gere uma boa acuácia mas ela pode não se desenvolver legal com dados reais. O K-Fold vai deixar isso mais robusto, dando certeza a escolha dos parâmetros.

{% hint style="success" %}
Mudar os dados para o treinamento vai consequentemente mudar o aprendizado. O K-Fold vai mudar os dados para conseguir diferentes treinamentos.
{% endhint %}

### Como funciona

Esse algoritmo divide **toda a base** (inclui treino e teste) em K partes. Uma das partes será destinada para o treino e o restante para o teste, da seguinte forma (em um exemplo para 4 folds):

<figure><img src="../../../../.gitbook/assets/divisao de folds.png" alt=""><figcaption></figcaption></figure>

{% hint style="info" %}
Veja que não segue uma ordem os dados: o teste as vezes está antes, ou no meio ou no final. Não apenas no K-Fold mas em qualquer base, a <mark style="color:green;">ordem não importa</mark> a menos que seja séries temporais ou condições baseadas em datas.

Embaralhar é uma ótima opção por conseguir evitar viés, quando por exemplo, os dados de um determinado intervalo são explicados por algo que aconteceu naquele determinado tempo. Até existe o parâmetro `shuffle` para ser alterado.
{% endhint %}

Cada combinação vai rodar o `fit` e será rodado K vezes, isso porque ele vai testar cada fold. Então, se temos 10 combinações e 4 folds, isso quer dizer que o algoritmo roda 40 vezes, por isso a demora.

Cada fold rodado vai gerar métricas (que variam se o rótulo é contínuo ou categórico). Essas métricas geram a métrica final baseado na média entre todas elas. Isso vai evitar usar [<mark style="color:purple;">hiperparâmetros</mark>](#user-content-fn-4)[^4] que só funcionam bem em um split específico, e vai forçar usar os hiperparâmetros que funcionam bem de maneira consistente.

Isso porque testou diferentes intervalos e ainda gerou uma média entre eles. Veja um exemplo de rodar uma combinação X:

<figure><img src="../../../../.gitbook/assets/metricas robustas.png" alt=""><figcaption></figcaption></figure>

Isso mostra que a combinação X não é tão boa quanto implicaria fazer o teste apenas com a divisão treino e teste. Portanto, isso comprova que o K-Fold <mark style="color:blue;">garante a escolha de hiperparâmetros robustos</mark>.

### Como usar (GridSearch)

É importante lembrar que essa técnica é de validação e não de teste final. Ou seja, o último `fit` do modelo final é usando os 80% de dados para o treino, então essa divisão de treino e teste deve existir do mesmo jeito.

Se a gente fizesse o K-Fold para treinar com fit, isso não iria sobrar nada para testar (pois não ia ter dados dedicados para os testes pois todos eles passaram uma vez pelo treino). Além disso, ia causar o overfitting pois o modelo foi otimizado em cima de todo o dataset, inclusive aqueles dados que deveriam ser apenas para teste.

Portanto, o K-Fold vem na etapa inicial do algoritmo, antes de treinar o modelo ideal. Para isso, utilizamos o método `GridSearch`, responsável basicamente por tudo:

* Gerar todas as combinações possíveis com os hiperparâmetros especificados.
* Treina e testa! Basicamente, faz o algoritmo inteiro.
* Gera as métricas de resultado. Portanto, sabe os melhores modelos.

Esse método exige algumas especificações como: quantos folds, qual algoritmo e qual métrica será usada. Tudo isso depende do algoritmo que estamos lidando.

> Quantos folds é um número ideal?

Ele ainda retorna um objeto após o `fit` com diversas propriedades para ser usadas, podendo resgatar quais foram os melhores parâmetros, a melhor busca e muitos outros. Sua implementação segue essa ordem:

```python
# Variação de parâmetros escolhidos pelo programador
param_grid = {
    'hidden_layer_sizes': [(50,), (100,)],
    'activation': ['relu', 'tanh'],
    'solver': ['adam', 'sgd'],
    'alpha': [0.0001],
    'learning_rate_init': [0.001, 0.01],
    'batch_size': [32, 64],
    'shuffle': [True],
}

# Modelo base, neste caso com MLP
mlp = MLPClassifier(
    max_iter=1000,
    early_stopping=True,
    random_state=42
)

# Passando de parâmetros as melhores escolhas para algoritmos de MLP
grid_search = GridSearchCV(
    estimator=mlp,
    param_grid=param_grid,
    scoring='f1_weighted',
    cv=3,
    verbose=1,
    n_jobs=-1
)

# Treino final
grid_search.fit(X_train, y_train)

# Melhor modelo
best_mlp = grid_search.best_estimator_
y_pred_mlp = best_mlp.predict(X_test)

# Outras propriedades interessantes
# grid_search.best_params_
# grid_search.cv_results_
```

[^1]: Como KNN, regressão linear, etc.

[^2]: Número de K para KNN, número de camadas escondidas para MLP e assim vai.

[^3]: Vamos chamar de combinação uma iteração com parâmetros, por exemplo:

    * Métrica 'euclidian'
    * Peso 'distance'
    * K sendo '7'

[^4]: Palavra utilizada para os parâmetros que variamos nos modelos.
