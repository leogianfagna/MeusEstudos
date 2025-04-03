# String copy

```c
strncpy(destino, origem, tamanho);
```

A estrutura abaixo:

* Primeira linha: copia o que está no vetor nome para o `novo->nome`, diminuindo em um o espaço para evitar que ultrapasse o tamanho alocado.
* Segunda linha: Define o último caractere da string `novo->nome` para `'\0'`, o que simboliza o fim de uma string.

```c
const char *nome[50];

strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
novo->nome[sizeof(novo->nome) - 1] = '\0';
```
