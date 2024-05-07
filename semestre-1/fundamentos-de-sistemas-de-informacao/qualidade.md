# Qualidade

## Métricas de qualidade

Valores e métodos usados para medir a qualidade de um software.

A qualidade pode ser separa por dois externos:

* Externos: aquilo que o usuário percebe ou reporta
* Internos:podem ser medidos pelos programadores

### Fan-in e Fan-out

Ambos esses termos são usados para determinar métricas e conseguir medir uma qualidade em uma lógica ou em um softare. São eles:

* Fan-out: <mark style="color:blue;">**setas saindo**</mark>; simbolizam o número de funções que uma dada função chama. Valor alto <mark style="color:red;">**significa complexidade**</mark> na função, pois começa a embolar.
* Fan-in: <mark style="color:blue;">**setas entrando**</mark>; número de vezes que essa função é chamada por outra. Valor alto <mark style="color:red;">**significa impacto**</mark> na mudança.

Portanto, para checar a função mais complexa, é apenas verificar qual possui o maior valor fan-out. Quando há uma função com inúmeros fan-out, a melhoria seria reestruturar para que essas funções que estão sendo chamadas, chamem outras funções também ao invés de apenas uma chamar todas.&#x20;

### Acoplamento

Acoplamento corresponde ao grau de <mark style="color:blue;">**interdependência entre dois componentes**</mark> de um software. Quando há um baixo acoplamento, um componente consegue operar de forma praticamente independente do outro. Alto acoplamento já implica em uma conexão forte entre os dois, que pode torná-los até indistinguíveis.

Quanto maior o nível de acoplamento, pior. Isso pois está muito ligado com a coesão, quanto maior o acoplamento simboliza menor coesão.

<figure><img src="../../.gitbook/assets/image.png" alt=""><figcaption></figcaption></figure>

### McCabe

É uma métrica usada para medir a complexidade de um programa (classe, método, rotina etc). Ela indica a dificuldade de se construir testes de unidade em um determinado código uma vez que ela mede a <mark style="color:blue;">**quantidade de caminhos linearmente independentes**</mark> neste código.

<figure><img src="../../.gitbook/assets/image (2).png" alt=""><figcaption></figcaption></figure>



#### Exemplos

Vemos abaixo um exemplo prático, onde começa na primeira linha e depois abre condições. No caso do **IF/ELSE** abre um fluxo para cada lado, cada lado simbolizando ou o IF ou o ELSE.

<figure><img src="../../.gitbook/assets/image (3).png" alt=""><figcaption></figcaption></figure>

É importante lembrar que existe a possibilidade da <mark style="color:red;">**inexistência do ELSE**</mark>. Sendo apenas com IF, não há dois lados para ir e apenas uma linha única com uma ramificação, por exemplo:

<figure><img src="../../.gitbook/assets/image (4).png" alt=""><figcaption></figcaption></figure>

Dentro dos círculos, em um exemplo foi escrito apenas o "IF" e em outro foi escrito as etapas, como "1" e "2".
