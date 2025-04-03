# Vetores e matrizes

## Vetores (array)

Um array é uma coleção de elementos do mesmo tipo, armazenados em posições contíguas de memória, igual às outras linguagens. Os vetores são simbolizados por `[colchetes]` que indicam seu índice e a declaração pode ser feita usando `{chaves}`.

O acesso de um elemento é através do índice:

```c
int numeros[12];
int primos[3] = {1, 3, 5};

primos[2] = 7;

printf("O vetor completo é:\n");
for (int i = 0; i < 3; i++) {
    printf("Posição %d: %d", i, primos[i]);
}
```

Aqui podemos ver a declaração informando o tamanho total, uma declaração já com os elementos, manipulação e impressão de elemento por elemento.

## Matrizes

Matrizes são vetores de mais de uma dimensão, basicamente é uma estrutura de dados do tipo vetor com duas ou mais dimensões. Na prática, as matrizes formam tabelas na memória.

Sua declaração consiste em linhas e colunas, que formam uma tabela, isto é: dois índices. Ler todos os elementos pode ser feito <mark style="color:blue;">percorrendo todas as linhas com</mark> <mark style="color:blue;"></mark><mark style="color:blue;">`i`</mark> e depois percorrendo dentro de cada linha <mark style="color:blue;">todas as colunas com</mark> <mark style="color:blue;"></mark><mark style="color:blue;">`j`</mark>, desta forma:

```c
float matriz[3][3];

for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        scanf("%f", matriz[i][j]);
    }
}
```
