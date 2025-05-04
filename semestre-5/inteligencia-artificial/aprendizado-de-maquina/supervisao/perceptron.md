# Perceptron

As <mark style="color:purple;">redes neurais</mark> usam um modelo computacional de neurônio chamado&#x20;Perceptron. Ele é uma estrutura inspirada em um neurônio (entrada de sinal e ativação), que resulta em **zero ou um**, e pode ser representada por uma fórmula:

$$
𝑦 = 𝑓 (∑ 𝑊𝑖 ∗ 𝑋𝑖 + 𝑊𝑏 ∗ 1)
$$

<details>

<summary>Explicação da fórmula</summary>

* f() uma função degrau, forçando o resultado a ser 0 ou 1.
* 𝑊𝑏  &#x20;é um peso para uma entrada especial que será discutida em breve.
* A parte interna é uma soma ponderada das entradas, vamos entender como isso  &#x20;funciona, pensando em uma única entrada.

</details>

Essa fórmula gera uma reta no plano cartesiano:

* Ao alterar o peso Wb, a angulatura desta reta se altera.
* Ao alterar o viés[^1], mudamos por onde a reta passa. Caso contrário, ela passa pela origem (0,0).

Essa linha é usada para separar os grupos em seus cortes. Alteraramos o peso ou o viés para ir ajustando as linhas e fazer cortes precisos na separação dos grupos. Em resumo, <mark style="color:blue;">cada linha é um neurônio</mark>.

Muitas vezes não é possível dividir os grupos com apenas uma linha, então podemos inserir mais linhas para criar novas divisões. Curiosidade: não pensar em usar duas linhas foi o que travou o desenvolvimento da IA a muitos anos atrás.

<figure><img src="../../../../.gitbook/assets/image (1).png" alt="" width="263"><figcaption></figcaption></figure>

Os pesos são iniciados com valores aleatórios e sendo ajustados gradualmente. Esse é um exemplo final de perceptron fazendo uma divisão de grupos.

<figure><img src="../../../../.gitbook/assets/image (2).png" alt="" width="309"><figcaption></figcaption></figure>

[^1]: Sinal/dendrito do neurônio, que é constantemente igual a 1 e estará associado a um    &#x20;peso 𝑊b.
