# Critérios externos

## Rótulos categóricos

Abordagens que funcionam apenas para esses rótulos, como por exemplo, se o label da base de dados pode ser definido como satisfeito ou insatisfeito em um histórico de clientes.

### Matriz de confusão

Mostra quantos exemplos o modelo acertou e errou por classe e é excelente para ver onde o modelo faz confusão. Cada rótulo se identifica como positivo ou negativo e a matriz identifica para qual lado somar.

Normalmente, define-se como rótulo positivo aquela classe mais importante de se buscar, como se fosse um booleano. Nisso, juntamos nossos resultados em uma <mark style="color:purple;">matriz de confusão</mark>, que compara o que nosso modelo previu com o que está no padrão-ouro:

* Modelo previu positivo e no padrão-ouro também é positivo: ✅ **True Positive** `TP`
* Modelo previu negativo e no padrão-ouro também é negativo: ✅ **True Negative** `TN`
* Modelo previu positivo, mas no padrão-ouro era negativo: ❌ **False Positive** `FP`
* Modelo previu negativo, mas no padrão-ouro era positivo: ❌ **False Negative** `FN`

A cada ocasião, vai somando para cada variável. Então, se nosso algoritmo acertou a formação de uma dupla, soma +1 para `TP` e assim vai. E então, montamos a nossa matriz:

<figure><img src="../../../../.gitbook/assets/matriz confusão.png" alt="" width="563"><figcaption></figcaption></figure>

{% hint style="warning" %}
Nem sempre segue essa ordem. As vezes pode começar com true negative, mudar o eixo, etc. As fórmulas se mantém as mesmas, mas é preciso tomar cuidado com a ordem da matriz.
{% endhint %}

Com esses dados prontos, podemos incluir em fórmulas e chegar a um <mark style="color:blue;">relatório final de métricas</mark>. Podemos incluir o valor resgatado de cada métrica abaixo, pois, levar apenas uma em consideração, não é recomendado. O melhor cenário é usar **F1-score como métrica de validação final** e plotar gráficos e comparar as demais.

<table><thead><tr><th width="154">Nome</th><th width="383">Utilização</th><th>Fórmula</th></tr></thead><tbody><tr><td>Precisão</td><td>Porcentagem de acerto quando rotulou como positivo.</td><td>a / a + b</td></tr><tr><td>Acurácia</td><td>Mede a relação entre acerto e erro, considerando todos os pares.</td><td>a + d / a + d + b + c</td></tr><tr><td>Sensibilidade</td><td>Mede a capacidade do modelo de identificar corretamente as amostras <a data-footnote-ref href="#user-content-fn-1">positivas</a>.</td><td>a / a + c</td></tr><tr><td>Especificidade</td><td>Mede a capacidade do modelo de identificar corretamente as amostras <a data-footnote-ref href="#user-content-fn-2">negativas</a></td><td>d / d + b</td></tr><tr><td>F1-score</td><td>Média <a data-footnote-ref href="#user-content-fn-3">harmônica</a> entre precisão e sensibilidade</td><td>2 * a / 2 * a + b + c</td></tr></tbody></table>

#### Exemplo real

Os campos coloridos são **os acertos**: true negative ou true positive, depende da classe daquela posição da matriz. Eles não estão coloridos por ser o quadrado de acerto, mas a coloração é feita automática pela quantia de valores no quadrado.

<figure><img src="../../../../.gitbook/assets/matriz de confusão ex real.png" alt=""><figcaption></figcaption></figure>

Olhando apenas para esse gráfico, conclui que o modelo não está apenas "chutando" predominantemente algum valor. De forma clara, os números mostram um equilíbrio razoável e justificável entre as classes positivas e negativas, o que indica que o modelo não está tendencioso, mas ainda é obrigatório analisar as demais métricas e gráficos para uma conclusão mais precisa.

### Acurácia

Mede em porcentagem quanto o modelo acertou, de forma simples, acertos dividido pelo total resultando em uma porcentagem. A acurácia **não é usada como métrica final** pois não pondera os positivos e não é recomendada para datasets desbalanceados.

$$
Acurácia = TP+TN/TP+TN+FP+FN
$$

### Sensibilidade

Mede a capacidade do modelo de identificar corretamente as&#x20;amostras positivas. Detectar amostras positivas é a parte mais importante em rótulos categóricos, então não conseguir passa a ser algo mais grave. A responsabilidade da sensibilidade é medir isso.

Contudo, se o modelo chutar apenas positivo, isso resultará em sensibilidade de 100% e é por isso que essa métrica não é útil para ser olhada sozinha. É excelente para ser juntada com precisão (isso acontece no f1-score).

$$
Sensibilidade = TP/TP+FN
$$

### Especificidade

Mede a capacidade do modelo de identificar corretamente as&#x20;amostras negativas. Segue a mesma lógica da sensibilidade mas caso o contexto um falso positivo seja algo muito crítico, como um alarme falso de uma fraude bancária.

Segue o mesmo esquema da sensibilidade que, sem usar a precisão ao lado, seu valor não tem muito sentido pois o modelo pode começar a chutar tudo negativo e conseguir especificidade de 100%.

$$
Especificidade = TN/TN+FP
$$

### Precisão

Das vezes que o modelo previu que era positivo, quantas vezes ele estava certo? Essa medida é usada para conseguir calcular o que de fato chamamos de **confiabilidade**, entender se está errando essas identificações e se podemos confiar neste modelo.

$$
Precisão = TP / TP + FP
$$

### F1-score

Média harmônica (sem favorecer nenhuma métrica) entre precisão e sensibilidade, usado como métrica final para medir a qualidade do modelo. Como visto, sensibilidade sozinha é ilusório pois pode sacrificar a precisão para conseguir o valor de 100%.

O F1-score vai medir o quanto sensível pode ser se mantendo preciso, uma métrica que equilibra os fatores mais importantes quando detectar uma amostra positiva é muito válido.

$$
F1score = 2 * precisao *sensibilidade/precisao+sensibilidade
$$

#### Curva Precisão-Sensibiliade (Precision-Recall)

Existe uma curva entre precisão x sensibilidade que é muito importante ser plotada em conclusões de análises de machine learning. Colocando a precisão no eixo Y e a sensabilidade no eixo X, essa curva exibe <mark style="color:blue;">quantos positivos conseguem ser capturados sem sacrificar a precisão</mark>. Que é basicamente o que a métrica F1-score faz.

Essa curva mostra o trade-off entre precisão e recall para mostrar esse equilíbrio. Quanto mais inclinada, pior o equilíbrio entre os pontos e por isso, a análise do gráfico conclui que a curva laranja (respectiva à MLP) é muito melhor, pois consegue ter um maior valor de sensibilidade sem sacrificar a precisão. O ideial é ter ambos os valores próximos de 1, isso quer dizer, a curva que consegue se manter lá em cima por mais tempo.

Ambas as curvas chegam ao mesmo valor no final, isso porque, para conseguir sensibilidade igual à 1, isso exige muitos chutes. Esse valor é próximo de 0,5 o que está relacionado à distribuição de dados do dataset utilizado, cada base de dados pode retornar algo diferente.

<figure><img src="../../../../.gitbook/assets/precisão x sensibilidade.png" alt=""><figcaption></figcaption></figure>

[^1]: Útil em problemas onde é mais crítico detectar a classe positiva, como diagnóstico    \
    médico.

[^2]: Essencial quando um falso positivo pode ser problemático (ex: alarme falso de    \
    fraude bancária).

[^3]: É útil quando há um desequilíbrio entre as classes e não queremos favorecer uma    \
    métrica sobre a outra.
