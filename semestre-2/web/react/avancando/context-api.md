# Context API

Ajuda a compartilhar variáveis/estados entre <mark style="color:orange;">vários componentes</mark>. Quando estamos falando em níveis hierarquicos simples, utilizamos o [State Lift](state-lift.md), mas o **Context API** serve para resolver o problema quando temos **diversos níveis** de componentes e compartilhamento entre todos eles.

**Normalmente**, o Context acaba encapsulando e englobando todos os componentes, criando portanto <mark style="color:green;">variáveis globais</mark>.

{% hint style="success" %}
Convenção: Deixar na pasta chamada `/context` dentro de `/src`.
{% endhint %}

## Etapas de implementação

* **Contexto**: Quem altera os valores.
* **Provider**: Quem providencia esse contexto.
* **Encapsular**: Apenas componentes filhos podem usar o contexto.

### Componente provedor do contexto

É necessário <mark style="color:blue;">criar um componente a parte</mark>, que sua única funcionalidade será envolver os demais componentes dentro de um contexto. Utiliza o hook `createContext` e precisa **exportar** tanto o contexto e o provider, visto acima. Vamos chamar de `MapContext`.

```jsx
import { createContext, useContext, useState } from 'react'

export const MapContext = createContext()

export function useMapContext() {
  return useContext(MapContext)
}
```

### Componente que irá envolvê-lo

A ideia é, um componente que tem vários filhos, compartilhar contextos entre todos eles. Então, neste caso é interessante fazer com que esse componente pai já seja o provedor do contexto.

Para isso, basta envolver tudo o que está sendo renderizado (os componentes filhos e afins) dentro do objeto `Provider` criado naquele componente a parte no exemplo acima. Isso quer dizer que nosso pai terá a responsabilidade de ser o provedor.

```jsx
import { MapContext } from "./MapContext";

const Form = () => {
  const [formData, setFormData] = useState([]);
  
  const handleChangeForm = (event) => {
    ...
  };

  return (
    <FormContext.Provider value={{ formData, setFormData, handleChangeForm }}>
      <h1>Formulário</h1>
      <PaginaUm />
      <PaginaDois />
    </FormContext.Provider>
  );
};

export default Form;
```

Veja então que esse componente tem suas funcionalidades e também exporta o contexto para seus filhos, que no caso são `PaginaUm` e `PaginaDois`. Os contextos exportados são esses passados em `value`: formData, setFormData e handleChangeForm (duas funções e uma variável). Se nós quisermos passar mais contextos para serem utilizados, é só incluir mais!

É muito importante saber que, os <mark style="color:green;">filhos dos filhos também podem usar esse contexto</mark>. Isto é, se `PaginaUm` chama um componente dentro dele (supondo `FilhoPaginaUm`), esse componente também pode importar e usar esse contexto livremente.

Não é necessário nenhum código adicional para isso acontecer. Então se quisermos usar o contexto apenas em `FilhoPaginaUm` mas não em seu pai, o `PaginaUm`, é só importar os contextos apenas no `FilhoPaginaUm` e tudo funcionará tranquilamente. O seu <mark style="color:blue;">pai não tem a responsabilidade de passar nada para o filho</mark>.

### Componentes que consomem/alteram

Esse são os componentes (quaisquer componentes) que querem usar os contextos exportados. Para isso, utiliza o hook `useContext` e precisa importar também o contexto criado por nós (precisamos especificar qual importar).

```javascript
import { useContext } from "react"
import { useMapContext } from "../FormContext"; // Nome da função que criamos e exportamos no primeiro exemplo
```

Depois trazer o contexto para o componente. Os dados trazidos chegam em um objeto, portanto utilizamos:

```jsx
const { formData, handleChangeForm } = useFormContext();
```

E pronto, já pode estar sendo utilizado ao longo desse componente, como por exemplo, chamar as funções ou imprimir variáveis. Os valores são dinamicamente compartilhados em todos os componentes.

Existem <mark style="color:orange;">várias formas de criar o context</mark>, por conta disso, pode haver algumas diferenças de exemplo para exemplo. Veja o exemplo completo:

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
