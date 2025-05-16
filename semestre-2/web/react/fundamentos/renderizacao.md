# Renderização

Precisamos saber os conceitos de renderização do React para que possamos criar algo <mark style="color:green;">otimizado</mark>. Quando o React entra na sua fase de render, isto é, renderiza o seu componente, ele executa a função do componente e tudo o que está no corpo dela imediatamente.

```jsx
const MyForm = () => {
  // Variáveis
  const [state, setState] = useState(unit);
  const result = myFunction();

  // Funções
  function myFunction() {
    ...
  }

  // Eventos
  const handleSomething = (event) => {
    ...
  };

  return (
    < ... >
  );
};

export default MyForm;
```

Todo esse código acima é o que está dentro do corpo. Veja que a função `myFunction` também é renderizada imediatamente, pois ela é chamada ao ser atribuída a variável "result". Mas a função `handleSomething` não é renderizada, pois não está sendo chamada diretamente.

Enfim, só depois de renderizar todo o corpo que o React atualiza o DOM e dispara useEffect, useLayoutEffect, etc.

## Quando é renderizado

A renderização ocorre na primeira vez que o componente aparece e <mark style="color:blue;">toda vez que um estado se altera</mark>. Ou seja, se durante a execução do código nenhum estado se alterar, não há uma nova renderização.

Por isso existe a <mark style="color:green;">recomendação de salvar variáveis dentro de estados</mark> do **useState**. Se salvar variáveis comuns e alterá-las, isso não vai afetar a renderização. Por exemplo:

```jsx
const [number, setNumber] = useState(10);
const numberStateless = 10;

setNumber(15); // Renderiza o componente todo novamente
numberStateless = 15; // Não renderiza novamente
```

Isso pode afetar em casos de que você precisa do valor dos estados para imprimir no componente (ou usar em gráficos, por exemplo). Se você não precisa disso, talvez não seja necessário o uso de estados.

## Otimização e prevenção de loop

Chamadas de fetch data ou setState <mark style="color:red;">não devem estar diretamente chamadas no corpo</mark> porque geram **loop infinito**.&#x20;Podemos criar quantas funções queremos, mas é recomendado que elas não sejam chamadas durante a renderização, como é feito com o `myFunction`.

<mark style="color:green;">Para resolver isso</mark>, é uma boa prática deixar essas funções ou setStates dentro do **useEffect** ou funções de **handle**, que são chamadas algumas vezes com interações HTML.

### Exemplo real

Esse exemplo mostra códigos dentro de um corpo de um componente. Veja abaixo uma função que é chamada no corpo e dentro dela usa um useState:

```jsx
const keyList = [...]
const [key, setKey] = useState(null);
const keysFiltered = getKeyFromCategory(); // A função é chamada na render

function getKeyFromCategory(findKey) {
  if (keyList.find((k) => k === findKey)) {
    setKey(k.name); // useState dentro da função
    return k.name;
  }
}
```

Esse exemplo não roda pois cria um loop infinito. Para corrigir tal problema, fazemos:

* A variável `keysFiltered` não precisa ficar se atualizando a cada renderização e precisa assumir apenas um resultado somente. Portanto, movemos essa chamada para um useEffect. Para isso funcionar, deixamos ele declarado como um useState.
* Para remover a necessidade do `setKey` dentro de uma função, fizemos que essa função retorne um objeto e assim resgatamos qual parte do objeto queremos no código.

```jsx
const keyList = [...]
const [key, setKey] = useState(null);
const [keysFiltered , setkeysFiltered] = useState(null);

function getKeyFromCategory(findKey) {
  return keyList.find((k) => k === findKey));
}

useEffect(() => {
  setkeysFiltered(getKeyFromCategory(myKey));
}, []);
```
