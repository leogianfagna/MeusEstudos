# State lift

**P**rática para compartilhar ou sincronizar o estado entre componentes irmãos ou descendentes. Fazemos isso movendo o estado para o componente mais próximo comum a todos que precisam acessar ou modificar esse estado. Em outras palavras, "levantamos" o estado para o **pai** de todos os componentes que precisam dele.

Poderíamos por exemplo dentro de um componente usar e manipular estado de elementos. Mas caso esse estado precise ser acessado por outros componentes, precisamos usar o state lift. Para que isso funcione:

* Estado está sendo gerenciado pelo componente pai. Isto é, uma variável que recebe `useState`.
* Uma forma de alterar o estado também no componente pai, como `setState`.
* Um componente que consome esse estado, via props.
* Um componente que altera o estado, recebendo o `setState` via props.

<figure><img src="../../../../.gitbook/assets/state lift.png" alt=""><figcaption></figcaption></figure>

## Aplicação

Componente pai \<App /> que vai ter o estado e um método para alterar esse estado.

```jsx
function App() {
  const [cobranca, setCobranca] = useState(0);

  const handleCobranca = (valor) => {
    setCobranca(valor);
  }

  return (
    <div>
      <Cobranca valor={cobranca}/>
      <NovaCobranca handleCobranca={handleCobranca}/>
    </div>
  );
}
```

Elemento filho que vai exibir o estado, passado por props como `valor`.

```jsx
const Cobranca = ({valor}) => {
  return (
    <div>
        <p>Valor da cobrança: {valor}</p>
    </div>
  );
}
```

Elemento filho que gerencia/altera o estado usando o método criado pelo pai `handleCobranca`, que dentro desse método tem um `setCobranca` (proveniente do useState) para alterar o valor.

```jsx
const NovaCobranca = ({handleCobranca}) => {
  return (
    <div>
      <button onClick={() => handleCobranca(50)}>Definir cobrança em $50</button>
      <button onClick={() => handleCobranca(200)}>Definir cobrança em $200</button>
      <button onClick={() => handleCobranca(1000)}>Definir cobrança em $1k</button>
    </div>
  );
}
```

## Explicando o lifting

No componente NovaCobranca, ele altera o estado através da função `handleCobranca` que é um método do pai. o estado em si **reside no pai**, enquanto os componentes filhos recebem funções setters. Isso quer dizer que quando um componente filho chama essa função "setter", ele **modifica diretamente o estado que está no pai**.

Por isso que um componente filho consegue alterar um estado e o componente pai já tem esse estado alterado.
