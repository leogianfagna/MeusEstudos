# Resumo

## Formas estruturais

<figure><img src="../../.gitbook/assets/estrutura de dados.png" alt=""><figcaption></figcaption></figure>

### Modo de uso

* **Lista**: Um ponteiro na main sempre guarda o primeiro elemento da lista.
  * Novo nó aponta para quem estava em primeiro.
* **Fila**: Nenhum ponteiro é usado na main.
  * Novo nó sempre aponta para NULL.
  * Resgate do que é necessário é feito através dos ponteiros first[^1] e last[^2].
  * Mudanças na fila atualizam os ponteiros first e last.
* **Pilha**: Nenhum ponteiro é usado na main.
  * Novo nó aponta para o que estava no topo.
  * Resgata o topo através do ponteiro top.
  * Mudanças na pilha atualizam o topo.

[^1]: Necessário para resgatar quem é o primeiro, que será o nó atendido.

[^2]: Necessário para inserir novos elementos, já que eles são inseridos no final, com:

    `f->last->prox = novo`.
