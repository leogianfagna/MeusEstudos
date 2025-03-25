# Hooks

São funções que usam [recursos do React](#user-content-fn-1)[^1] prontas para serem importadas e utilizadas nas aplicações. Também podemos fazer nossos próprios hooks e tem como o propósito a <mark style="color:blue;">reutilização</mark>. Eles tem uma nomenclatura com o prefixo "use".

#### Exemplo comum de uso de hook

O hook mais comum é o `useState`. Temos um problema que, se uma variável se alterar ao longo do Javascript, seu novo valor não é renderizado novamente na página. Esse hook monitora o estado de um dado. Exemplo disso:

```jsx
const ManageData = () => {
  let someData = 10;

  return (
    <div>
      <p>Valor do dado: {someData}</p>
      <button onClick={() => (someData = 15)}>Mudar valor variável</button>
    </div>
  );
};
```

O dado `someData` está sendo alterado no botão, mas ele não deixa de exibir 10 na página.

#### Recursos reacts legados

Podemos resolver o problema acima com o método setState, fornecido também pelo React. Esse método não é um hook, mas pode ser utilizado para a mesma funcionalidade. Os hooks são uma <mark style="color:blue;">solução moderna</mark>. Na própria documentação do React diz que não será mais atualizado.

## Utilização de hooks

Criamos uma variável que recebe o retorno do hook que vamos usar (podemos chamar de destruturação como array), usaremos como exemplo o `useState`.

```jsx
const [number, setNumber] = useState();
const [number, setNumber] = useState(15); // Se queremos inicializar "number"
```

A função recebida do hook agora pode ser utilizada para alterar o valor de number, como por exemplo:

```jsx
// Precisamos importar o hook
import { useState } from "react";

const ManageData = () => {
  const [number, setNumber] = useState(10); // setNumber pode ser qualquer nome

  return (
    <div>
      <button onClick={() => setNumber(20)}>Mudar valor variável</button>
      <p>Valor do dado: {number}</p>
    </div>
  );
};

export default ManageData;
```

## Estado anterior

Vimos acima que o hook useState altera o estado de um elemento, mas neste caso, para um número já definido e estático. Talvez possa ser necessário usar o estado atual para definir o novo valor de alteração, assim chamamos de <mark style="color:purple;">previous state</mark>. Muito comum em contadores, onde você precisa identificar qual número atual do contador para somar mais um.

Sempre será resgatado o estado do elemento que está relacionado com ele. Vendo o exemplo acima, o método `setNumber` conseguirá resgatar o estado anterior da variável number, pois eles estão relacionados.

<figure><img src="../../../../.gitbook/assets/previous state react.png" alt=""><figcaption></figcaption></figure>

O estado anterior do elemento é passado como argumento da função. Então, se usássemos `setNumber(x)`, o valor de `x` será o estado anterior de number. Por convenção, a nomenclatura fica `prevElemento`.

```jsx
import { useState } from "react";

const EstadoAnterior = () => {
  const [varTeste, setState] = useState(15);

  const dobrarValor = () => {
    // Chama a função setState
    setState((prevState) => prevState * 2); // Recebe prevState no parâmetro
  };

  return (
    <div>
      <p>Valor atual: {varTeste}</p>
      <button onClick={dobrarValor}>Dobrar valor atual</button>
    </div>
  );
};

export default EstadoAnterior;
```

## Principais Hooks

### useEffect

Escuta qualquer efeito colateral que a página recebe (uma renderização, chamada de API, etc) e executa um código toda vez que isso acontece. Permite utilizar argumentos que fazem com que ele execute apenas se um determinado estado altera (por exemplo, o valor de alguma variável).

```jsx
const [nome, setNome] = useState('');

useEffect(() => {
    console.log("Executarei toda vez que nome mudar.");
}, [nome]);
```

É bom pensar que os componentes do React estão sempre se renderizando, então as vezes é importante ter ações únicas. Por isso, o useEffect também é muito utilizado nas <mark style="color:orange;">requisições assíncronas</mark>, como <mark style="color:green;">renderizar a chamada da API apenas uma vez</mark>.



[^1]: Como estado e ciclo de vida
