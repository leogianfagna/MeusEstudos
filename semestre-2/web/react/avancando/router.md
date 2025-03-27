---
description: >-
  É uma biblioteca muito grande e possivelmente seja útil chegar a documentação
  do React Router. Os aprendizados nesta página, na maioria das vezes, são os
  principais e usados em todas as aplicações.
---

# Router

É um pacote externo (então precisa instalar) que cria uma estrutura de rotas permitindo criar múltiplas páginas para serem navegadas.&#x20;

```bash
npm install react-router-dom
```

## Princípio de uso

Utilizamos 3 componentes na configuração:

* `BrowserRouter` é o componente que **habilita o uso de rotas** na aplicação, utilizando a **API de histórico do navegador (history API)** para navegação sem recarregar a página. Por conta disso, ele deve <mark style="color:blue;">envolver toda a aplicação</mark>.
* `Routes` para definir as rotas. O que estiver fora do que ele envolve, estará <mark style="color:orange;">presente em todas as páginas</mark>.
* `Route` que configura cada rota com path e seu respectivo componente.

### Configuração

Consiste em importar os componentes do ReactRouter, importar os componentes criados por nós (cada página é um componente) e envolver a aplicação no `BrowserRouter`.

Veja que cada `Route` define um path e elemento. Veja também que há elementos fora do Routes do BrowserRouter, o que significa que eles aparecerão em todas as páginas.

```jsx
import { BrowserRouter, Routes, Route } from "react-router-dom";

import Home from "./pages/Home";
import About from "./pages/About";

function App() {

  return (
    <div className="App">
      <h1>Elemento Padrão nas páginas</h1>
      <BrowserRouter>
        <span>Elemento repetido em todo lugar também</span>
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/about" element={<About />} />
        </Routes>
      </BrowserRouter>
    </div>
  );
}

export default App;
```

As páginas podem ser acessadas através do uso da rota:

<figure><img src="../../../../.gitbook/assets/react router rotas.png" alt=""><figcaption></figcaption></figure>

### Páginas

Como dito, as páginas são componentes normais criados por nós. Por convenção, é criado esses componentes em uma pasta separada chamada **pages**, diferente de components.

<figure><img src="../../../../.gitbook/assets/pasta pages do react.png" alt=""><figcaption></figcaption></figure>

## Navegação

Para navegar para outras páginas, podemos:

* Usar o <mark style="color:blue;">elemento \<a></mark> para navegar entre rotas com href. Mas isso <mark style="color:red;">causa na atualização da página</mark>, ou seja, não recomendado.
* Usar próprio recurso do React Router <mark style="color:blue;">Link</mark>, que <mark style="color:green;">previne o recarregamento</mark> da página e torna a experiência de usuário muito melhor.

Como dito, `BrowserRouter` precisa envolver elementos de rotas para funcionar. Portanto, o Link deve estar dentro dele para funcionar.

Nesse exemplo, como a `nav` está criada fora de Routes, ela vai se **repetir** em todas as páginas.

```jsx
<BrowserRouter>
  <nav>
    <Link to="/about">About</Link>
  </nav>

  <Routes>
    <Route path="/" element={<Home />} />
    <Route path="/about" element={<About />} />
  </Routes>
</BrowserRouter>
```

## Rota dinâmica

Consiste em uma nova rota que é criada dinamicamente através de um dado. Exemplo prático disso é uma rota `/products/celular` que mostra todos os dados de um produto chamado celular. Essa rota não foi criada individualmente.

Para definir algo dinâmico, colocar uma `/:` depois da rota com o elemento que será usado para criá-la, desta forma:

```jsx
<Route path="/products/:id" element={<Product />} />
```

A partir disso, já é possível acessar a rota qualquer dela, tipo `localhost:5173/products/1`, mas não terá nada nela.

Para criar conteúdo dentro dessa rota, usamos o <mark style="color:purple;">**Link**</mark> que leva para essa rota dinâmica e depois o hook <mark style="color:purple;">**useParams**</mark> para trazer o conteúdo usado para acessar a rota (no caso abaixo, o `item.id`).

```jsx
// Em alguma página para levar até nossa rota
const items = { ... };
<Link to={`/products/${item.id}`}/>
```

<pre class="language-jsx"><code class="lang-jsx">import { useParams, useEffect, useState } from "react-router-dom";

