# Formulários

O principal [hook ](hooks.md)utilizado durante os formulários será `useState` com o evento `onChange`, que permite identificar os dados coletados no formulário, assim como validá-los.

## Estrutura de um formulário

```html
<form>
  <label>
    <span>E-mail:</span>
    <input type="email" name="email" placeholder="Digite o email"></input>
  </label>

  <input type="submit" value="enviar"></input>
</form>
```

## Gerenciamento de dados

Usando o evento `onChange` no input, podemos resgatar o dado que está sendo inserido no mesmo. Criamos uma variável para o state de email e devemos criar para cada campo de formulário existente. O handleName recebe o evento e com `e.target.value` conseguimos em forma de variável o que foi digitado:

```jsx
const MyForm = () => {
    // Precisa atrelar esses valores ao dados inseridos nos formulários
    const [email, setMail] = useState()

    const handleName = (e) => {
        console.log(e.target.value);
    }

  return (
    <div>
      <form>
        <label>
          <span>E-mail:</span>
          <input type="email"
                 name="email"
                 placeholder="Digite o email"
                 onChange={handleName}>
          </input>
        </label>

        <input type="submit" value="enviar"></input>
      </form>
    </div>
  );
};
```

Se nós criarmos 10 formulários, teríamos que criar 10 funções. Quando quisermos <mark style="color:blue;">apenas o resgate dos valores do input</mark>, podemos usar a simplificação abaixo.

### Simplificação

Função inline do onChange.&#x20;

```jsx
const [email, setMail] = useState();

<label>
  <span>E-mail:</span>
  <input
    type="email"
    name="email"
    placeholder="Digite o email"
    onChange={(e) => setMail(e.target.value)}
  ></input>
</label>
```

## Envio

Usando o evento `onSubmit` que fica na tag `<form>`, que [<mark style="color:blue;">chama uma função</mark>](#user-content-fn-1)[^1] para validar os dados. O submit no HTML faz recarregar a página e perder os dados, por isso, dentro dessa função podemos usar o método `preventDefault` para isso não acontecer.

```jsx
const MyForm = () => {
  // Precisa atrelar esses valores ao dados inseridos nos formulários
  const [number, setNumber] = useState();
  const [email, setMail] = useState();

  const handleSubmit = (e) => {
    e.preventDefault();
    console.log("Enviando o form:");
    console.log(`Dados:\n Número: ${number}\n Email: ${email}`)
  }

  const handleNumber = (e) => {
    setNumber(e.target.value);
  }

  return (
    <div>
      {/* Criação do form */}
      <form onSubmit={handleSubmit}>
        
        // Feito usando arrow function para definir o dado
        <label>
          <span>E-mail:</span>
          <input
            type="email"
            name="email"
            placeholder="Digite o email"
            onChange={(e) => setMail(e.target.value)}
          ></input>
        </label>
        
        // Feito usando um método handleNumber
        <label>
          <span>Número:</span>
          <input
            type="number"
            name="email"
            placeholder="Coloque um número"
            onChange={handleNumber}
          ></input>
        </label>

        <input type="submit" value="enviar"></input>
      </form>
    </div>
  );
};
```

### Limpar o formulário

Se necessidade limpar o formulário (dados que estavam preenchidos) após o envio, basta apenas modificar `handleSubmit` para limpar os campos para strings vazias:

```jsx
const handleSubmit = (e) => {
  e.preventDefault();
  
  // Limpar
  setMail("");
  setNumber("");
}
```

## Controlled inputs (labels preenchidos)

Serve para <mark style="color:purple;">formulários de edição</mark>, onde dados já vem prontos (de [props](props.md)). Apenas é modificado o componente acima:

<figure><img src="../../../../.gitbook/assets/controlled inputs.png" alt=""><figcaption></figcaption></figure>

```jsx
// App.jsx
<MyForm userData={{number: 4556, email: "leo@gmail.com"}}/>

// MyForm.jsx
const MyForm = ({ userData }) => {
  const [number, setNumber] = useState(userData ? userData.number : "");
  const [email, setMail] = useState(userData ? userData.email : "");
  
  return (
    <form onSubmit={handleSubmit}>
      <label>
        <span>E-mail:</span>
        <input
          type="email"
          name="email"
          placeholder="Digite o email"
          onChange={(e) => setMail(e.target.value)}
          value={email} // Novo campo
        ></input>
      </label>
      ...
```

## UseRef para focar

É um hook que cria uma referência para algum lugar (elemento HTML) que neste caso será utilizado para o usuário estar com o teclado selecionado em algum input mesmo após o submit.

```jsx
const inputRef = useRef(null);

const handleSubmit = (e) => {
    inputRef.current.focus();
}

return (
    <form onSubmit={handleSubmit}>
        <input ref={inputRef}></input>
    </form>
);
```

[^1]: Normalmente chamada de `handleSubmit`.
