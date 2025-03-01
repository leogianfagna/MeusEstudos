# Context API

Ajuda a compartilhar variáveis/estados entre <mark style="color:orange;">vários componentes</mark>. Quando estamos falando em níveis hierarquicos simples, utilizamos o [State Lift](state-lift.md), mas o **Context API** serve para resolver o problema quando temos diversos níveis de componentes e compartilhamento entre todos eles.

**Normalmente**, o Context acaba encapsulando e englobando todos os componentes, criando portanto <mark style="color:green;">variáveis globais</mark>.

{% hint style="success" %}
Convenção: Deixar na pasta chamada `/context` dentro de `/src`.
{% endhint %}

## Etapas de implementação

* **Contexto**: Quem altera os valores.
* **Provider**: Quem providencia esse contexto.
* **Encapsular**: Apenas componentes filhos podem usar o contexto.

### Componente provedor do contexto

Utiliza o hook `createContext` e precisa **exportar** tanto o contexto e o provider, visto acima.

```jsx
import { createContext, useState } from "react";

const MapContext = createContext();

const MapContextProvider = ({ children }) => {
    const [map, setMap] = useState("null");

    return (
        <MapContext.Provider value={{ map, setMap }}>
            {children}
        </MapContext.Provider>
    );
};

export { MapContext, MapContextProvider };
```

### Componentes que consomem/alteram

Utiliza o hook `useContext` e precisa importar também o contexto criado por nós.

```javascript
import { useContext } from "react"
import { MapContext } from "../context/MapContext"
```

Trazer o contexto para o componente. Os dados trazidos chegam em um objeto, portanto utilizamos:

```jsx
const { map, setMap } = useContext(MapContext);
```

E pronto, já pode estar sendo utilizado ao longo desse componente. Veja o exemplo completo:

<figure><img src="../../../../.gitbook/assets/context api componente que recebe.png" alt=""><figcaption></figcaption></figure>

### Hierarquia

Todos os componentes que utilizaram deste contexto, <mark style="color:orange;">necessitam ser filhos do Provider</mark> (isso se chama <mark style="color:purple;">encapsular</mark> o contexto). Então, ao utilizar os componentes, precisa envolvê-los dentro do provider exportado criado por nós.

#### Envolver cada componente manualmente

Se é um provider para contextos utilizados em apenas alguns componentes, podemos envolvê-los dentro do `App.jsx`. Isto é:

```jsx
// App.jsx
import { MapContextProvider } from "./context/MapContext";
import ContextTest from "./components/ContextTest";

return (
    // Envolver nossos componentes dentro do provider
    <MapContextProvider>
        <ComponenteUm />
        <ComponenteDois />
        <ComponenteTres />
    </MapContextProvider>
)
```

#### Envolver a aplicação inteira

Existe uma outra alternativa de fazer esse encapsulamento, que é <mark style="color:blue;">envolver</mark> <mark style="color:blue;"></mark><mark style="color:blue;">**toda a aplicação**</mark> <mark style="color:blue;"></mark><mark style="color:blue;">(App.jsx) dentro do contexto</mark>. Isso quer dizer que toda a aplicação vai ter acesso a esses contextos. Isso é vantajoso quando o objetivo é que esse contexto seja de fato uma <mark style="color:purple;">variável global</mark> acessada de qualquer lugar.

Para isso, navegamos até `main.jsx` que é onde o `<App />` é utilizado e envolvemos ele dentro do nosso provedor.

```jsx
// main.jsx
import { MapContextProvider } from "./context/MapContext.jsx";

createRoot(document.getElementById("root")).render(
  <StrictMode>
    // Envolver todo o App dentro do Provider
    <MapContextProvider>
      <App />
    </MapContextProvider>
  </StrictMode>
);
```
