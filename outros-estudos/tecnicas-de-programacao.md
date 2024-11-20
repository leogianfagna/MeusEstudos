---
description: Veja técnicas inteligentes de programação.
---

# Técnicas de programação

#### Acrescentar direto no sumário de um vetor

Podemos substituir a linha de acrescentar uma unidade na variável direto no sumário, na hora de resgatar o valor de um vetor.

```java
String variavelDaVez;
int posicao = 15;

// Exemplo original
for (int i = 0; i < 10; i++) {
    variavelDaVez = vetor[posicao];   // vetor[15]
    posicao++;                        // posicao = 16
}

// Resgata a variável do vetor e depois acrescenta uma nova unidade
for (int i = 0; i < 10; i++) {
    variavelDaVez = vetor[posicao++]  // vetor[15]
                                      // posicao = 16
}

// Acrescenta uma nova unidade ANTES e depois resgata a variável do vetor
for (int i = 0; i < 10; i++) {
    variavelDaVez = vetor[++posicao]  // posicao = 16 e vetor[16]
}
```

#### For infinito

Faz um `for` executar infinitamente e usa `break` para sair quando quiser.

```java
// Testado em Java
for (;;) {
    break;
}
```

#### Iterar sobre itens

Usar `T item : itens` como parâmetro de um for para passar por cada elemento dentro de uma classe armazenadora.

```java
// Testado em Java
public class ColecaoGenerica<T> {
    private List<T> itens;
    
    private void exibirItens() {
        for (T item : itens) {
            System.out.println(item);
        }
    }
}
```
