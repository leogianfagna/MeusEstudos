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

Usando o evento `onChange` no **input**, podemos resgatar o dado que está sendo inserido no mesmo. Criamos uma variável para o state de email e devemos criar para cada campo de formulário existente.

O evento gerado no onChange permite resgatar o valor inserido na propriedade `target.value`, sendo possível definir o valor da variável desta forma:

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

### Salvar todos os dados

Se temos uma grande entrada de dados, podemos salvar todos eles em um **objeto** (chamaremos de formData). Criamos uma função `handleChangeForm` que consegue resgatar o campo e o valor preenchido nele.

<figure><img src="../../../../.gitbook/assets/react form spread object.png" alt=""><figcaption></figcaption></figure>

O objeto gerado será desta forma:

<figure><img src="../../../../.gitbook/assets/objeto gerado.png" alt=""><figcaption></figcaption></figure>

### Objetos dentro de objetos (exemplo complexo)

Em um projeto real, vamos supor que temos que preencher um grande formulário para compor um grande JSON. Cada seção deste formulário é armazenada em um campo desse objeto (por consequência, teremos um objeto de objetos).

A mudança disto para o exemplo acima é que precisamos especificar qual é o campo que vamos salvar, então em vez de apenas usar `...prevData`, fazemos isso concatenado com o nome do campo em um vetor, como `...prevData, ["nomeCampo"]`.

<figure><img src="../../../../.gitbook/assets/form objeto dentro de objeto react.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../../.gitbook/assets/resultado form objeto em objeto.png" alt=""><figcaption></figcaption></figure>

Se a estrutura do objeto não estiver declarada previamente, o programa vai causar erro ao tentar <mark style="color:red;">atribuir em um campo inexistente</mark>. Em problemas mais reais, podemos utilizar um JSON [já montado](#user-content-fn-1)[^1] como estrutura.&#x20;

```jsx
import jsonFile from "/public/data/json_response.json";

const Form = () => {
  const [formData, setFormData] = useState(jsonFile);
  // ...
}
```

{% hint style="info" %}
Possivelmente, precisaremos saber posteriormente:

1. [Como enviar JSON no body em uma requisição HTTP](requisicoes-http.md#post).
2. [Como encontrar chaves dentro de um objeto de objetos em Javascript.](../../javascript/metodos-arrays.md#usar-para-objetos)
3. Como fazer download de arquivos.

```jsx
function downloadJsonFile() {
  // Sendo apiData um arquivo JSON ou objeto
  if (!apiData) return;

  // Prepara o objeto (mantém como JSON)
  const jsonString = JSON.stringify(apiData);
  const blob = new Blob([jsonString], { type: "application/json" });
  const url = URL.createObjectURL(blob);

  // Cria o link para o download
  const tempLink = document.createElement("a");
  tempLink.href = url;
  tempLink.download = "meuArquivo.json";
  document.body.appendChild(tempLink);
  tempLink.click();
  document.body.removeChild(tempLink);
  URL.revokeObjectURL(url);
}

<button onClick={downloadJsonFile} disabled={!apiData}>
  Baixar JSON
</button>
```
{% endhint %}

## Envio

Usando o evento `onSubmit` que fica na tag `<form>`, que [<mark style="color:blue;">chama uma função</mark>](#user-content-fn-2)[^2] para validar os dados. O submit no HTML faz recarregar a página e perder os dados, por isso, dentro dessa função podemos usar o método `preventDefault` para isso não acontecer.

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

## Checkbox

#### Valor inicialmente preenchido

Caso não haja necessidade de armazenar e atualizar estados, podemos usar a tag `defaultChecked` para um input do tipo checkbox iniciar marcado. Caso seja necessário os estados, usar `checked={condição}`.

```jsx
<input type="checkbox" name="check" onChange={handleCheckbox} defaultChecked />
```

[^1]: Dica: ele já pode conter dados definidos ali dentro, vários campos dentro de campos. Assim, na hora de manipular com o formulário, se o campo for repetido ele irá substituir aquele valor.

[^2]: Normalmente chamada de `handleSubmit`.
