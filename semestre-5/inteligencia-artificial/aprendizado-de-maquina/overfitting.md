# Overfitting

Esse fenômeno acontece quando o modelo busca minimizar o erro do treino até quase zero, mesmo que isso signifique ajustar os pesos de forma exagerada, o que exige até aprender ruídos e não o padrão real. Lembrando que o foco de um modelo é buscar a generalização para não aprender tais ruídos.

Então, o overfitting deixa o peso de cada entrada valores absurdos para que a função de perda seja zero, criando curvas malucas. Para combater isso, existe um regularizador (presente em redes neurais), chamado de alpha.

Sua ideia é desestimular o crescimento excessivo dos pesos. Ele faz isso adicionando uma penalização na função de perda:

$$
Loss Total = ErroTreino + alpha * ∑w²
$$

{% hint style="info" %}
* Função de perda: é a função/valor que o modelo está tentando minimizar.
* Gradiente descendente é o que auxilia no ajuste de peso para essa minimização.
{% endhint %}

Veja que o alpha é uma constante e ao ser colocada na fórmula, o modelo passa a aceitar um erro. Alpha é multiplicado pela somatória dos pesos, então se os pesos aumentarem muito na tentativa de ajustar o erro, o resultado será o inverso e o erro vai aumentar.

Ou seja, é como se fosse um limitador de aumento de peso o que resolve o problema inicial: não ter pesos absurdos para causar o overfitting. A parte em verde só entra na função de perda com a existência do alpha, ou seja, se o alpha for menor que zero, a perda não se preocupa com o tamanho dos pesos.

<figure><img src="../../../.gitbook/assets/image (13).png" alt="" width="563"><figcaption></figcaption></figure>

{% hint style="danger" %}
O alpha muito alto causa o processo inverso: o **underfitting**.
{% endhint %}

## Detecção de overfitting

Um overfitting pode ocorrer mesmo usando o K-Fold? A resposta é sim, ela é uma técnica de validação mas o overfitting pode ocorrer ainda dentro de cada fold, contudo, essa técnica consegue mostrar se isso está ocorrendo.

O overfitting obtém ótimos resultados nos treinos mas passa a ir mal na validação. Portanto, usando um gráfico de curva de aprendizado que mostra as linhas de validação e treino podemos inspecionar o gap entre elas. Se o modelo foi bem no treino e mal na validação, isso quer dizer que ele decorou o treino.

Curvas próximas e altas são sinal que convergiu bem. Curvas baixas, mesmo que próximas, são sinal de underfitting.

<figure><img src="../../../.gitbook/assets/image (12).png" alt=""><figcaption></figcaption></figure>
