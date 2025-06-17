# Redes neurais

Uma rede neural é um mecanismo de aprendizado que imita como um cérebro humano aprende. O cérebro recebe o estímulo do mundo exterior, faz o processamento e gera o resultado. À medida que a tarefa se torna complicada, vários neurônios formam uma rede complexa, transmitindo informações entre si. Portanto, a rede neural artificial imita um comportamento semelhante.

## Perceptron

As redes neurais usam um modelo computacional de neurônio chamado&#x20;Perceptron. Ele é uma estrutura inspirada em um neurônio (entrada de sinal e ativação), que resulta em **zero ou um**, que tenta <mark style="color:blue;">decidir se uma entrada pertence a uma classe ou não</mark>.

{% hint style="success" %}
A explicação formal para um perceptron é: neurônio artificial que possui entrada de dados, função de ativação, peso e viés (com soma ponderada). A <mark style="color:purple;">função de ativação</mark> é o que vai ser passado adiante.&#x20;
{% endhint %}

Essas entradas são variáveis de um dado (idade, peso, etc) e cada uma delas tem um peso que simboliza a importância dessa entrada, chamado de `Wi` e começando com **valores aleatórios**. As entradas são somadas com esse peso e se essa soma atingir um certo valor, resulta em um e se for menor, a saída será zero. Essa fórmula é responsável por essa representação:

$$
𝑦 = 𝑓 (∑ 𝑊𝑖 ∗ 𝑋𝑖 + 𝑊𝑏 ∗ 1)
$$

<details>

<summary>Explicação da fórmula</summary>

