# Async wait

Async/await permite escrever código assíncrono de forma mais simples, parecendo código síncrono. Ele é usado para trabalhar com <mark style="color:purple;">Promises</mark>, que são úteis para operações que levam tempo, como acessar uma API, banco de dados, etc.

## Como usar cada palavra

Só é necessário marcar como `async` a função que vai <mark style="color:blue;">**receber**</mark> <mark style="color:blue;"></mark><mark style="color:blue;">os dados</mark>, ou seja, a função onde usaremos o `await` para <mark style="color:blue;">esperar o resultado de uma Promise</mark>.

* `async` transforma uma função para que ela retorne uma Promise.
* `await` só pode ser usado dentro de funções marcadas como `async` e faz com que a execução "espere" a resolução de uma Promise.

## Como transformar algo em async

Vamos supor uma função que retorne um json do banco de dados tudo em uma variável object (típico de backend). Para transformar esse código em `async/await`, você precisamos fazer:

1. Colocar `await` antes de qualquer chamada de função que precisa esperar por algo, tipo o valor de uma função, um fetch, etc.
2. Marcar a função que tem a presença de "wait" como `async`.
3. Neste caso, em vez de usar `.then`, convertemos os dados em json, como no exemplo abaixo.

### Função sem async

<figure><img src="../../../.gitbook/assets/fetch sem usar async.png" alt=""><figcaption></figcaption></figure>

### Transformando em async

<figure><img src="../../../.gitbook/assets/exemplo async task completo.png" alt=""><figcaption></figcaption></figure>
