# Props

Possibilidade de <mark style="color:blue;">passar valores ou funções de um componente pai para o componente filho</mark>, útil quando estamos lidando com dados vindos do back-end. Isso é responsável para gerar <mark style="color:purple;">componentes dinâmicos</mark>.&#x20;

Basicamente, quando o componente é inserido em algum lugar, ele pode receber tags, que serão esses dados. Essas tags são recebidas no arquivo do componente, onde podem ser manipuladas.

```jsx
function App() {
  const [peso] = userState(72.50);
  return (
    <div>
      // Usando o componente e enviando propriedades
      <MeuComponente dado={peso} />
    </div>
  );
}
```

```jsx
const ShowUserName = (props) => {
  return (
    <div>
      <h2>Peso recebido: {props.dado}</h2>
    </div>
  );
};

export default ShowUserName;
```

#### Caso de funções

Se temos uma função declarada no elemento pai, ela também pode ser passada como props para o componente filho, como mostra abaixo. No componente filho, pode ser usada livremente, por exemplo, incluindo em tags tipo button formando algo do tipo:&#x20;

```jsx
<button onClick={children}>Executar função</button>
```

```jsx
function App() {
  function showMessage() {
    console.log("!");
  }
  
  return (
    <div>
      // Usando o componente e enviando propriedades
      <MeuComponente myFuncion={showMessage} />
    </div>
  );
}
```

## Destructuring em props

Vimos que [destructuring ](../../javascript/destructuring.md)é uma forma em Javascript de receber dados, destruturando elas. Isso é útil pois normalmente são passadas várias propriedades e não apenas uma visto no exemplo acima (normalmente em um objeto).

Na imagem abaixo, seria como faríamos da forma acima. Com destructuring, o parâmetro `props` deixa de existir e já é recebido como um objeto, no formato do destructuring. Assim, podemos usar as variáveis como se elas tivessem declaradas no arquivo:

<figure><img src="../../../../.gitbook/assets/image.png" alt=""><figcaption></figcaption></figure>

```jsx
// App.jsx
<CarDetailsDestructuring brand="Toyota" km={56322} color="black" />

// CarDetailsDestructuring.jsx
const CarDetailsDestructuring = ({brand, km, color}) => {
  return (
    <div>
      <h2>Detalhes:</h2>
      <li>
        <ul>Marca: {brand}</ul>
        <ul>Km: {km}</ul>
        <ul>Cor: {color}</ul>
      </li>
    </div>
  );
};
```

## Enviar objetos inteiros

Se o componente precisa de grandes quantidades de propriedades armazenadas em um objeto, é válido passar o objeto inteiro. Para isso, basta seguir a primeira lógica.

```jsx
// App.jsx
function App() {
  const obj = {
    id: 111,
    carName: "test"
  }

  return (
    <>
      // Vai passar o objeto inteiro, com a key "obj"
      <CarDetailsObject obj={obj} />
    </>
  );
}

// CarDetailsObject
const CarDetailsDestructuring = (props) => {
  return (
    <div>
      <h2>Detalhes:</h2>
      <li>
        // Acessado dessa forma, já que props é um objeto, então objeto que
        // acessa outro até chegar no elemento carName
        <ul>Test name: {props.obj.carName}</ul>
      </li>
    </div>
  );
};
```
