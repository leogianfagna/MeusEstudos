# Busca

Tarefas de busca se preocupam com:

* Planejamento: rota
* Identificação: encontrar solução

## Busca não informada

Não temos informações e localizações do que procuramos para ajudar (como um caça ao tesouro). Neste caso, é preciso transitar e <mark style="color:blue;">armazenar as transições de possíveis estados</mark> (andar uma casa é um estado por exemplo).

Passando por informações, <mark style="color:red;">nunca podemos definir o estado guardado ali como final</mark>, a menos que esteja tudo completo. Isso porque: supondo que em um puzzle a peça esteja no lugar certo, mesmo assim, talvez ela precise ser removida dali para não travar uma outra, por isso o <mark style="color:orange;">estado final dela não pode ser definido</mark>.

### Busca em largura

Supondo que os [dados estão organizados em uma árvore](../../semestre-2/estrutura-de-dados/arvores.md), essa busca procura todos os nós de um nível antes de ir para outro nível (passar por todos os irmãos). Ou seja, o <mark style="color:green;">tamanho da largura se relaciona com o custo</mark>.

* :warning:  Funciona apenas se a <mark style="color:blue;">largura for finita</mark>. Completude é quando os dados podem existir infinitamente.
* :chart\_with\_upwards\_trend:  Tendência de usar quando a <mark style="color:blue;">respostá está mais próxima da raíz</mark>.
* :map:  Utiliza-se a [estrutura fila](../../semestre-2/estrutura-de-dados/fila.md) para implementar essa busca.

### Busca em profundidade

Supondo que os [dados estão organizados em uma árvore](../../semestre-2/estrutura-de-dados/arvores.md), essa busca vai pelos filhos até o final e volta. Neste caso, devemos escolher <mark style="color:green;">qual ordem seguir</mark>.

* :chart\_with\_upwards\_trend:  Tendência de usar quando a <mark style="color:blue;">respostá está longe e explorar todas as opções possíveis</mark>.
* :map:  Utiliza-se a [estrutura pilha](../../semestre-2/estrutura-de-dados/pilha.md) para implementar essa busca.

#### Ordens

Os nós são empilhados em uma estrutura pilha. A <mark style="color:blue;">ordem em que eles são empilhados</mark> pode ser escolhida. Atenção: isso **não quer dizer** a ordem de <mark style="color:red;">**ACESSAR**</mark> os elementos, e **sim** a ordem de <mark style="color:green;">**EMPILHAR**</mark>. Isso quer dizer que obrigatoriamente vai passar pelo nó pai antes, mas não necessariamente ele será o empilhado no momento.

* Pré ordem: <mark style="color:purple;">`NÓ`</mark> → `ESQ` → `DIR`
* Em ordem:`ESQ` → <mark style="color:purple;">`NÓ`</mark> → `DIR`
* Pós ordem: `ESQ` → `DIR` → <mark style="color:purple;">`NÓ`</mark>

<figure><img src="../../.gitbook/assets/ordens de busca em arvores.png" alt=""><figcaption></figcaption></figure>
