# Renderização de lista

Renderizar listas é algo bem comum de ser feito, tendo em vista que as listas podem representar um grande conjunto de dados, como por exemplo, algo vindo do banco de dados da aplicação.

* Feitos com dados do tipo **array de objetos**.
* Utiliza-se o método `map`, ensinado [aqui](../../javascript/metodos-arrays.md#map).
* É possível inserir JSX em cada iteração, o que permite muito.

#### Detalhe importante com map

Esse método utiliza-se um corpo com chaves. Contudo, quando estamos retornando um objeto, utilizamos parênteses e não chaves. No JSX (quando estamos no return do React), isso faz retornar um objeto, portanto, temos essa alteração:

```jsx
const mapPadrao = itens.map((item) => { // Aqui é chaves
    item.valor *= 0.5;or
    return item;
});

const mapComObjeto = itens.map((item) => ( // Aqui é parênteses
    item.valor *= 0.5;
    return item;
));
```

## Como renderizar

A ideia vai consiste em criar uma tag `<ul>` para cada item no array, usando o método `map()` para isso, que dentro de cada iteração vai estar uma HTML com essa tag. Chamamos isso de <mark style="color:blue;">inserção de dados dinâmicos</mark>.

Além disso, é obrigatório combinar isso com a propriedade `key`, que quer dizer que cada dado/componente precisa de uma [<mark style="color:red;">chave única</mark>](#user-content-fn-1)[^1], para ser encontrado no HTML de forma única e fácil.

```jsx
import { useState } from "react";

const ListRender = () => {
  
  // Repare a criação na lista com o hook useState, mesmo
  // sem necessidade neste momento
  const [users] = useState([
    { id: "A1", username: "Amanda" },
    { id: "A2", username: "Marcus" },
    { id: "A3", username: "Yasmin" },
  ]);

  return (
    <div>
      <p>Minha lista:</p>
      <ul>
        {users.map((usuario) => (
          <li key={usuario.id}>{usuario.username}</li>
        ))}
      </ul>
    </div>
  );
};

export default ListRender;
```

## Estado anterior da lista

Como o `useState` renderiza a página novamente quando o estado muda, ao manipular uma lista (por exemplo, ao remover um elemento), precisamos criar uma nova versão da lista, usando o estado anterior, para atualizar e renderizá-la novamente. Para isso, usamos o [estado anterior do elemento](hooks.md#estado-anterior) visto em hooks.

O estado em React é imutável e por isso sempre precisamos de uma nova lista. Isso é muito utilizado com o método [filter](../../javascript/metodos-arrays.md#filter).

```jsx
import { useState } from "react";

const Lista = () => {
  const [itens, setItens] = useState(["Item 1", "Item 2", "Item 3"]);

  const removerItem = (itemParaRemover) => {
    // Usando o estado anterior para criar uma nova lista
    setItens((prevItens) =>
      // Método filter que vai excluir "itemParaRemover" passado no parâmetro
      prevItens.filter((item) => item !== itemParaRemover)
    );
  };

  return (
    <div>
      <h3>Minha Lista:</h3>
      <ul>
        {/* Javascript que adiciona todos os elementos da lista, exemplo acima */}
        {itens.map((item, index) => (
          <li key={index}>
            {/* Usa função de seta para não executar função ao carregar página */}
            <button onClick={() => removerItem(item)}>Remover item {item}</button>
          </li>
        ))}
      </ul>
    </div>
  );
};

export default Lista;
```

[^1]: É muito importante que seja de fato uma chave única. Veja no exemplo que esse ID é única e não é confundido com outro elemento.



    Algumas soluções propõe o uso do index, como users.map((usuario, index) ⇒ .., mas isso traria problemas pois index não será único para cada tipo de elemento.