const Product = () => {
  const { id } = useParams();
  const [produto, setProduto] = useState(null);

  useEffect(() => {
<strong>    fetch(`http://localhost:3000/products/${id}`)
</strong>      .then((res) => res.json())
      .then((data) => setProduto(data));
  }, [id]);

  if (!produto) return &#x3C;p>Carregando...&#x3C;/p>;

  return (
    &#x3C;div>
      &#x3C;h2>{produto.nome}&#x3C;/h2>
      &#x3C;p>{produto.descricao}&#x3C;/p>
      
      { /* Exemplo de Nested Route: Próximo tópico */ }
      &#x3C;Link to={`products/${produto}/reviews`}>Avaliações&#x3C;/Link>
    &#x3C;/div>
  );
};
</code></pre>

Perceba que, o `id` recebido na rota dinâmica é <mark style="color:red;">apenas um número e não tem utilidade sozinho</mark>. Esse id vai servir para resgatar os dados que queremos através de um fetch, cujo url foi concatenada (linha marcada). Isso quer dizer que podemos criar <mark style="color:purple;">**dados dinâmicos**</mark> usando as rotas dinâmicas.

A lógica de funcionamento fica:

<figure><img src="../../../../.gitbook/assets/logica de funcionamento de rotas dinamicas.png" alt=""><figcaption></figcaption></figure>

## Nested route

São rotas ainda mais complexas, que podem estar **depois** de uma rota dinâmica (ou seja, um próximo componente) <mark style="color:green;">sem perder o id passado</mark>, por exemplo:

> `localhost:5173/products/:id/mais_alguma_coisa`

Então funcionam igual a uma rota dinâmica. Veja que foi incluído no exemplo acima de rota dinâmica um link para o Nested Route para ter uma ideia. Neste exemplo, estamos dentro do componente `Product/:id` e temos um link para um outro componente chamado `Review`, e a base para essa rota segue a mesma anterior, mantendo o product e o id.

Isso faz com que, ao chegar nessa rota, podemos <mark style="color:orange;">repetir exatamente o mesmo processo</mark> com **useParams** para resgatar o id e fazer a mesma coisa, mas agora em uma página mais limpa.

Essa rota também precisa ser declarada no App.jsx:

```jsx
<Route path="/products/:id/reviews" element={<Review />} />
```

{% hint style="success" %}
Criar o componente Review é literalmente **copiar e colar o componente Product** acima, apenas alterando os elementos HTML que você quiser.
{% endhint %}

## No match route (404)

Uma rota declarada com `*` que qualquer rota que saia dos padrões definidos por nós, visite essa rota, que é uma página/componente que criamos e deve ser importada. Por padrão, é criado como última rota da lista.

<pre class="language-jsx"><code class="lang-jsx">&#x3C;BrowserRouter>
  &#x3C;Routes>
    &#x3C;Route path="/" element={&#x3C;Home />} />
    &#x3C;Route path="/about" element={&#x3C;About />} />
    &#x3C;Route path="/products/:id" element={&#x3C;Product />} />
    &#x3C;Route path="/products/:id/reviews" element={&#x3C;Review />} />
<strong>    &#x3C;Route path="*" element={&#x3C;NotFound />} />
</strong>  &#x3C;/Routes>
&#x3C;/BrowserRouter>
</code></pre>

## Link ativo

É o caso quando fica marcado em uma barra de navegação em qual página estamos. Para implementar essa ideia, é necessário trocar os componentes usados anteriormente `Link` para `NavLink` pois eles fazem a mesma função e tem a propriedade `isActive`.

```diff
 <nav>
-   <Link to={`/products`}>Página do produto</Link>
+   <NavLink to={`/products`}>Página do produto</Link>
 </nav>
```

Essa propriedade <mark style="color:green;">reconhece e adiciona automaticamente</mark> classe do css se chamada de **active**. Então, basta criar uma classe com esse nome que ela será adicionada ao elemento ativo da nav bar, como por exemplo:

```css
.active {
    background-color: green;
    color: white;
}
```

{% hint style="success" %}
Caso necessário, esse elemento também pode ser utilizado como uma variável. Sendo assim, possibilitando a criação de lógicas mais compostas de estilos, como:

```jsx
<NavLink
  to="/"
  className={({ isActive }) =>
    isActive ? "alguma classe" : "outra clase"
  }
>
  Início
</NavLink>
```
{% endhint %}

## Search Params

Serve para buscar dados mas que o parâmetro de busca utilizado fique na URL da página, fazendo com que a busca não se perca ao recarregar ou até podendo compartilhar o endereço gerado.

## Redirecionamento de páginas

Suponha que uma URL deixe de existir. Para usuários não caírem em uma página inexistente, podemos redirecionar todos que <mark style="color:blue;">acessem essa URL para outra</mark>.

Basta manter a mesma URL antiga, mas com o hook `Navigate`:

```jsx
import { Navigate } from "react-router-dom";
<Route path="/old_url" element={<Navigate to="/about" />} />
```
