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

## **Restrições na Modelagem e Métodos de Busca Heurística**

A modelagem de problemas muitas vezes envolve **restrições**, que podem estar relacionadas a diversas variáveis, como cores, atributos específicos, valores binários, entre outros. Um exemplo prático de problema com restrições é a **montagem da grade curricular de uma faculdade**, onde diversos fatores devem ser considerados, como:

* **Pré-requisitos das disciplinas** (uma matéria só pode ser cursada se outra tiver sido concluída);
* **Disponibilidade de horários** (conflitos entre disciplinas precisam ser evitados);
* **Disponibilidade de professores** (cada professor tem um limite de disciplinas que pode ministrar).

### **Modelagem do Problema com Grafos**

Para representar esses problemas, frequentemente utilizamos **grafos**, onde os nós representam os elementos (exemplo: disciplinas) e as conexões entre eles representam as restrições (exemplo: relação de pré-requisito ou conflito de horários).

Um exemplo clássico de problema com restrições é o **problema de coloração de grafos**, onde cada nó (estado) deve ser colorido de forma que nenhum nó vizinho tenha a mesma cor. Para resolver esse problema, aplica-se um processo chamado **propagação de restrições**, que consiste em manter uma <mark style="color:purple;">tabela de possibilidades</mark> para cada variável. Por exemplo:

* Se o **estado A** for vermelho, então o **estado B** pode ser azul ou verde, o **estado C** pode ser amarelo, e o **estado D** pode ser azul ou amarelo.

Esse processo reduz as possibilidades e facilita a busca por uma solução válida.

### **Decisão de Variáveis e Heurísticas**

Durante a resolução do problema, é necessário decidir em qual ordem as variáveis (nós do grafo) serão avaliadas. Algumas estratégias comuns incluem:

1. **Escolher primeiro as variáveis que impactam mais o restante do problema** (normalmente aquelas conectadas a mais elementos);
2. **Escolher primeiro as variáveis que têm menos opções disponíveis** (ou seja, aquelas que já estão mais restritas devido às conexões com outras variáveis).

A escolha da estratégia influencia diretamente a eficiência do algoritmo e a qualidade da solução encontrada.

### **Técnicas de Busca e Backtracking**

Para encontrar a melhor solução, existem diferentes técnicas de **busca heurística** que orientam como as restrições serão tratadas. Algumas dessas abordagens incluem:

* **Busca com restrições rigorosas** (segue um caminho onde todas as restrições devem ser satisfeitas desde o início);
* **Busca mais flexível** (permite algumas violações iniciais, que serão corrigidas posteriormente);
* [**Backtracking** ](../../semestre-2/estrutura-de-dados/grafos/busca.md#busca-em-profundidade)(se uma decisão não leva a uma solução válida, o algoritmo retorna e tenta outra possibilidade).

Dependendo do contexto, o algoritmo pode encontrar a solução **ótima** ou apenas uma solução **aceitável**, considerando o custo computacional envolvido.

### **Conclusão**

O estudo de restrições na modelagem é essencial para resolver problemas complexos, como escalonamento de horários, alocação de recursos e coloração de grafos. A escolha da melhor estratégia de busca e decisão depende das características do problema e dos objetivos desejados. Métodos heurísticos e técnicas como **propagação de restrições e backtracking** são fundamentais para encontrar soluções viáveis e eficientes.
