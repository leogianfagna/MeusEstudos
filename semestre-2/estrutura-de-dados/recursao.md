# Recursão

A palavra recursão refere-se a repetição de algo do mesmo jeito que já foi mostrado anteriormente. Em computação, é uma função que chama a si mesmo, mas essa função deve possuir um <mark style="color:blue;">critério de parada</mark> pois ela não pode se chamar infinitamente. Um fatorial é um exemplo de recursão.

Chamar a própria função novamente geralmente é mais lento do que implementar uma lógica de repetição. Isso fica apenas vantajoso quando não precisa fazer códigos repetidos, que são casos muito específicos que não veremos aqui.

## Como uma recursão funciona

A **filosofia** da recursão consiste em, toda vez que chama a própria função novamente, <mark style="color:blue;">todo o código anterior entra em espera</mark>. Ao terminar todas as recursões, o código vai retrocedendo resultado por resultado até chegar na atribuição.

<figure><img src="../../.gitbook/assets/caminhos e filosofia da recursão.png" alt=""><figcaption></figcaption></figure>

Vemos aqui que em todas as chamadas exceto a última, temos um `fat = n * fatorial(...)`. Isto é, a variável recebe um valor que é o retorno da função, então temos que esperar o resultado dessa função para atribuir.

Só que, na função de baixo a situação é a mesma. Então isso se repete até que chegue na última chamada, no nosso caso, a terceira. Assim, todos os `fat`, que estão em vermelho, ficam esperando para serem atribuídos.

Ao chegar na última, as setas rosas indicam que o valor começa a subir, atribuindo uma por uma até chegar na primeira. Assim, temos o resultado do fatorial feito através de recursão.

O código por inteiro fica:

```c
int fatorial(int n) {

    if (n == 1) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}


int main() {
    int numFatorial;
    
    printf("Escolha um número para fatorial: ");
    scanf("%d", &numFatorial);
    
    printf("Resultado = %d", fatorial(numFatorial));
    return 0;
}
```
