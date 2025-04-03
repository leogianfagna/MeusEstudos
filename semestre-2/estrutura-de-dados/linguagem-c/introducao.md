# Introdução linguagem C

Todo programa em C começa com uma função chamada `main()`, que é o ponto de entrada do programa. Os códigos começam com inclusão/importação de bibliotecas, como é muito comum vermos a biblioteca `#include <stdio.h>`, responsável por imprimir dados na tela e outras coisas básicas.

A função main() é do tipo inteiro, ou seja, ela sempre deve retornar algo desse tipo. Retornar zero simboliza que o código foi bem sucedido.

## Código englobando o básico

Esse código vai englobar os seguintes conceitos para entendermos como funciona nessa linguagem:

* Importação de bibliotecas: feito com hashtag no início.
* Tipos primitivos: no caso int e float.
* Uso do `%d` que simboliza o espaço de uma variável dentro das aspas, tanto para imprimir um dado quando para ler com scanf.
  * Na hora de escanear, colocamos um `&` antes do nome da variável.
* Chamada de funções, onde precisa declarar as funções inicialmente, diferente de outras linguagens.
  * A declaração de uma função informa ao compilador sobre o nome da função, o tipo de retorno e os parâmetros que ela aceita.
* O restante é basicamente o mesmo.

```c
#include <stdio.h>

// Declara as funções
int encontrarMaior(int a, int b, int c);
float calcularMedia(int a, int b, int c);

int main() {
    int num1, num2, num3, maiorNumero;
    float media;
    
    printf("Insira 3 números inteiros");
    scanf("%d %d %d", &num1, &num2, &num3);
    
    maiorNumero = encontrarMaior(num1, num2, num3);
    media = calcularMedia(num1, num2, num3);
    
    printf("O maior número é %d\n", maiorNumero);
    printf("A média dos números é %.2f", media);
    
    return 0;
}

int encontrarMaior(int a, int b, int c) {
    int maiorEncontrado = a;
    
    if (b > maiorEncontrado) maiorEncontrado = b;
    if (c > maiorEncontrado) maiorEncontrado = c;
    
    return maiorEncontrado;
}

float calcularMedia(int a, int b, int c) {
    return mediaCalculada = (a + b + c) / 3.0;
}
```
