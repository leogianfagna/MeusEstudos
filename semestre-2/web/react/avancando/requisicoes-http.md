# Requisições HTTP

De forma nativa no React, podemos utilizar a Fetch API para resgatar os dados de uma rota, com `fetch(url)`.

<details>

<summary>Como definir uma rota local de teste</summary>

Crie uma base de dados em JSON no caminho `meu-projeto/data/db.json`. Exemplo:

```json
{
  "products": [
    {
      "id": 1, "name": "Camisa", "price": 59.9
    },
    {
      "id": 2, "name": "Calça vermelha", "price": 90
    },
    {
      "id": 3, "name": "Boné aba reta", "price": 29.9
    }
  ]
}
```

Depois instale o pacote Json server, para criar um servidor local de hospedagem de dados: `npm i json-server`.

Em scripts do `package.json`, implemente um novo script para rodar esse servidor, desta forma:

```json
  "scripts": {
    "dev": "vite",
    "build": "vite build",
    "lint": "eslint .",
    "preview": "vite preview",
    "server": "json-server --watch data/db.json" // Novo script
  },
```

Ligue com `npm run server` e agora seus dados estarão disponíveis como se fosse em uma rota em `http://localhost:3000/products`. Faça uma variável assumir este valor para acessar, já com os exemplos abaixo.

</details>

## Rotas

Precisamos conhecer as rotas que vamos utilizar para as requisições. Convencionalmente, definimos uma variável chamada url que recebe a rota, exemplo:

```javascript
// Definir a URL que vamos utilizar
const url = "http://localhost:3000/products";
const url = "http://www.dominio.com.br/rotaroot/";
```

Jogar essas rotas no navegador já é possível ver a saída em formato JSON. Normalmente, temos sub-rotas para utilizar, que podem expressar diferentes resultados, como por exemplo `/root/calcular`. Então podemos definir a url base e depois <mark style="color:green;">concatenar posteriormente</mark> de acordo com a rota que queremos, por exemplo:

```jsx
// Isso fica dentro do método FETCH
const res = await fetch(`${url}calcular/`, { // Concatenação
    method: "POST",
    // ...
```

## GET

As requisições HTTP guardam os dados no código com useState. Para a API não ser chamada diversas vezes durante a execução do código (por conta do comportamento do React de renderizar), podemos utilizar o hook de useEffect e chamam a API uma única vez de forma assíncrona.

O métogo GET não precisa ser identificado, como `method: "GET"` pelo fato dele ser o método HTTP padrão.

```javascript
// Dados são salvos com estado
const [products, setProducts] = useState([]);

// Uso do useEffect para chamar a API
useEffect(() => {
  async function fetchData() {
    const res = await fetch(url);
    const data = await res.json();
    setProducts(data);
  }

  fetchData();
}, []);
```

## POST

Esse método exige um body (enviar algo na requisição), normalmente sendo um JSON (ou objeto). Veja abaixo, sendo `jsonData` um arquivo JSON importado externamente.

```jsx
const [apiData, setApiData] = useState([]);

async function fetchData(jsonData) {
  try {
    const res = await fetch(`${url}calculate/`, {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify(jsonData),
    });

    const data = await res.json();
    setApiData(data);
  } catch (error) {
    console.error(error);
  }
}
```

## Carregamento de dados dinâmicos

Se estamos usando um `GET` para resgatar dados (e apenas uma vez como visto acima), ao usar um `POST`, teoricamente não veremos esse novo dado ao menos que a tela seja recarregada ou que use um `GET` novamente. Ambos os casos são mal perfomáticos.

Se podemos ter a variável com todos os dados resgatados através do [estado anterior](hooks.md#estado-anterior) de `products`, ao fazer um `POST` podemos simplesmente <mark style="color:green;">adicionar o novo dado de forma manual</mark> nessa lista usando [spread operator](../../javascript/conceitos.md#spread-operator). Isso vai fazer com que o dado já apareça e de forma otimizada.

No código acima, não temos nenhum carregamento de dados dinâmico pois ele apenas implica em enviar um JSON e receber uma resposta.

Em um novo exemplo, vamos supor que queremos enviar algo para adicionar no banco e já visualizar na tela, podemos fazer utilizando o resultado `res` do `POST`, que será justamente o dado adicionado. Depois definir um novo valor para products, concatenando o estado antigo com o novo dado.

Criamos um objeto que representa o que será inserido no banco, no caso `product`. Ele recebe as variáveis que estamos lidando ao longo da vida do código, recebendo seus valores [através de formulários](formularios/formulario-nativo.md).

```jsx
const [name, setName] = useState("");
const [price, setPrice] = useState("");

const handleSubmit = async (e) => {
  e.preventDefault();

  const product = {
    name,
    price,
  };

  const res = await fetch(url, {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify(product),
  });
  
  // Carregamento de dados dinâmicos, veja abaixo
  const addedProducts = await res.json();
  setProducts((prevProducts) => [...prevProducts, addedProducts]);
};
```

## Custom Hook

Podemos refatorar o código para toda essa lógica ficar em um hook customizado por nós ([exemplo aqui](https://github.com/matheusbattisti/curso_react/blob/main/7_REQ_HTTP_REACT/httpreact/src/hooks/useFetch.js)), criado em `src/hooks` e pode ser usado nos componentes desta forma:

```jsx
import { useFetch } from "./hooks/useFetch";
const url = "http://localhost:3000/products";

function App() {
  const [products, setProducts] = useState([]);
  const { data: items, httpConfig, loading, error } = useFetch(url);
  
  const handleSubmit = async (e) => {
    e.preventDefault();
  
    const product = {
      name,
      price,
    };
      
    httpConfig(product, "POST");
    setName("");
    setPrice("");
  };
  
  const handleRemove = (id) => {
    httpConfig(id, "DELETE");
  };
  
  // ...
}
```

A lógica por trás é:

* `httpConfig` configura a requisição (método, header e body) que é necessária para cada tipo. Tenho esse método, já podemos também criar o delete sem muito mais código.
* `fetchData` continua a mesma lógica, mas agora uma nova lógica envolve a variável _callFetch_, que recebe o json e vira um parâmetro no useEffect, ou seja, toda vez que é alterado teremos o `fetchData` novamente.

### Estado de loading

Dados assíncronos podem demorar para chegar. Criar um estado de loading pode ser importante para mostrar um carregamento. Ele deve iniciar como false, tornando-se true dentro de qualquer função que tenha um retorno assíncrono e voltando para false quando bem sucedido.

Esse estado deve ser exportado em uma variável (assim como as outras data, httpConfig, etc), e utilizada no JSX, como:

```jsx
const { data: items, httpConfig, loading, error } = useFetch(url);

// JSX
{loading && <p>Carregando dados...</p>}
```

#### Loading no POST

Para evitar que o usuário envie mais de um formulário por conta de um duplo clique, podemos usar esse estado para evitar um novo POST.

```jsx
{loading && <input type="submit" disabled value="Criar"></input>}
{!loading && <input type="submit" value="Criar"></input>}
```

### Tratando erros

Mesma lógica do estado de loading, onde é apenas um estado marcado como false que se altera em caso de falha. As falhas podem ser capturadas utilizando um try catch que envolve o fetch de dados, como:

```jsx
const fetchData = async () => {
  try {
    const res = await fetch(url);
    const json = await res.json();
    setError(null);
  } catch (error) {
    console.log(error.message);
    setError("Houve um erro ao carregar os dados!");
  }
};
```
