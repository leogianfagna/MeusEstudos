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
