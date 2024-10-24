# Sistemas de IO

Um dispositivo de entrada/saída é um hardware que permite a <mark style="color:blue;">comunicação (troca de dados) do computador com o mundo externo</mark>. São com eles que o usuário fornece e recebe dados. Um teclado é um dispositivo de entrada enquanto o monitor é um dispositivo de saída.

O gerenciamento de E/S é um aspecto fundamental no funcionamento de um sistema operacional, permitindo a comunicação eficiente entre o software e o hardware. É um aspecto crucial que influencia diretamente a operação de um computador, já que a interação com dispositivos de entrada e saída <mark style="color:blue;">ocorrem constantemente</mark>.

## Comunicação processador com hardware

<mark style="color:purple;">Portas</mark>, <mark style="color:purple;">barramentos</mark> e <mark style="color:purple;">controladores</mark> são componentes essenciais no gerenciamento de entrada e saída de um sistema, que permitem a comunicação entre o **processador** e os diversos dispositivos de hardware, como discos rígidos, teclados, impressoras, entre outros.

* Portas: <mark style="color:blue;">**Ponto de conexão**</mark> físico ou lógico (porta USB, porta de rede, portas paralelas). Permitem que o sistema operacional se conecte e troque dados com dispositivos externos, e cada porta tem um endereço que o processador utiliza para identificar qual dispositivo está conectado a ela.
* Barramentos: Como se fosse uma "estrada" por onde os dados trafegam entre os dispositivos e o processador, oferecendo a <mark style="color:blue;">**estrutura de comunicação**</mark>.
* Controladores: atua como uma "ponte" entre o processador e os dispositivos de E/S, controlando e <mark style="color:blue;">**coordenando**</mark> <mark style="color:blue;">**a comunicação**</mark> com os dispositivos, garantindo que o processador e o dispositivo de E/S <mark style="color:blue;">**entendam as mesmas instruções**</mark> (através do gerenciamento das operações de leitura e escrita dos dispositivos).

## Drivers

Os drivers <mark style="color:blue;">encapsulam os detalhes específicos de cada dispositivo</mark>, tornando a interface de acesso uniforme para o sistema operacional. Isso permite que o kernel do sistema operacional se comunique com diferentes dispositivos sem a necessidade de conhecer todos os detalhes de cada hardware. Se um novo dispositivo utiliza um protocolo conhecido, muitas vezes o sistema operacional não precisa de modificações, já que o <mark style="color:blue;">driver garante a compatibilidade</mark>.

## Modos de acessos de Entrada/Saída

Existem diferentes **modelos de acesso** que determinam como o sistema operacional interage com os dispositivos. O <mark style="color:blue;">processador sempre participa de alguma forma</mark> no processo de entrada e saída mas o <mark style="color:orange;">nível de envolvimento do processador pode variar.</mark>

### Programada (polling)

Aqui o processador controla diretamente o dispositivo de E/S <mark style="color:blue;">checando constantemente o estado</mark> dispositivo (testa se está pronto para operações de leitura ou escrita). Essa checagem constante é um loop de verificação contínua, que é a tradução para <mark style="color:purple;">polling</mark>. O processador continua verificando enquanto não estiver pronto o que impede de executar outras tarefas enquanto isso, tornando-o ineficiente.

### Guiada por interrupção

Aqui o processo é inverso do de cima, sendo o dispositivo de E/S <mark style="color:blue;">enviando um sinal de interrupção para o processador</mark> confirmando que está pronto. Assim, o processador pode realizar outras tarefas enquanto isso, mas fazendo com que o processador pare a sua tarefa atual. Essa parada custa um certo desempenho pois, para fazer isso, precisa salvar estados da tarefa passada para retormar novamente mais tarde. Além disso, pode sobrecarregar com múltiplas requisições.

### Acesso direto à memória (DMA)

O processador começa configurando o controlador do DMA que vai permitir que os dispositivos E/S enviem seus dados <mark style="color:blue;">diretamente à memória RAM, sem a necessidade do processador</mark>. Depois que os dados já estão na memória RAM, o processador pode, no seu tempo adequado, acessar os dados que estão ali e executá-los. Um exemplo prático é transferir arquivos de um pen-drive, que é transferido diretamente para a memória RAM e depois o processador faz a função de guardá-los no disco rígido.

