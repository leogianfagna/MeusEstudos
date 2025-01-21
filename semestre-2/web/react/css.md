# CSS

As classes em CSS são aplicadas nos elementos HTML através da tag `className`.

## Estilos globais

Dentro da pasta src, o arquivo `index.css` representa os <mark style="color:purple;">estilos globais</mark>, que aplica os estilos para todos os arquivos e **também componentes**.

## Componentes

Criamos um arquivo no mesmo diretório com o mesmo nome do componente e importamos esse CSS no arquivo do componente.

```javascript
import "./App.css";
```

O CSS dos componentes tem um problema pois <mark style="color:red;">ele vaza</mark> (não é scoped). Isso quer dizer, se definir um estilo para o elemento `<p>`, esse estilo também vai ser aplicado no `App.jsx`. Por isso, devemos sempre usar classes para que isso não aconteça. Isso ocorre porque o CSS tradicional não tem escopo local ou isolamento por padrão.

### Biblioteca de estilos escopados

Essa biblioteca permite fazer CSS dentro do componente, útil para regras muito específicas.

```jsx
import styled from 'styled-components';

const Button = styled.button`
  background-color: blue;
  color: white;
  border: none;
  padding: 10px;
`;

function App() {
  return <Button>Click me</Button>;
}
```

## Estilos in-line

São aqueles estilos definidos dentro de uma tag HTML com `style`. Eles devem sempre ser evitados por conta de manutenção. Sua aplicação ocorre entre chaves pois eles simbolizam um objeto, desta forma:

```jsx
<p style={{color: "black", padding: "20px", userSelect: "none"}}>Texto estilizado</p>
```

### In-line dinâmico

Como acima são objetos, podemos fazer regras e estilos baseado em condições usando operadores ternários. Ainda **não é a melhor prática de se utilizar**, mas aqui mostra como seria possível fazer:

```jsx
const n = 15;
<p style={ n < 10 ? { color: "purple" } : { color: "green" } }>Condição</p>
<p style={ n < 10 ? { color: "purple" } :        null        }>Condição</p>
```

## Classes dinâmicas

Essa situação traz os conhecimentos visto no estilos in-line para as classes, onde é a **melhor situação de aplicação**. O código vai mudar de classe baseado em condições de variáveis.

```jsx
const redTitle = true;
<h1 className={redTitle ? "red-title" : "normal-title"}>Status da página</h1>
```

```css
.red-title {
    color: red;
    border: 5px solid black;
}

.normal-title {
    color: white;
    padding: 15px;
}
```

## CSS Modules

Forma de criar arquivos de estilos para componentes que não são vazadas para outras páginas herdadas. O arquivo CSS é importado <mark style="color:blue;">virando um objeto dentro do componente</mark> (chamamos de `styles` por convenção), podendo utilizar os estilos como se fosse os atributos desse objeto. Consiste em:

1. Criar o arquivo css com a nomenclatura `NomeComponente.module.css`.
2. Importar o estilo com `import styles from "./NomeComponente.module.css"`.
3. Utilizar como se fosse um objeto:

```jsx
import styles from './NomeComponente.module.css'

<h1 className={styles.main_title}>Título da Página</h1>

// Quando a classe tem traço "-"
<h1 className={styles['main-title']}>Título da Página</h1>
```

As convenções de nome de estilos dentro de componentes serão utilizadas com underline pois CSS Modules não lida de forma adequada com os traços `-`.
