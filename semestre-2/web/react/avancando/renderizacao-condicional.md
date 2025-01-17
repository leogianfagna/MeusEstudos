# Renderização condicional

Podemos renderizar elementos HTML baseado em condições.

## Forma simplificada (exibir algo ou nada)

O React possui o operador `&&` que simplifica uma condição `if`. Neste caso, não existiria o else pois ele vai exibir baseado em uma condição ou não exibirá nada. Sua simplificação fica desta forma:

```jsx
const [x] = useState(true);
const [y] = useState(15);

{x && <p>X é igual a true</p>}
{(y > 5 && y < 20) && <p>Está no intervalo</p>}

// Traduzindo para linguagem Javascript usual
if (x)
    return <p>Exibir<p/>;

if (y > 10 && y < 20)
    return <p>Está no intervalo</p>;
```

## Forma com operador ternário

Caso queremos um `else`, podemos usar o operador ternário. Assim como o caso de cima, casa resultante pode imprimir um elemento HTML. Podemos imprimir grandes elementos, veja:

```javascript
{nome === "João" ? ( elementos se verdade ) : ( elementos se não ) }
```

Esses parênteses podem ser quebrados e exibir grandes estruturas dentro deles. Veja um exemplo final:

```jsx
import { useState } from "react";

const ConditionalRender = () => {
  const [x] = useState("João");

  return (
    <div>
      <h1>Isso será exibido?</h1>
      {x === "Messias" ? (
        <div>
          <h1>Identificador de nome</h1>
          <p>O nome condiz!</p>
        </div>
      ) : (
        <div>
          <h1>Identificador de nome</h1>
          <p>O nome não condiz!</p>
        </div>
      )}
    </div>
  );
};

export default ConditionalRender;
```

Em vez de inserir as grandes estruturas no operador ternário, podemos criar componentes e exibir os componentes no lugar dessas estruturas, que daria no mesmo resultado porém mais organizado. Esses componentes podem ser criados no próprio arquivo, porém, fora da função do componente principal (acima dele). A inclusão no HTML ficaria:

```jsx
<div>
  {x === "Messias" ? <NomeCondiz /> : <NomeNaoCondiz />}
</div>
```

## Renderizar função

Também podemos criar todo HTML em uma grande função, podendo haver muitas outras condições para isso e fazer algo mais complexo. Nisso, importamos a função para o return do componente, desta forma:

```jsx
import { useState } from "react";

const ConditionalRenderTernario = () => {
  const [cargo] = useState("Gerente");

  const renderizarResultado = () => {
    if (cargo === "Gerente") {
      return (
        <div>
          <h1>Bem vindo Gerente</h1>
          <button>Acessar página administrativa</button>
        </div>
      );
    }

    if (cargo === "Funcionário") {
      return (
        <div>
          <h1>Bem vindo Funcionário</h1>
          <button>Acessar página logada</button>
        </div>
      );
    } else {
      return (
        <div>
          <h1>Bem vindo!</h1>
          <p>Nenhum cargo foi encontrado.</p>
        </div>
      );
    }
  };

  return <div>{renderizarResultado()}</div>;
};

export default ConditionalRenderTernario;
```
