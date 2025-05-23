# Análise bivariada

Analisa se existe relação entre variáveis `x` e `y`. Gera uma representação gráfica diagrama de dispersão, que indica uma relação positiva, negativa ou sem relação.

## Coeficiente de relação de Pearson

Uma fórmula que ao ser calculada vai retonar um valor de -1 a 1 no máximo. Para resolver, monte uma tabela com os dados x ao lado do y, e preencha (sendo `i` a linha do dado):

* Xi \* Yi
* Xi²
* Yi²

<figure><img src="../../.gitbook/assets/tabela pearson.png" alt=""><figcaption></figcaption></figure>

Depois, substitua na fórmula oficial do coeficiente de Pearson, que vai buscar a correlação do dado x com o dado y:

<figure><img src="../../.gitbook/assets/formula pearson.png" alt=""><figcaption></figcaption></figure>

Os símbolos do somatório quer dizer o valor resultante do somatório de toda a coluna respectiva e n simboliza o número de amostras da nossa base sendo estudada. Levando `n` como 3 no nosso exemplo, a fórmula ficaria dessa maneira com as substituições:

<figure><img src="../../.gitbook/assets/resolvendo pearson.png" alt=""><figcaption></figcaption></figure>

Depois de substituído, apenas continuar com as contas (multiplicações, subtrações, raíz e divisão).&#x20;

### Interpretação

Para interpretar de forma qualitativa, seguimos a seguinte tabela:

<table><thead><tr><th width="209">Coeficiente de correlação</th><th>Grau de correlação</th></tr></thead><tbody><tr><td>0</td><td>Inexistente</td></tr><tr><td>0,0 - 0,3</td><td>Fraca</td></tr><tr><td>0,3 - 0,6</td><td>Regular</td></tr><tr><td>0,6 - 0,9</td><td>Forte</td></tr><tr><td>0,9 - 1,0</td><td>Muito forte</td></tr><tr><td>1</td><td>Perfeita</td></tr></tbody></table>

## Reta de regressão linear

Calcula a reta que atravessa o gráfico de dispersão <mark style="color:blue;">melhor representando os dados</mark> (com menos erro). Com ela, podemos fazer previsões:

* Interpolar ou extrapolar informações.
* Se tem a reta, podemos achar Y (valor dependente) simulando um X (valor independente).

### Fórmula da reta

Sendo A (coeficiente angular: altera a inclinação da reta, acréscimo em Y para cada unidade de X) e B (coeficiente linear: valor de Y quando X=0) pontos dispersos, cada ponto possui a sua fórmula que deve ser calculado e substituído na seguinte fórmula da reta:

$$
y = Ax + B
$$

### Fórmulas dos coeficientes

Basta substituir os mesmos valores encontrados na tabela de correlação de Pearson aqui e temos os valores de A e B.

<figure><img src="../../.gitbook/assets/coeficientes em regressão linear.png" alt=""><figcaption></figcaption></figure>

Depois de encotrado esses valores, basta substituímos A e B na fórmula da reta acima, resultando algo do tipo `y = 3,5x + 6`.
