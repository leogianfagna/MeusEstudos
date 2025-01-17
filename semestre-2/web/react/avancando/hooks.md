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
  const [number, setNumber] = useState(10);

  return (
    <div>
      <button onClick={() => setNumber(20)}>Mudar valor variável</button>
      <p>Valor do dado: {number}</p>
    </div>
  );
};

export default ManageData;
```

[^1]: Como estado e ciclo de vida