* f() uma [função degrau](#user-content-fn-1)[^1], forçando o resultado a ser 0 ou 1.
* 𝑊𝑏  &#x20;é um peso para uma entrada especial que será discutida em breve.
* A parte interna é uma soma ponderada das entradas, da mesma forma descrita acima.

</details>

Essa fórmula gera <mark style="color:blue;">**uma reta**</mark> no plano cartesiano:

* Ao alterar o peso Wb, a angulatura desta reta se altera.
* Ao alterar o viés[^2], mudamos por onde a reta passa. Caso contrário, ela passa pela origem (0,0).

<figure><img src="../../../../../.gitbook/assets/image (1) (2).png" alt="" width="263"><figcaption></figcaption></figure>

Essa linha é usada para separar os grupos em seus cortes. Alteraramos o peso ou o viés para ir ajustando as linhas e fazer cortes precisos na separação dos grupos. Em resumo, <mark style="color:blue;">cada linha é um neurônio/perceptron</mark>.

Muitas vezes não é possível dividir os grupos com apenas uma linha como em problemas do tipo XOR, então podemos usar o modelo MLP de redes neurais, que utiliza mais linhas para criar novas divisões. Curiosidade: não pensar em usar duas linhas foi o que travou o desenvolvimento da IA a muitos anos atrás.

## Perceptron Multi Camadas (MLP)

Usa mais de um perceptron (ou chamamos de neurônio artificial) para conseguir fazer divisões precisas, onde <mark style="color:blue;">cada perceptron é responsável por uma região específica</mark>. O conceito de ter entrada de dados processadas em camadas gera o conceito de redes neurais. A MLP é definida quando todos os perceptrons e entradas estão conectados com todos os outros da camada anterior e posterior.

A rede será formada por três camadas, cada camada representada por uma cor, e os círculos são os neurônios:

* Camada de entrada: Não há neurônios, apenas as entradas de dados e o total é o número de features[^3]. Eles só repassam o dado e só pode haver uma única camada de entrada.
* Camada de saída: O número de neurônios é o número de classes que podem haver nos rótulos. Também apenas uma camada.
* Camada escondida: Não existem restrições para a quantidade de camadas escondidas e nem de neurônios, depende das transformações a serem feitas.

<figure><img src="../../../../../.gitbook/assets/image (9).png" alt=""><figcaption></figcaption></figure>

### Função dos neurônios

Cada neurônio é como se fosse um aluno em um projeto: tem a sua respectiva função. Um neurônio fica responsável por detectar círculos e outro por retas.&#x20;

Os neurônios fazem transformação linear na entrada (a fórmula mostrada no perceptron), que é a combinação ponderada das entradas somado com o viés. Recapitulando, uma transformação linear resulta em uma reta, não podendo separar grupos complexos. Para conseguir uma transformação não linear, esse resultado é passado para uma <mark style="color:purple;">função de ativação</mark>.

### Função de ativação

A função de ativação pega o resultado da transformação linear (chamamos de `z`) e joga em sua própria fórmula. Essa transformação não linear é capaz de criar retas e curvas. Ela <mark style="color:blue;">resulta em um dado matemático, usado para passar informação adiante</mark> e que seu significado [depende do tipo de função ativação utilizado](#user-content-fn-4)[^4].

Se esse neurônio estiver na camada de saída, esse resultado matemático é a saída da rede (a predição). Esse valor de saída será comparado com o valor real, calculando um erro, seguindo para o passo de <mark style="color:purple;">backpropagation</mark>.

<figure><img src="../../../../../.gitbook/assets/image (1) (1).png" alt=""><figcaption></figcaption></figure>

#### Função de etapa binária

Essa função é apenas para aprender teoria, que é a função usada no modelo do Perceptron no surgimento dele. É uma função que resulta em zero ou um, criando uma função degrau. Por isso que elas não conseguem resolver problemas não linearmente separáveis, pois são retas.

A derivada de uma função degrau é zero, pois não há inclinação. Por conta disso, a função degrau não fornece gradiente útil, e como o gradiente é a base matemática para o ajuste dos pesos durante o treinamento, redes modernas usam gradiente contínuo e útil.

#### Função linear `identity`

É raramente usada em camadas ocultas, pois a derivada de uma função linear é uma constante. Isso quer dizer que o gradiente seria o mesmo em todo o backpropagation. Se o gradiente é o mesmo, não teremos melhora no erro.

Então a saída com essa função é uma transformação linear da entrada, o que pode ser útil para algoritmos simples de separação linear.

#### Sigmóide `logistic`

Essa função amplamente utilizada varia dos valores de zero a um e faz um formato de S, que pode ser entendida como o fato de tentar empurrar os valores resultantes para a extremidade, o que facilita a identificação de classes. Portanto, lembra a função binária mas não é linear e existe sim seu gradiente.

O problema dessa função é que ela pode tornar o gradiente muito pequeno quando o valor está muito próximo de zero ou um (pois é um S e quase não tem inclinações). O gradiente que é um fator de 3 valores incluindo a função ativação, se multiplicado a uma função ativação muito baixa, consequentemente se torna pequeno.

O problema do gradiente baixo é que ele não é capaz de ajustar pesos (gradiente baixo ≠ erro baixo). Com o gradiente baixo, o erro não muda muito mesmo ajustando os pesos. Veja matematicamente:

> Erro = 12
>
> Wnovo = (w - n) \* gradiente
>
> Deltaw = (0.1) \* 0.00001 = 0.000001 -> Veja que o peso não mudou quase nada.

#### Tanh `tanh`

Funciona de forma igual à sigmóide mas deixa simétrico em relação à origem, então varia de -1 até 1, resolvendo o problema dos valores não podendo ser negativos.

Não ter negativos pode ser um problema. A possibilidade de poder ter resultados negativos permite que os pesos possam se ajustar de forma livre, para cima ou para baixo dependendo da direção do erro. Além disso, ter um intervalo menor ajuda no problema de gradientes pequenos, o que também são chamados de vanishing gradients.

#### ReLu `relu`

É a função mais popular atualmente, pois o fluxo matemático dela favorece os gradientes e é bem simples: se o resultado dessa função ativação for negativo, a derivada da relu será `0` e caso contrário será exatamente igual a `1`.

O valor de zero vai inibir que neurônios irrelevantes participem do aprendizado, evitando perda de tempo ajustando peso de neurônios mortos. E quando está na parte positiva, não atrapalha o gradiente pois ele é igual a 1 e qualquer coisa multiplicada a 1 dá ele mesmo.&#x20;

<figure><img src="../../../../../.gitbook/assets/image (1).png" alt=""><figcaption></figcaption></figure>

O gradiente sendo igual a 1 indica ser muito mais forte e permite um fluxo mais saudável no backpropagation.

### Backpropagation

durante o backpropagation, as atualizações dos pesos são influenciadas pelo gradiente da função de ativação.



### Gradiente descendente

Cada neurônio tem a sua entrada de pesos e a modificação de pesos vai alterar o erro da rede (a tal função de perda). Ou seja, alterar os pesos corretamente vão fazer com que o erro melhore e o modelo aprenda.

Agora que temos o valor desse erro, calculado nos neurônios de saída, o gradiente descendente é o método para <mark style="color:blue;">ajustar os pesos da entrada para minimizar esse erro</mark>. Ele é executado dentro de cada neurônio, pois o gradiente é a <mark style="color:blue;">derivada da função de perda em relação ao peso respectivo daquele neurônio</mark>. Mas o que esse valor quer dizer?

!!! IMAGEM DO aL/aW (se mudar isso, vai afetar isso)

A função de perda (erro total da rede) é um gráfico de uma curva que remete a uma parábola, onde consequentemente o menor erro fica no ponto mais em baixo que é a descida (por isso chamado de descendente). Podemos achar esse erro pois a derivada no menor ponto é igual a zero.

<figure><img src="../../../../../.gitbook/assets/image (5).png" alt=""><figcaption></figcaption></figure>

O resultado de gradiente descendente é um número que <mark style="color:blue;">indica a inclinação do ponto atual do peso</mark> em relação a essa curva. Sabendo dessa inclinação, sabemos qual a direção que o ponto precisa caminhar para alcançar a derivada zero, que é o ponto mínimo. A derivada é zero pois no ponto mínimo ela forma uma reta. Portanto, se a reta tem alguma inclinação:

* Baixo: quer dizer que precisamos avançar o ponto.
* Cima: quer dizer que precisamos recuar o ponto.

<figure><img src="../../../../../.gitbook/assets/image (8).png" alt="" width="563"><figcaption></figcaption></figure>

Sabendo dessa direção, o ponto vai caminhar. O modelo vai resgatar o learning rate, que é o tamanho do passo, e andar um montante em direção ao ponto de inflexão, o que também significa ajustar o peso.

<figure><img src="../../../../../.gitbook/assets/image (14).png" alt=""><figcaption></figcaption></figure>

!!! IMAGEM ANDANDO NO GRÁFICO

Então esse peso foi ajustado. Se o peso mudou, segue em frente com a rede neural (o mesmo ciclo inicial), até chegar nas camadas de saída, gerar um novo erro e repetir esse processo novamente. Basicamente, o gradiente responde depois do backpropagation: se eu mudar um pouco este peso, o erro da rede vai aumentar ou diminuir? E quanto?

!!! IMAGEM DO GRÁFICO DO MEU PAPEL, aL/aW = 0

{% hint style="info" %}
## Matematicamente falando

Matematicamente, o gradiente envolve a derivada da função de perda, derivada da ativação, e derivada da transformação linear (pelo peso).
{% endhint %}

#### Solver

Decide como aplicar o gradiente descendente, mas independente das formas, usam o valor resultado pelo cálculo do gradiente, o que muda é o depois.

* SGD (Stochastic Gradient Descent) é o método clássico e tradicional, visto acima.
* ADAM é um modelo que ajusta o learning rate.

O método ADAM é menos sensível à escolha do learning rate. Seu principal trabalho é ajustar o fator de aprendizagem baseado no contexto. Ele é um dos modelos mais usados por ser muito mais rápido, já que ajusta, fica mais rápido de convergir.

O learning rate base não é alterado, ele inicia naquele valor e modula automaticamente os tamanhos do passo. Esse ajuste é para cada peso individualmente. Com uma lógica básica, se o gradiente for estável vai aumentando o passo e ser for instável diminui.

Basicamente, ajusta baseado no passo que deveria dar. E ele faz isso usando médias: histórico da média dos gradientes e a variância desse histórico.

#### Fator de aprendizado

Vendo que precisamos mover o peso para atingir o menor erro, o fator de aprendizado é o tamanho do passo dado até a descida. Passos muito largos vai fazer com que sempre passe o menor ponto e passos curtos vai custar na otimização do algoritmo.

Esse é um exemplo final de perceptron fazendo divisão de grupos:

<figure><img src="../../../../../.gitbook/assets/image (2) (2).png" alt="" width="309"><figcaption></figcaption></figure>

### Batch size

O **batch size** define a quantidade de amostras que a rede neural processa antes de realizar uma atualização dos pesos durante o treinamento. Em vez de calcular o gradiente e ajustar os pesos após cada exemplo individual, o modelo agrupa um número específico de exemplos (o batch), calcula a média da perda e dos gradientes sobre esse grupo, e só então atualiza os pesos.

Isso ajuda a equilibrar o custo computacional e a estabilidade do treinamento, permitindo que o modelo faça atualizações mais frequentes (se o batch for pequeno) ou gradientes mais estáveis (se o batch for maior), controlando a velocidade e a qualidade do aprendizado.

O segundo batch inicia com os pesos calculados para o primeiro batch. Então o segundo batch vai para as camadas de entrada com os pesos calculados para o batch 1 e assim sucessivamente. Um batch não se junta com o outro.

O `max_iter` são os ciclos/épocas. Significa quantas vezes o processo **completo** irá se repetir até ser encerrado, ou se convergir primeiro com `early_stopping`. Se temos 100 `batchs` e 1000 `max_iter`:

* Isso quer dizer que vamos mandar o batch 1 até o 100, isso será o max\_iter 1 ou primeiro ciclo.
* Repetir esse MESMO processo, iniciando do batch, mais 999 vezes.

### Regularização

Representado pelo parâmetro alpha α é uma técnica para combater overfitting.&#x20;

### Aplicação prática e variação de parâmetros

A variação da camada escondida ajuda na detecção de padrões, mas tem que tomar cuidado com o overfitting. Esses números representam quantos neurônios em cada camada escondida, então números agregados quer dizer mais de uma camada.

Quanto mais camadas, maior a chance de aprender funções não lineares complexas. A diminuição de valores é para criar um funíl forçando o algoritmo a resumir as informações. Quanto mais camadas, mais dados são requeridos.

```python
'hidden_layer_sizes': [
    (200,), (100,), (50,), (200,100), (200,100,50), (200,100,50,25)
]
```

As funções de ativação dos perceptrons em redes neurais não se limitam apenas no binário zero e um (aquelas chamadas de função degrau). Essas funções retornam valores contínuos. A função `relu` é a mais usada por ser eficiente e funcionar como `max(0, x)`. Já a `tanh` suaviza os dados retornando entre -1 e 1.

```python
'activation': ['relu', 'tanh']
```

Os parâmetros `solver` + `learning_rate_init` + `alpha` servem para a atualização dos pesos.

* Solver: algoritmo usado para fazer o gradiente descendente, definindo como o erro é corrigido.&#x20;
  * `'adam'`: adaptativo, ajusta o aprendizado ao longo do tempo, muito usado hoje.
  * `'sgd'`: gradiente estocástico puro. Mais lento, mas mais simples e te dá mais controle.
* Alpha: não varia, deixando um valor bem baixo que faz penalidades leves para os pesos.
* Learning rate init: É o tamanho dos passos dados para o gradiente descendente. Lembrando que existe aquele dilema entre valores altos e baixos.

```python
'solver': ['adam', 'sgd'],
'alpha': [0.0001],
'learning_rate_init': [0.001, 0.01, 0.1]
```

Podemos definir a cada quantas amostras de treino o algoritmo vai fazer a atualização dos pesos. O algoritmo passa por todas as camadas e faz todo o seu percurso, mas usando a quantidade definida de amostras em `batch_size`. Quanto maior, mais estável.

```python
'batch_size': [8, 16, 32, 64]
```

Por fim, algo já visto em validação, o embaralhamento de dados a [cada época](#user-content-fn-5)[^5] para evitar decorar ordem de dados com shuffle. Não embaralhar pode ser bom para dados que podem ser afetados por sequências temporais.

```python
'shuffle': [True, False]
```

#### Aplicação do resto do algoritmo

Define o máximo de épocas. 1000 significa que o modelo pode passar até mil vezes pelos dados de treino, mas se convergir antes, o modelo vai parar. Convergir significa que em X iterações (podendo ser definido no parâmetro n\_iter\_no\_change) não ter melhora significativa no F1-score, o modelo é interrompido automaticamente.&#x20;

```python
mlp = MLPClassifier(
    max_iter=1000,
    early_stopping=True,
    random_state=42
)

grid_search_mlp = GridSearchCV(
    estimator=mlp,
    param_grid=param_grid_mlp,
    scoring='f1_weighted',
    cv=5,      # usa validação cruzada com 5 folds para avaliar a performance
    verbose=1, # usa todos os núcleos do processador
    n_jobs=-1  # imprime progresso no terminal
)
grid_search_mlp.fit(X_train, y_train)
```

[^1]: Retorna zero ou um.

[^2]: Sinal/dendrito do neurônio, que é constantemente igual a 1 e estará associado a um    &#x20;peso 𝑊b.

[^3]: Colunas da base de dados sem contar o rótulo.

[^4]: Os tipos de ativação são especificados adiante. Cada um deles é usado com um propósito diferente, por isso fica difícil definir certamente.

[^5]: Ciclo completo de treino.
