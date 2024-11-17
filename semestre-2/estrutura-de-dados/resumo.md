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

### Anotações para prova

Anotações de como fazer cada método para memorizar.

<table><thead><tr><th width="135">Método</th><th>Lista</th><th>Fila</th><th>Pilha</th></tr></thead><tbody><tr><td>Inserir</td><td>Simples</td><td>Simples  + atualizar ponteiros da fila.</td><td>Simples  + atualizar ponteiros da pilha.</td></tr><tr><td>InserirPos</td><td>Simples se pos==0, percorrer tudo e depois fazer as checagens se não.</td><td>-</td><td>-</td></tr><tr><td>Percorrer</td><td>Imprimir tudo com ponteiro auxiliar (conferir se está vazio).</td><td>Imprimir tudo com ponteiro auxiliar (conferir se está vazio).</td><td>Imprimir tudo com ponteiro auxiliar (conferir se está vazio).</td></tr><tr><td>Buscar</td><td>Percorre tudo e retorna dentro do while o dado se encontrado.</td><td>-</td><td>-</td></tr><tr><td>Remover</td><td>Percorre até achar o dado ou a lista for nula. Checagens depois para conferir se o dado foi encontrado e se anterior==null.</td><td>Remove e ajusta ponteiros. Checa se a fila é nula.</td><td>Remove e ajusta ponteiros. Checa se a pilha é nula.</td></tr><tr><td>Liberar</td><td>Percorre tudo usando free e libera ponteiro também.</td><td>Percorre tudo usando free e libera ponteiro também. Ajusta os ponteiros para NULL.</td><td>Percorre tudo usando free e libera ponteiro também. Ajusta os ponteiros para NULL.</td></tr></tbody></table>

[^1]: Necessário para resgatar quem é o primeiro, que será o nó atendido.

[^2]: Necessário para inserir novos elementos, já que eles são inseridos no final, com:

    `f->last->prox = novo`.
