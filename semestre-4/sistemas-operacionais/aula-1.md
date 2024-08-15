# Aula 1

Um código de um sistema operacional não possui classes e objetos, é como se fosse um único código tudo junto, onde se algo der errado em certa parte, claramente terá problema em todo o resto. Isso é feito para ser extremamente rápido.

## O que é sistema operacional e como funciona o processamento de um computador moderno

Um core executa apenas um único programa. Existem processadores com mais de um core e ai sim cada core é responsável por um programa, mas, durante o uso do computador temos muito mais de um programa e processos ao mesmo tempo, então como é feito?

O computador fica ciclando cada processo de cada programa de cada vez, revezando-os tão rápido em milissegundos que o usuário não percebe. Isso engloba o conceito de concorrência. Mesmo com mais de um core, esse conceito ainda está presente.

O sistema operacional é quem controla esses processos, <mark style="color:blue;">alocando recursos e gerenciando execução</mark>, portanto, podemos definí-lo como uma <mark style="color:green;">interface que traduz o que está acontecendo</mark>. O sistema operacional possui um núcleo, chamado de <mark style="color:red;">kernel</mark>.

<figure><img src="../../.gitbook/assets/comunicação com SO.png" alt=""><figcaption></figcaption></figure>

> **Observação:**
>
> Programa = passivo
>
> Processo = ativo
>
> _Processos são uma sequência de instruções depois que o programa foi rodado._

## Modo de trabalho de um SO

Sistema operacional trabalha em modo operação dual: usuário ou kernel. O modo kernel é um modo do processador que pode e tem direito de fazer tudo, não podemos confundí-lo com modo administrador pois não é relacionado. O modo usuário é o radical oposto onde não pode nem acessar disco, memória, hardware, etc. Sua única permissão é fazer contas básicas, normalmente colocadas em códigos como `for`, variáveis, etc.

#### Chamada de sistema

Entender esse modo de trabalho operação dual nos leva a precisar entender as chamadas de sistemas. Fazer algo em modo usuário (que é o que usamos) vai precisar ajuda do sistema pois ela em si não tem acesso a nada e essa ajuda é a chamada de sistema.

Ela funciona como se fosse uma função, contudo, ela não é chamada diretamente. Essas chamadas estão presentes através de uma biblioteca que dentro da api usa a chamada de sistema. O comando `printf()`, por exemplo, é uma biblioteca que usa uma chamada de sistema. Vejamos um exemplo prático:

<figure><img src="../../.gitbook/assets/chamadas de sistemas.png" alt=""><figcaption></figcaption></figure>

Esse é um programa para copiar um arquivo. Com exceção do loop e checagens de condições, literalmente todo o restante é uma chamada de sistema. Tecnicamente, uma chamada de sistema é um código presente dentro do sistema operacional escrito em c++ e ela vem associada a um número, onde nós não precisamos ter mais detalhes sobre isso. A chamada de sistema também poderá ser escritra como **Syscall**.

<figure><img src="../../.gitbook/assets/interface syscall.png" alt=""><figcaption></figcaption></figure>

#### Gerenciamento de memória

Para algo ser executado, tem que sair do disco para a memória RAM. Mas o disco é muito grande e a memória muito pequena e com certeza não vai caber tudo. Por isso, é trabalho do compilador enviar as instruções corretas para a memória ram executar.

## Linkers e loaders

O código fonte é compilado em diversos arquivos objetos que podem ser carregados de qualquer lugar da memória. Um Linker junta esses arquivos objetos em um arquivo executável, basicamente fazendo o papel de um compilador, que é transformar as linguagens de alto nível (tipo c) em assembly que é a linguagem de máquina.

> hello.c -> gcc -> hello.o -> linker -> ./hello

O loader é quem carrega esse arquivo na memória para ser executado. Por conta das interfaces de chamadas de sistemas e bibliotecas dinâmicas diferentes, as aplicações são dedicadas a um SO apenas. Algo feito para Windows não roda em Linux e vice-versa, exceto se for uma linguagem interpretada (Python) ou rodar em uma máquina virtual (Java).

## Falta!!

* Final slides
* monolítico
  * bloco só de código (kernel)
* micro kernel
  * divisão em varios pedaços

