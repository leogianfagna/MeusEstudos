# SysM

A modelagem inicia-se na identificação, focando em identificar limites, ambiente e todas as interações com o meio do sistema e de todos os subsistemas. Há de se tipificar os blocos que os compõe, como:&#x20;

* Software&#x20;
* Hardware&#x20;
* Instalação&#x20;
* Dados&#x20;
* Pessoas&#x20;
* Procedimentos&#x20;
* Ou qualquer outra parte que seja relevante&#x20;

## 3 tipos de diagrama SysML&#x20;

<figure><img src="../../../.gitbook/assets/tipos de modelagem sysml.png" alt=""><figcaption></figcaption></figure>

### Comportamentais:&#x20;

Aspectos dinâmicos, por exemplo o sistema de freio, se comporta baseado nas necessidades baseado nas interações com o sistema&#x20;

* Atividades&#x20;
* Sequência&#x20;
* Casos de uso&#x20;
* Máquinas de estado (processando, finalizado, etc)&#x20;

### Requisitos:&#x20;

capturam as necessidades de um sistema&#x20;

### Estruturais:&#x20;

documentar aspectos estruturais e estáticos de um sistema, feito para visualizar hierarquias:&#x20;

* Pacotes&#x20;
* Definição de blocos&#x20;
* Blocos internos&#x20;
* Paramétricos (velocidade mínima para acionar abs, massa mínima, etc)&#x20;

## Modelagem estática - blocos (IBD)&#x20;

Bloco é elemento estrutural básico e flexível em SysML usado para representar sistemas e subsistemas. Os blocos são compostos por outros blocos até ele não possuir outras partes e passar a usar outras ferramentas. Ele modela uma categoria/tipo de entidade presente no sistema. &#x20;

<figure><img src="../../../.gitbook/assets/blocos IBD.png" alt=""><figcaption></figcaption></figure>

O bloco não representa instâncias (objetivos). Por exemplo, em uma instituição, professor é um tipo e cada professor é uma instância desse tipo. Outro exemplo utilizando um shopping como um tipo, Galleria e Iguatemi são instâncias desse tipo. Pensando em subsistemas, exemplos de subsistemas de um shopping são <mark style="color:blue;">`ControleDeEntrada`</mark> e <mark style="color:blue;">`ControleDeSaida`</mark>.

## Representação de blocos&#x20;

O bloco é formato por nome e estereótipo, portas de comunicação e 6 compartimentos de características, todas opcionais. Os compartimentos devem ser colocados baseados no valor deles pro modelo, por exemplo, se for algo que não seja essencial, pode-se omitir. &#x20;

<figure><img src="../../../.gitbook/assets/representacao de blocos sysml.png" alt=""><figcaption></figcaption></figure>

* Estereótipo: usado para detalhar uma informação chave, por exemplo, usar <\<subsistema>> ou <\<controlador>> para se remeter ao papel dele no bloco.&#x20;
* O nome do bloco é o tipo de sistema a ser modelado&#x20;
* Nos componentes:&#x20;
  * `<nome>`: é definido pelo modelador&#x20;
  * `<tipo>`: geralmente o nome de outro bloco que é componente&#x20;
  * `<multiplicidade>`: quantidade de instâncias&#x20;
  * `<valor padrão>` e `<expressão>`: opcionalmente um valor inicial&#x20;
  * `<tipo retorno>`: o tipo retornado pela expressão&#x20;
  * `<<sinal>>`: estereótipo&#x20;
  * `<parâmetros>`: dados transferidos em chamadas, como em funções&#x20;
* Portas de comunicação: ponto onde ocorre interações com outros blocos&#x20;

Na linguagem SysML, o “N” para simbolizar quantidade infinita é com asterisco, ou seja, 1\* (significa um para N). 0:1 significa que pode não existir e se houver, é no máximo um. Mesma coisa o 0:\*, para não existir ou ter vários. Exemplo final:

<figure><img src="../../../.gitbook/assets/representação de blocos exemplo completo sys.png" alt=""><figcaption></figcaption></figure>

## Portas de comunicação&#x20;

Representam interfaces bem definidas e são um ponto onde ocorre interações com outros blocos pela fronteira do bloco representado. Elas podem ser modeladas em qualquer ponto limite do bloco.&#x20;

Um componente é adicionado para se utilizar a porta, o “flow properties”. As propriedades do fluxo vão detalhar o recebimento de entradas ou de saída do bloco podendo ser energia, dados ou matéria.&#x20;

Esse novo componente é constituído por:&#x20;

