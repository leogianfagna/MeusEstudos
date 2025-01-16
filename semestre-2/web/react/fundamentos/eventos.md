# Eventos

Em React, colocamos o <mark style="color:blue;">evento no próprio JSX</mark> (que é o HTML), fazendo com que já fique entendido que elemento se quer usar para aquele evento.

```jsx
<button onClick={handleMyEvent}>Clique aqui.</button>
```

## Detalhes

As funções que lidam com os eventos geralmente tem a nomenclatura `handleAlgumaCoisa`. Elas são declaradas como [arrow functions](../../javascript/arrow-function.md) e [recebem um argumento](#user-content-fn-1)[^1] chamado `event`, por convenção colocamos apenas como `e`.

Como dito acima, os eventos são chamados no elemento. Nele, <mark style="color:orange;">não usamos o abre e fecha parênteses</mark> pois isso faria com que o evento disparasse quando o HTML carregasse. Os eventos são declarados pelo nome do evento que executa a função que vai lidar com ele, entre chaves.

```jsx
const Events = () => {
  
  const handleMyEvent = (e) => {
    console.log(e);
    console.log("Ativou o evento");
  };

  return (
    <div>
      <div>
        // Evento especificado para esse botão
        <button onClick={handleMyEvent}>Clique aqui.</button>
      </div>
    </div>
  );
};

export default Events;
```

## Funções nos eventos

Vimos acima o exemplo do evento que executa uma simples função `handleMyEvent()`. Essas funções podem ser criadas na própria tag e não precisa necessariamente serem declaradas acima:

```jsx
<button onClick={() => console.log("Clicou")}>Exemplo linha única</button>

<button onClick={(e) => {
  if (e != null) {
      console.log("Existe informações aqui!")
  }
}}>Outro botão</button>
```

Isso é apenas uma boa prática quando estamos falando de uma função de uma <mark style="color:blue;">única linha</mark>, como é o primeiro exemplo, que são quando as arrow functions não possuem corpo.

## Funções de renderização

São funções que retornam JSX. Isso é útil para renderizar elementos HTML que aparecem apenas com determinadas condições, em outras palavras, dados dinâmicos.

```jsx
const Events = () => {

  // Declaramos a função. Escolhemos receber um parâmetro "x"
  const conditionRender = (x) => {
    if (x) {
      return <h1>Renderizar isso se X existir</h1>;
    } else {
      return <h1>X não existe</h1>;
    }
  };

  return (
    <div>
        // Queremos que renderize ao carregar a página, por isso usamos ()
        {conditionRender(true)}
        {conditionRender(false)}
    </div>
  );
};

export default Events;
```

[^1]: Acesso a um elemento especial.
