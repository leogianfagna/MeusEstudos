# Backend

Para desenvolver o front-end, são linguagens como:

* HTML
* CSS
* JavaScript

Enquanto para desenvolver o back-end, são utilizadas linguagens como:

* Node.js: conjunto de funções para escrever código em JavaScript para rodar no servidor (chamado de run time JavaScript server site, um conjunto de funções)
  * Site para fazer o download do node, para conseguir rodar: [https://nodejs.org/en](https://nodejs.org/en)
* PHP
* Entre outras

## Verbos de aquisição em HTTP

São eles aqueles para controlar os dados do banco.

* POST: recebe entrada e atualiza
* GET: obter dado, não recebe entrada
* PUT: inserir algo novo no banco de dados
* DELETE: excluir algum dado do banco

É possível fazer tudo com POST e GET pois era feito assim antigamente. Existem muitos outros verbos de aquisições, contudo, são eles os mais usados e que usaremos nos projetos.

## Funções de callback (req e res)

Eles são objetivos que representam requisição e resposta respectivamente. A requisição caminha do cliente ao servidor enquanto a resposta é do servidor para o cliente.

Os tipos de requisições são dados em formulários, cookies, entre outros enquanto a resposta do servidor é o status da resposta (como 404, sucesso, não encontrado, entre outros), o header e o body da resposta.

&#x20;

## Body e Header

O body é o corpo da requisição, é onde você envia dados e informações ao servidor, normalmente em requisições POST, PUT e PATCH. Todos os dados em formulários serão enviados através do body.

O header é o cabeçalho da requisição e eles complementam com informações sobre a requisição como o tipo de conteúdo enviado, por exemplo: “content-type”. São usados para enviar informações adicionar para ajudar o servidor processar as informações corretamente.

&#x20;

## Promise

É um objeto com um valor que pode não estar disponível imediatamente, por exemplo, um dado que é requisitado a um banco ou um serviço. Quando a função é uma Promise, usa-se a característica async para representá-la, por ser uma função assíncrona.

Além disso, pode-se usar a palavra-chave await para esperar o resultado dessa Promise. Ou seja, “async (req,res)” é uma Promise.



## A parte backend de um projeto

Tudo está em um arquivo chamado app.ts, apenas no começo do aprendizado. Em uma maneira correta, separa cada serviço (GET, PUT e DELETE) em módulos.

O banco não está no mesmo servidor que o projeto, então é um serviço assíncrono. Então, usamos async para denotar um serviço de back-end que usa recursos de rede que precisam ser controlados por _promises_.

Em outras palavras, sempre que há uma requisição fora do serviço (no caso, o Oracle), não sabemos quanto tempo vai demorar para processar o que queremos, logo, precisamos usar o await.

Vejamos no capítulo “entendendo o código” o passo a passo de tudo.

### CustomResponse

Personalização da resposta para o cliente. A tendência de um algoritmo é erro, já que é possível somente um sucesso para N erros, por isso, inicializa a resposta com a tendência.

No exemplo, cria um objeto de resposta chamado CustomResponse com:

```javascript
let cr: CustomResponse = {
  status: "ERROR", 
  message: "", 
  payload: undefined,
};
```

### Tratamento de exceção

As linguagens mais modernas (como TypeScript, Java, C++, Python) tem tratamentos de exceção. São elas: **try**, **catch** e **finally**.

Tudo o que estiver dentro do bloco try o programa tentará fazer. Porém, se algum dos comandos resultar em erro dentro desse bloco, o programa para a execução do bloco e direciona para o bloco catch e depois executa o bloco finally.

No entanto, se tudo o que estiver dentro do bloco try funcionar, será direcionado diretamente para o bloco finally. O finally é responsável por retornar a resposta, basicamente, apenas uma linha que é o objeto CustomResponse.

### Postman

Ferramenta para testar o serviço, ele faz o serviço de front-end para saber se o serviço de back-end funciona.

### Integração com o front-end

Deixou o script logo no head. Ele cria diversas funções para verificar se os dados inseridos (em cada formulário) estão corretos.

Como chama a função e o que entra nela (os dois parâmetros).

!selecionouFabricante() significa selecionouFabricante() === false

A função inserirAeronave trata todos os erros e ve se cai fora ou não. Se o código chegou até a parte de cadastrar, ele pega os dados e finalmente insere.

No Javascript, existe uma função chamada fetch. Essa função chama um serviço do back-end dado o seu endereço completo. Ela precisa de um body, um verbo (do banco de dados, por exemplo, PUT) e o endereço (do banco de dados).

ESTUDAR FUNÇÃO FETCHINSERIR E CONCEITO DE PROMISES (chega em .then \[quando da certo])

O que é objetivo js anônimo?



### Instalação de dependências e módulos

Primeiro, precisa abrir uma pasta de projeto em que vai trabalhar, depois, executar comandos no terminal daquele diretório parra importar módulos para serem usados no projeto (lembrar que precisa ter o Node instalado para isso funcionar):

1. npm init –y
2. npm install express
3. npm install typescript --save-dev
4. npm install @types/node @types/express --save-dev
5. npm install oracledb
6. npm i --save-dev @types/cors
7. npx tsc –init

Tudo o que foi instalado será escrito nas dependências do projeto ou do desenvolvedor no arquivo packed.json. A pasta de build e node\_modules não é enviada no projeto final, portanto, quem for editar ou executar o código basta apenas executar o comando “**npm install**” e todas as dependências declaradas nesse arquivo serão automaticamente instaladas.

Depois de feito, já é registrado todas as dependências do projeto e as dependências do desenvolvedor. Agora, com o arquivo tsconfig.json criado (ele que possui diversas configurações da linguagem TypeScript), abrimos ele para configurar algumas opções.

* rootDir: "src"
* outDir: "build"

A opção “rootDir” indica onde estão os arquivos TypeScript do nosso projeto. É uma boa prática deixar todos esses tipos de arquivos na pasta src (source abreviado). O “outDir” indica onde vai gerar os arquivos JavaScript através do código em .ts.

Depois de feito isso, cria-se uma pasta no diretório do projeto chamada src com um arquivo dentro dela chamado app.ts. Esse arquivo representa a nossa aplicação em backend com o express.

### O que é express?

O express é um módulo que traduz toda a complexidade de trabalhar com requests e responses. Ele facilita para que não precisamos criar tantos códigos para criar rotas, HTTP request, etc, ocultando muito código e tornando simples o serviço de subir um servidor web.



### Gerar o arquivo javascript

Criando o primeiro código em app.ts na pasta src, que ficou da seguinte forma:

<figure><img src="../../.gitbook/assets/typescript htpp requests.png" alt=""><figcaption></figcaption></figure>

Sempre rodaremos o código em JavaScript e esse código será gerado automaticamente através do código escrito em TypeScript (acima). Depois de criado, abrimos o terminal e rodamos o comando: “npx tsc”

### Rodar o código

Isso vai gerar o código JavaScript na pasta build (que será criada automaticamente). E assim, para rodar o código gerado, no terminal rodamos: `node build/app.ts`

## Criar comandos pelo packet.json

Os dois comandos acima (de converter o código e rodar o código) são chatos de serem executados a todo momento, por isso, é possível criar comandos através desse arquivo.

Há uma aba chamada scripts onde você pode criar seus próprios comandos. Nesse caso, vamos criar um comando chamado “start” que vai rodar esses dois acimas. Todos os scripts criados poderão ser rodados com:

\-          npm \<NOME DO SCRIPT>

<figure><img src="../../.gitbook/assets/comandos com packet json.png" alt=""><figcaption></figcaption></figure>