* {IN ou OUT}: simboliza se é entrada ou saída&#x20;
* \<nome da propriedade>: a propriedade que flui pela porta, tipo o nome da variável que está se conectando&#x20;
* \<tipo>: por exemplo, boolean&#x20;

Já na porta, ainda é adicionado uma nova sintaxe para ela. Todos os elementos dessa nova sintaxe são os mesmos representados nos componentes do bloco. Essa sintaxe é da seguinte forma:&#x20;

<figure><img src="../../../.gitbook/assets/sintaxe porta bloco sysml.png" alt=""><figcaption></figcaption></figure>

Podem-se criar modelos parciais para fazer a representação das ligações entre portas. Ao invés de colocar todos os blocos somado com as ligações, cria-se um outro modelo com blocos simples, que definem apenas o nome de cada bloco e as portas, por exemplo:

<figure><img src="../../../.gitbook/assets/representação das portas sysml.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/modelos parciais portas sysml.png" alt=""><figcaption></figcaption></figure>

Deve lembrar em manter consistência de fluxo, por exemplo, se está recebendo algo pela porta, a entrada é IN. Além disso, manter o mesmo tipo (por exemplo boolean) em ambas.&#x20;

Se for uma linha é referência, se for um diamante é composição. Por exemplo, um bloco pode compor o outro e é representado pelo diamante. Se for apenas uma linha, é uma referência, um bloco usa o outro, mas não é composto pelo outro.&#x20;

## Operations e Recepetions&#x20;

São componentes colocados no bloco que representam um comportamento sobre as portas.&#x20;

* Operações: invocada por um evento de chamada&#x20;
  * É o comportamento que o bloco executa quando um outro bloco a chama&#x20;
  * Normalmente síncrona: cliente (bloco de origem) espera resposta da execução&#x20;
* Recepção: invocada por um evento de sinal&#x20;
  * É o comportamento que o bloco executa quando envia o sinal para outro bloco&#x20;
  * Normalmente assíncrona: cliente (bloco de origem) não espera a resposta da execução&#x20;

Diagrama deve estar em um quadro (também chamado de frame), composto por header e content.&#x20;

## Associações em SysML&#x20;

Essas associações vão criar as ligações entre os blocos que, até então, não são muito bem representadas. Os blocos contêm informações e características estruturais, mas visualmente não é legível. Para isso, utiliza-se as associações que podem ter diferentes tipos:&#x20;

### Associações de referência&#x20;

Lembrando na modelagem de blocos (que são tipos ou classes), “parts” são componentes internos daquele bloco e “references” são interações com outros blocos de forma externa, que não compõe o mesmo. Uma associação de referência indica uma conexão entre instâncias de blocos durante a operação do sistema. &#x20;

A representação ocorre um diagrama diferente ou fora do bloco, não utilizando o mesmo diagrama de blocos. Essa associação é criada utilizando uma linha contínua e são por padrão bidirecionais (não apontam uma para a outra). Mas isso pode ser alterado e uma seta apontada para um bloco de destino pode ser inserida.&#x20;

Esse diagrama também deve representar a multiplicidade dessa ligação, ou seja, quantas instâncias do bloco A estão ligadas a quantas instâncias do bloco B. Nessa nomenclatura, todos os tipos já vistos até então podem ser aplicados. Fica como exemplo de um diagrama dessa associação:&#x20;

<figure><img src="../../../.gitbook/assets/associações de ref sysml.png" alt=""><figcaption></figcaption></figure>

### Associações por composição&#x20;

Esse tipo de associação tem como objetivo criar visualmente a composição hierárquica do bloco TODO. O bloco todo seria aquele que menciona o sistema, que possui as partes dentro dele. Basicamente, essa associação vai se baseando no que foi declarado na categoria “partes”. &#x20;

Como o bloco todo “domina” essa composição, as demais representações serão ligadas a ele. Para representar essa ligação, é utilizado uma figura de diamante colada ao bloco em que pertence, criando assim a árvore da composição. Esse diagrama dessa associação também implementa e deixa representado as multiplicidades entre os blocos. Um exemplo desse diagrama completo é:&#x20;

<figure><img src="../../../.gitbook/assets/associação por composição sysml.png" alt=""><figcaption></figcaption></figure>

## Generalizações&#x20;

São associações que representam heranças de tipos entre elementos, em outras palavras, transmissão de características. Por exemplo, não é uma representação de blocos onde um pertence ao outro. A associação por generalização possui no mínimo dois elementos: o supertipo (geral e genérico) e o subtipo (especializado).&#x20;