### Comparação Resumida:

| Modo de Acesso                    | Funcionamento                                                                      | Vantagens                                                   | Desvantagens                                                                                                                |
| --------------------------------- | ---------------------------------------------------------------------------------- | ----------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------- |
| **E/S Programada (Polling)**      | O processador verifica o estado do dispositivo continuamente.                      | Simplicidade de implementação                               | Ineficiente, pois consome muito tempo de CPU                                                                                |
| **E/S Guiada por Interrupção**    | O dispositivo sinaliza ao processador quando está pronto, usando uma interrupção.  | Eficiência, já que o processador não fica ocioso            | Processador pode ser sobrecarregado com múltiplas interrupções                                                              |
| **DMA (Acesso Direto à Memória)** | O controlador de DMA gerencia a transferência de dados diretamente para a memória. | Alta eficiência, ideal para grandes transferências de dados | Implementação mais complexa e [<mark style="color:purple;">overhead</mark>](#user-content-fn-1)[^1] para pequenas operações |

## Interface de E/S para a Aplicação

As chamadas de sistemas encapsulam o comportamento desejado das interfaces com os detalhes fornecidos no driver. Cada dispositivo de entrada e saída tem suas próprias características, que com certeza mudam a forma como sistemas operacionais gerenciam eles.

* Tipo de dados: Grandes blocos de dados (como discos) ou fluxo de caracteres (como teclados).
* Acesso: Sequencial (como fitas magnéticas) ou aleatório (como disco rígido).
* Operação: De forma síncrona (em tempo real) ou assíncrona (concluídas em tempos diferentes).
* Compartilhamento: se os dispositivos são dedicados à um único processo ou compartilhado à vários. O exemplo de uma impressora pode servir para os dois.
* Velocidade: A operação dos dispositivos podem variar bastante, além de tempo de espera e latência.
* Modos: Dispositivos podem ser de leitura + escrita, somente leitura (como CD-ROMs) ou somente escrita (algumas impressoras).

## Subsistema de E/S

Esse termo refere-se a parte específica <mark style="color:orange;">do sistema operacional</mark> em lidar com as operações de entrada e saída, como se fosse uma divesão especial para coordenadar isso.

### Escalonamento

Assim como faz com processos, o escalonamento <mark style="color:blue;">organiza os pedidos de entrada e saída em fila</mark>, muito útil quando há diversas requisições, garantindo a qualidade.

### Buffering

Enquanto uma transação de E/S está em andamento, o buffering consiste em guardar os dados que estão sendo **transferidas ou processadas** entre o sistema e dispositivos de entrada e saída na <mark style="color:blue;">memória RAM</mark>. Também gerencia **diferenças no tamanho dos dados**, assegurando que as operações sejam executadas sem interrupções ou perdas de dados.

### Caching

Com o foco no desempenho, mantém uma <mark style="color:blue;">cópia dos dados em um dispositivo mais veloz</mark> (tipo memória RAM), que assim pode requisitar os dados da cópia fazendo uma busca mais rápida.

### Spooling

Para garantir que não há sobrecarga, ele guarda <mark style="color:blue;">temporariamente as requisições futuras em casos de dispositivos que só podem atender uma por vez</mark> (exemplo impressora) e assim garante que trabalhe na ordem e organizadamente.

### Reserva de dispositivos

Resolve uma possibilidade de seção crítica, onde dispositivos não podem ser acessados ao mesmo tempo, então usa uma chamada de sistema para trancar/reservá-los proporcionando <mark style="color:blue;">acesso exclusivo</mark>, o que pode causar também deadlock.

## Proteção

Todas as instruções de entrada e saída são classificadas como privilegiadas, que implica que só podem ser executadas através de chamadas de sistemas que também só pode ser feito pelo sistema operacional. Além disso, somente o sistema operacional tem acesso as portas de entrada e saída e mapeamento de memória dos dispositivos.

Isso porque, precisa garantir que usuários não interfiram no funcionamento desse sistema. Outros processos também podem tentar executar instruções E/S ilegais comprometendo a segurança. Esses aspectos vão assegurar estabilidade e segurança.

[^1]: Uma sobrecarga desnecessária.
