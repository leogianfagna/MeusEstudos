# Componentes

Componentes em React são blocos reutilizáveis de código que encapsulam partes específicas da interface e o comportamento associado. Basicamente são o coração do React e como ele é formado.

Na prática comum, cada arquivo do tipo JSX (uma sintaxe que permite escrever HTML dentro do JavaScript) representa um componente. Esses arquivos são nomeados com PascalCase e são salvos em um `assets/components`.

## Criar componente

O componente é composto por:

* Função: Compõe a lógica e o template.
* Retorno: Precisa retornar nesta função o resultado final do componente.
* Exportação: Essa função/componente é exportada para ser usada em outro componente, tipo o componente principal App.jsx.

Usa uma função anônima. A estrutura do componente fica dentro do `return`. Esse é um exemplo prático de um componente:

```javascript
const FirstComponent = () => {
    return (
        <div>
            <h1>Meu componente</h1>
        </div>
    );
};

export default FirstComponent;
```

## Usar componente

Depois de criado, um componente pode ser usado em outro ao importá-lo. As importações ficam no início da página. O nome do componente vira uma tag para inserir no corpo, desta forma:

```jsx
// Importação
import NomeComponente from './components/NomeComponente'

// Uso dentro do corpo. Tag abre e fecha
<FirstComponent/>
```

Exemplo prático:

```javascript
import FirstComponent from './components/FirstComponent'

import './App.css'

function App() {
  return (
    <>
      <p>Nosso componente importado:</p>
      <FirstComponent/>
    </>
  )
}

export default App
```

## Template expressions

Isso mostra para gente que dentro do corpo JSX podemos executar Javascript. Então por exemplo, dentro de uma tag `<p>` podemos incluir uma expressão `{ 4 + 4 }`. Isso é importante para usar variáveis dentro das tags HTML de componentes, desta forma:

```jsx
const TemplateExpressions = () => {
  const obj = {
    message: "Hello",
    sender: "Marcos"
  };

  return (
    <div>
      <h1>{obj.message} from {obj.sender}</h1> // Usando variáveis declaradas acima
      <p>4 + 4 equivale {4 + 4}</p> // Mostrando o uso de JS dentro da tag
      <p>{console.log("Mostrando que podemos executar funções também")}</p>
    </div>
  );
};

export default TemplateExpressions;
```

## Hierarquia

Conforme vamos criando componentes que abraçam outros componentes (quando importa um componente dentro do outro, tipo `App.jsx`), vamos criando uma hierarquia. Um componente que importa outro, será chamado de pai.

Contudo, esse componente pode e provavelmente será usado em vários outros, o que pode criar estruturas de irmãos.&#x20;

```jsx
function App() {
  return (
    <>
      <FirstComponent/>
      <AnotherComponent/>
    </>
  )
}
```

```jsx
function FirstComponent() {
  return (
    <>
      <AnotherComponent/>
    </>
  )
}
```

`FirstComponent` e `AnotherComponent` são filhos de App, consequentemente são irmãos. Mas `AnotherComponent` também é filho de `FirstComponent`, pois está sendo utilizado nele.

## Reutilização

Com as [props](../avancando/props.md), a reutilização de componentes começa a fazer sentido pois agora não teremos componentes estáticos e podemos reaproveitar tudo do componente, como estilos, formatos, etc, mudando apenas os dados deles, tipo os títulos.

Veja abaixo o reaproveitamento do componente CarDetailsDestructuring, onde todas as informações que preenche esse componente são fornecidas através de props.

```jsx
import CarDetailsDestructuring from "./components/CarDetailsDestructuring";

function App() {
  return (
    <div className="tabela-carros">
      <CarDetailsDestructuring brand="Toyota" km={0} color="black" />
      <CarDetailsDestructuring brand="Fiat" km={53442} color="white" />
      <CarDetailsDestructuring brand="Toyota" km={0} color="gray" />
      <CarDetailsDestructuring brand="Renault" km={12432} color="black" />
    </div>
  );
}

export default App;
```

### Replicação

Visto acima, se temos uma lista muito grande de produtos e precisamos exibir todos, podemos usar o que vimos em [renderização de lista](../avancando/renderizacao-de-lista.md) para renderizar todos os produtos. Vai consistir exatamente da mesma forma, mas em vez de renderizar tags HTML para cada iteração, vai ser renderizado o componente em si:

```jsx
function App() {
  const carData = [
    { id: 1, brand: "Toyota", km: 0, color: "black"},
    { id: 2, brand: "Fiat", km: 0, color: "gray"},
    { id: 3, brand: "Renault", km: 0, color: "red"},
    { id: 4, brand: "Toyota", km: 0, color: "white"}
  ]

  return (
    <div>
      {carData.map((car) => (
        <CarDetailsDestructuring key={car.id} brand={car.brand} km={car.km} color={car.color} />
      ))}
    </div>
  );
}
```