O subtipo recebe de herança as características e propriedades do supertipo genérico que, por sua vez, pode acabar fazendo alterações disso. Em outras palavras, o subtipo (que é o especializado) pode pegar a herança e alterar parte de suas definições, atribuir novas, adicionar características ou usá-las da mesma forma que foi recebida.&#x20;

Ou seja, pode-se redefinir as características transmitidas do supertipo. A representação desse diagrama pode-se fazer diretamente em outro diagrama. Os blocos especializados apontam uma seta para o genérico, que significa a herança de suas características. Neste caso, não se aplica multiplicidade. Um exemplo de representação dessa associação é (na parte grifada de azul):&#x20;

<figure><img src="../../../.gitbook/assets/generalizações sysml.png" alt=""><figcaption></figcaption></figure>

## Dependências e comentários&#x20;

São um tipo de associação que representam apenas uma forte dependência de um elemento ao outro, como por exemplo, um servidor para um prestador de serviço e também permite a adição de notas e comentários no meio dessa apresentação. Uma alteração no servidor pode causar muitas alterações em seus sistemas dependentes e são essas ligações entre elementos que são representadas no diagrama.&#x20;

As ligações são modeladas com setas pontilhadas apontadas para a quem o elemento depende (se o elemento A depende fortemente de B, então a seta será de A para B) e as notas são adicionadas na forma de um post-it e sempre serão ligadas ao item comentado. Um exemplo desse diagrama é:&#x20;

<figure><img src="../../../.gitbook/assets/dependencias e comentarios sysml.png" alt=""><figcaption></figcaption></figure>

## IBD X BDD&#x20;

O IBD (Definição interna dos Blocos) foi mostrado anteriormente, que caracteriza detalhadamente os componentes daquele bloco como partes, referências, valores, limitações, operações, entre outros. Eles são utilizados para mostrar a estrutura interna dos blocos e são ligados usando as portas de comunicação.&#x20;

Enquanto isso, o BDD é responsável em criar diagramas que mostrem melhor a estrutura da comunicação entre os blocos, mas já sem a quantidade de informações que o IBD oferece. A representação BDD vai utilizar os diferentes tipos de associações que foi visto acima, o tipo de representação vai depender do objetivo a ser mostrado e também do tipo de diagrama.&#x20;

A diferença entre IBD e BDD pode ser vista abaixo:&#x20;

<figure><img src="../../../.gitbook/assets/ibd x bdd sysml.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/Diagrama IBD.png" alt=""><figcaption><p>Sistema de controle geral feito no formato IBD</p></figcaption></figure>

## Diagramas de estado

Todos os sistemas ou blocos de um sistema passam e alterar seu estado ao longo do seu funcionamento, como ligado/desligado, disponível/alocado e entre tantas outras opções. Os estados são atributos que guardam uma propriedade.&#x20;

Um estado corresponde ao intervalo entre dois eventos (ocorrências no meio ambiente) e os eventos separam dois estados diferentes, um caminho vice e versa. Por exemplo, a ocorrência de um evento vai causar a mudança de um estado se satisfazer as condições.&#x20;

Havendo mais de dois tipos de estados, há a necessidade de existir o Diagrama de estado somado com a necessidade de descrições, que vão mencionar como se dá a mudança de um estado para o outro.&#x20;

<figure><img src="../../../.gitbook/assets/diagram de estado sysml.png" alt=""><figcaption></figcaption></figure>

O diagrama de transição de estados modela as diferentes situações que o bloco ou objeto pode se encontrar durante a execução do seu ciclo. Isso inclui: eventos (triggers), condições, ações causadas e mudanças de estado. O intuito é mostrar quais as possibilidades de mudanças de estado.

## Transição e eventos&#x20;

Um relacionado com o outro, a transição mostra um relacionamento entre dois estados que vai ocorrer a partir de um evento (que também é um trigger, denominado como gatilho). Em certos casos, pode haver uma condição para a transição de estados a partir do evento, por exemplo, caso a condição não seja estabelecida, mesmo com o acontecimento do evento, o estado não será alterado.&#x20;

&#x20;

## Condições e ações&#x20;

As condições são opcionais e estão presentes para retornar TRUE ou FALSE. São elas que podem ser colocadas nos eventos para saber se ocorrerá ou não a mudança de estado. Já as ações são a execução de algo caso a transição de estado seja bem-sucedida. Por exemplo, ocorreu um evento e esse evento tem uma condição, a condição se deu como completa e o estado foi alterado, então, neste caso, a ação determinada será executada.&#x20;

### Exemplos de ações&#x20;

As ações são divididas em tipos de execuções:&#x20;

