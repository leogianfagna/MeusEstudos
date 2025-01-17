# Children prop

Serve para <mark style="color:blue;">abraçar um conteúdo JSX (elementos HTML) com um componente</mark>. Tem como objetivo usar o componente e inserir novas tags dentro dele na estrutura que foi utilizado, exemplo:

```jsx
<div>
  {/* Uso comum */}
  <Container/>
  
  {/* Children prop */}
  <Container>
    <p>"Este é um conteúdo extra"</p>
  </Container>
</div>
```

Para que isso funcione, o componente precisa ser [desestruturado ](#user-content-fn-1)[^1]para receber uma propriedade especial.

```jsx
const Container = ({children}) => {
  return (
    <div>
        {children}
    </div>
  )
}
```

[^1]: Destructing visto [aqui](../../../javascript/destructuring.md).
