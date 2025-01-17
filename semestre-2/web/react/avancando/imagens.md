# Imagens

As imagens podem estar na pasta `public` ou na `assets`. O uso de imagens no JSX pode ser feito do jeito tradicional com a tag \<img> ou a imagem pode ser importada como se fosse um arquivo, fazendo com que deixa o código mais limpo e mais fácil de manutenção.

```jsx
import Logo from './assets/react.svg'

function App() {
  return (
    <>
    <div>
      <img src="vite.svg" alt="Logo Vite"></img>
      <img src={Logo} alt="Logo React"></img>
    </div>
    </>
  );
}
```
