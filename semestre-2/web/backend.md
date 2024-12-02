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





## Projeto BackEnd com node

Aprenda a criar um backend usando um banco de dados MongoDB com tecnologia node. Um projeto que utiliza Node precisa tê-lo instalado no computador.

<figure><img src="../../.gitbook/assets/diagrama de backend em node.png" alt=""><figcaption></figcaption></figure>

Abaixo será mostrado baseado em um projeto real.&#x20;

### Instalação

1. `npm init -y`: Cria o package.json.
2. `npm install express mongoose dotenv nodemon body-parser`: Instalar dependências.
   1. **express**: Framework para criar o servidor.
   2. **mongoose**: Biblioteca para manipular MongoDB.
   3. **dotenv**: Para configurar variáveis de ambiente.
   4. **nodemon**: Reinicia o servidor automaticamente ao salvar mudanças.
   5. **body-parser**: Analisa o corpo das requisições (JSON).

### Configuração de conexão

Criaremos um arquivo chamado `db.js` responsável por configurar a conexão usando moongose[^1]. Ele vai se <mark style="color:blue;">conectar ao banco de dados</mark> usando a string de conexão que é fornecida pelo MongoDB. Utilizaremos um arquivo .env para salvar a string de conexão de forma segura.

```yaml
# Arquivo .env
MONGO_URI=STRING DE CONEXÃO AQUI
```

```javascript
import mongoose from "mongoose"
const dotenv = require('dotenv');

export const connectDB = async () => {
    try {
        await mongoose.connect(process.env.MONGO_URI)
        console.log("Conectado ao banco.")
    } catch (error) {
        console.error("Erro na conexão com o banco: ", error)
        process.exit()
    }
}
```

### Configuração do servidor

