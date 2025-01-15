# Postman

É um software que usamos para testar nossas APIs criadas, simulando verbos e corpo de requisições.

## Testando a rota

Devemos criar uma **Collection** que representa cada API nossa. Depois de criado, adicionamos um request novo como mostrado abaixo:

<figure><img src="../../../.gitbook/assets/criacao de rotas no postman.png" alt=""><figcaption></figcaption></figure>

Configuramos esse request com o verbo e rota que queremos e depois podemos testar. Teste de rotas locais precisam ter o [Postman Agent](#user-content-fn-1)[^1] instalado para funcionar.

<figure><img src="../../../.gitbook/assets/testando rota no postman.png" alt=""><figcaption></figcaption></figure>

## Criação de uma rota

Vamos criar uma rota POST para testar:

<figure><img src="../../../.gitbook/assets/rota para testar postman.png" alt=""><figcaption></figcaption></figure>

O postman vai enviar uma requisição para essa rota com um JSON que vai conter os dados `name` e `price` em um objeto. A resposta `res` será enviada para o postman, que foi o solicitador da rota. Para testar isso, vamos:

#### 1. Criar uma nova rota do tipo POST

Criar um novo request como foi feito nos passos anteriores. Devemos utilizar o nome da rota definida como `createproduct` e definir como tipo POST.

<figure><img src="../../../.gitbook/assets/rota tipo post no postman.png" alt=""><figcaption></figcaption></figure>

#### 2. Criar um body

Essa rota espera `name` e `price` no body como falado anteriormente. Portanto, o postman deve enviar esses dados. Para isso, faça:

<figure><img src="../../../.gitbook/assets/definir body no postman.png" alt=""><figcaption></figcaption></figure>

#### 3. Testar

Já podemos enviar com "Send". Os dados serão recebidos de forma correta no terminal da aplicação e o postman vai receber a nossa resposta `res.json({message: "Resposta com sucesso!"})`. Se não houvesse essa resposta, o postman entraria em looping esperando por uma.

[^1]: O próprio site fornece o download ao reconhecer que é uma requisição local.
