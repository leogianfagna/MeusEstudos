# Imagens

As imagens podem estar em qualquer lugar, tanto no `src` ou na pasta `public`, independente, vale a pena deixar no diretório `assets`.

O uso de imagens no JSX pode ser feito do jeito tradicional com a tag `<img>`. Para usar uma imagem, podemos:

1. Importar ela como uma variável e usá-la com a tag `href`.
2. Especificar o caminho específico dela com a tag `src`.

```jsx
import Logo from './assets/react.svg'

function App() {
  const imageName = "oceano";
  
  return (
    <>
      // Modo 1: Importamos na primeira linha a variável e usamos ela aqui
      <img href={Logo} alt="Logo React" />
      
      // Modo 2: Especificamos o caminho que está guardada, pode ser dinâmico, usamos
      // a variável imageName declarada na quarta linha
      <img src={"/assets/" + imageName + ".png"} alt={imageName} />
    </>
  );
}
```