Esse arquivo `app.js` é o núcleo da aplicação com [<mark style="color:purple;">Express</mark>](#user-content-fn-2)[^2], que <mark style="color:blue;">integra os componentes</mark>. Usar `export const app = express()` estamos criando o aplicativo Express, que é a base para gerenciar rotas, middlewares e configurações e o export simboliza que ele poderá ser usado em outros arquivos.

* Define as rotas usadas: Quando uma requisição chega ao servidor, o Express verifica as rotas conectadas e redireciona a requisição para o [controlador ](backend.md#controladores)correspondente. O controlador, por sua vez, processa a lógica e retorna uma resposta.
* Estabelece conexão com o banco de dados: Usando a função criada na instalação, no arquivo `db.js`.
* Configura [<mark style="color:purple;">middlewares</mark>](#user-content-fn-3)[^3]: Como habilitar o CORS[^4].

```javascript
// Importações de framework
import express from "express"
import cors from "cors"

// Importação da configuração de conexão, criada no outro arquivo
import { connectDB } from "./db.js"

// Importação das rotas do projeto
import classificationRoutes from "./routes/classificationRoutes.js"
import kartTrackRoutes from "./routes/kartTrackRoutes.js"

// Criar o aplicativo express (gerenciar rotas, middlewares e configurações)
// e exportar para ser usado em outros arquivos
export const app = express()

// Middleware que vai permitir compartilhamento de recursos de
// diferentes domínios
app.use(cors())

connectDB()

// Registra middlewares ou rotas para lidar com requisições, conectando os arquivos
// de rotas importados na raíz do projeto
app.use("/", classificationRoutes, kartTrackRoutes)
```

### Inicialização do servidor

O arquivo `server.js` é responsável pelo ponto de entrada do servidor. Rodar esse código <mark style="color:blue;">coloca o servidor no modo escuta</mark>, garantindo que a aplicação está acessível para receber requisições HTTP na porta 3000 (passa a escutar ela). Esse arquivo depende do app, ao qual já tem as configurações necessárias como rotas registradas e middlewares e já conecta ao banco.

```javascript
// Ponto de entrada de inicialização do servidor, garante requisições HTTP

// Objeto app é uma instância do Express preparado com middlewares,
// configurações e conexões de rotas
import { app } from "./app.js"

const PORT = 3000

// Coloca no modo escuta para requisições
app.listen(PORT,()=>{
    console.log("Aplicativo rodando na porta: " + PORT + ".")
})
```

### Modelos

Um modelo é uma <mark style="color:blue;">abstração de uma tabela ou coleção no banco de dados</mark>, definindo a **estrutura**, **propriedades** e **comportamento** dos documentos que serão armazenados em uma coleção. Um modelo em Mongoose <mark style="color:blue;">define como esses documentos devem ser estruturados</mark> e as regras para manipulá-los.

Servem para garantir que os dados sejam armazenados no formato correto. Também podem fornecer métodos convenientes para manipular os dados (como consultas, atualizações e exclusões) e fornecer regras de validação e comportamento. Eles serão usados pelos [controladores](backend.md#controladores).

```javascript
import mongoose from 'mongoose';

const Schema = new mongoose.Schema({
    peso: String,
    nome: String,
    tempo: {
        minutos: Number,
        segundos: Number,
        milissegundos: Number,
        totalEmMs: Number
    },
    estado: String,
    kartodromo: String,
}, { versionKey: false } );

const Classification = mongoose.model('Classification', Schema);

// Exporta para ser usado por um controlador
export default Classification;
```

```javascript
import mongoose from 'mongoose';

const Schema = new mongoose.Schema({
    email: String,
    endereco: String,
    nome: String,
    telefone: String,
    whatsapp: String,
    desc: String,
    horario_funcionamento: String,
});

const Kart_Track = mongoose.model('Kart_Track', Schema);

// Exporta para ser usado por um controlador
export default Kart_Track;
```

### Controladores

Eles vão ser responsáveis, após receber uma requisição, por <mark style="color:blue;">processar a lógica necessária</mark>, como validações e chamadas ao banco de dados e <mark style="color:blue;">depois retornar as respostas</mark>. Nos exemplos abaixo, a lista de documentos encontrados é enviada de volta ao cliente em formato JSON.

```javascript
// Exemplo de um MODELO sendo usado para operações no banco de dados (find)
const classifications = await KartTrack.find(filter)

// Resposta que o CONTROLADOR precisa entregar, nesse caso, os resultados do find
res.json(classifications)
```

Esses controladores serão importados nas [rotas](backend.md#rotas), e ele será chamado toda vez que houver uma requisição naquela rota. Ele vai usar um [modelo ](backend.md#modelos)para realizar operações no banco.

No arquivo, define-se <mark style="color:blue;">um controlador para cada operação</mark> ou conjunto de operações que será desejado realizar no banco de dados, geralmente agrupando-as por funcionalidade ou tipo de recurso.

```javascript
import Classification from "../models/classification.js"
import net from "net"

export const getClassification = async (req, res) => {
    try {
        const { weight, karttrack, name } = req.params

        const filter = {}
        if (karttrack !== "null") filter.kartodromo = karttrack
        if (weight !== "null") filter.peso = { $gte: parseInt(weight), $lte: parseInt(weight) + 9 }
        if (name !== "null") filter.nome = name

        const classifications = await Classification.find(filter).sort({ "tempo.totalEmMs": 1 })
        res.json(classifications)
    } catch (error) {
        console.error(error)
        res.status(500)
    }
}
```

```javascript
import KartTrack from "../models/kart_track.js"

export const getKartTracks = async (req, res) => {
    try {
        const { name } = req.params

        const filter = {}
        if (name != "null") {filter.nome = { $regex: name, $options: "i" }}

        const classifications = await KartTrack.find(filter)
        res.json(classifications)
    } catch (error) {
        console.error(error)
        res.status(500)
    }
}
```

### Rotas

O [**rotedor** ](#user-content-fn-5)[^5]é onde você conecta **URLs** a **funções do controlador**. Quando o cliente faz uma requisição para tal rota, o roteador <mark style="color:purple;">encaminha as requisições para o controlador</mark> associado e assim segue o caminho a partir de lá. Os dados enviados no corpo da requisição (JSON) serão processados pelo controlador.

As rotas criadas são exportadas para serem usadas no `app.js`.

```javascript
import { Router } from "express"

// Importa as funções dos controladores
import { postClassification, getClassification} from "../controllers/classificationController.js"

// Router cria um conjunto de rotas. Essa instância será usada para registrar as rotas associadas aos controladores acima
const classificationRoutes = Router()

// Definições das rotas para os caminhos específicos, os dados enviados no corpo da requisição (JSON) serão processados pelo controlador
classificationRoutes.get("/classifications/:karttrack/:weight/:name", getClassification)
classificationRoutes.post("/classifications", postClassification)

// Exporta para ser usado no app.js
export default classificationRoutes
```

[^1]: Mongoose é um biblioteca de Modelagem de Dados de Objeto para MongoDB e Node.js. Ele é usado como tradutor entre objetos no código e a representação desses objetos no MongoDB.

[^2]: Framework que manipula requisições e respostas no Node.js.

[^3]: Middlewares são etapas pelo qual uma requisição passa antes de chegar ao seu destino final (ou controlador)

[^4]: Middleware que permite que seu servidor aceite requisições de outros domínios.

[^5]: Será chamado como arquivo da rota.