* ENTRY: Executada no instante de entrada do estado&#x20;
* EXIT: Executada no instante de saída do estado&#x20;
* DO: Executando durante o tempo que durar o estado&#x20;

Um exemplo de uma representação dessa seria:&#x20;

<figure><img src="../../../.gitbook/assets/ações sysml.png" alt=""><figcaption></figcaption></figure>

O exemplo acima trabalha apenas com eventos externos (especificados nas setas), aqueles que causam (ou podem causar) uma mudança de estado. Eventos internos do bloco não causariam a mudança de um estado, mas poderia causar o disparo de uma ação. Veja exemplo de ações que podem ser disparadas em eventos internos:

<figure><img src="../../../.gitbook/assets/ações disparadas em eventos internos sysml.png" alt=""><figcaption></figcaption></figure>

## Pseudoestados&#x20;

São utilizados para aprimorar representações mais complexas. Eles são apenas estruturas de controle relacionada aos estados e transições, são transitórios e um sistema não pode permanecer em um pseudoestado. Eles são representados com formas durante o diagrama podendo demarcar ponto de início, fim, bifurcação, junção, escolhe e outros tipos que podem auxiliar o sistema. &#x20;

Colocando em prática, o pseudoestado pode ser utilizado logo no início para representar o começo do sistema. Usando um sistema de semáforos, usa-se um pseudoestado de início para indicar o começo do ciclo de vida já no estado de luz verde. Pode-se adicionar um ponto de escolha para caminhar para estados diferentes dependendo de uma condição e um estado final indicando o fim do ciclo de vida daquele sistema. Exemplos seriam:&#x20;

<figure><img src="../../../.gitbook/assets/pseudoestados sysml.png" alt=""><figcaption></figcaption></figure>

## Estados multi-nivelados (compostos)&#x20;

Os estados podem ser divididos em sub estados ou blocos podem ser compostos por outras máquinas que tem seus próprios estados. Por exemplo, o sistema de uma marcha de carro pode estar no estado engatado ou não, mas dentro do sistema de engatado, possui vários sub estados que compõe as marchas, por exemplo:&#x20;

<figure><img src="../../../.gitbook/assets/estados multi nivelados sysml.png" alt=""><figcaption></figcaption></figure>

Lembrando que também o sistema de transmissão ainda é um subsistema do automóvel. Então, essa parte representada acima ainda é apenas um recorte de todo o sistema pai.

<figure><img src="../../../.gitbook/assets/estado pai sysml.png" alt=""><figcaption></figcaption></figure>

## Diagramas de sequência&#x20;

Esse diagrama é modelo baseado no que acontece por trás do que o usuário pode ver. Por exemplo, um sistema tem uma sequência de métodos para cumprir para o funcionamento do seu sistema e esse diagrama mostra como “ensaiar e filmar esse roteiro”. Tem como intuito mostrar a percepção de um comportamento do sistema e as relações entre os blocos para o funcionamento final.&#x20;

As palavras chaves para definir esse diagrama são os cenários de comportamento dos blocos, através da troca de mensagens baseado em uma linha do tempo. A troca de mensagens entre os blocos podem ser receptoras, operações e envio de sinais. &#x20;

Alguns elementos são colocados na modelagem dos diagramas de sequência:&#x20;

* Atores: o usuário&#x20;
* Entidade, negócio ou domínio (<\<entity>>): pertencem ao domínio do problema, como cancela, totem, estadia, etc.&#x20;
* Fronteira (<\<boundary>>): blocos comunicativos com o mundo externo, como botão, sensor, painel, janela, etc.&#x20;
* Controle (<\<control>>): concorrência de envio de mensagens, são os blocos que exercem controle sobre o outro encapsulando a lógica de coordenação de todas as partes, como Controlador, PlacaDeControle, SoftwareDeControle, etc.&#x20;

<figure><img src="../../../.gitbook/assets/diagrama de sequencia sysml.png" alt=""><figcaption></figcaption></figure>

Essa modelagem representa duas dimensões: o eixo X e o eixo Y. O eixo horizontal (X) são as instâncias dos blocos participantes na ordem que vão entrando na interação, ou seja, o nome dos blocos. No meio do diagrama, ainda na linha horizontal, aparecem as novas instâncias que aparecem durante a construção da modelagem. Já o eixo Y representa o tempo, de cima para baixo. Conforme vai tendo a troca de mensagens, o tempo vai passando, variando a altura em Y. Essas mensagens são enviadas para instâncias de outras classes ou para si mesmo.&#x20;

O formato da modelagem das instâncias é representado por “nome da instância: nome da classe”. &#x20;
