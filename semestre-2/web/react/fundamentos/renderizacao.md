# Renderização

Precisamos saber os conceitos de renderização do React para que possamos criar algo <mark style="color:green;">otimizado</mark>. Quando o React entra na sua fase de render, isto é, renderiza o seu componente, ele executa a função do componente e tudo o que está no corpo dela imediatamente.

```jsx
const MyForm = () => {
  // Variáveis
  const [selectedUnit, setSelectedUnit] = useState(unit);
  const result = myFunction();

  // Funções
  function myFunction() {
    ...
  }

  // Eventos
  const handleSomething = (event) => {
    ...
  };

  return (
    < ... >
  );
};

export default MyForm;
```

Todo esse código acima é o que está dentro do corpo. Veja que a função `myFunction` também é renderizada imediatamente, pois ela é chamada ao ser atribuída a variável "result". Mas a função `handleSomething` não é renderizada, pois não está sendo chamada diretamente.

Enfim, só depois de renderizar todo o corpo que o React atualiza o DOM e dispara useEffect, useLayoutEffect, etc.

## Otimização e prevenção de loop

Chamadas de fetch data ou setState <mark style="color:red;">não devem estar diretamente chamadas no corpo</mark> porque geram **loop infinito**.&#x20;Podemos criar quantas funções queremos, mas é recomendado que elas não sejam chamadas durante a renderização, como é feito com o `myFunction`.

<mark style="color:green;">Para resolver isso</mark>, é uma boa prática deixar essas funções ou setStates dentro do **useEffect** ou funções de **handle**, que são chamadas algumas vezes com interações HTML.

### Exemplo real

Esse exemplo mostra códigos dentro de um corpo de um componente. Veja abaixo uma função que é chamada no corpo e dentro dela usa um useState:

```jsx
const [metricCategory, setMetricCategory] = useState(null);
const metricsListFiltered = getMetricsFromCategory(metrics, unit); // Chamar função

function getMetricsFromCategory(allMetrics, metricUnit) {
  for (let key in allMetrics) {
    let metricsList = allMetrics[key];

    if (metricsList.find((m) => m === metricUnit)) {
      setMetricCategory(key); // useState dentro da função
      return metricsList;
    }
  }
}
```

Esse exemplo não roda pois cria um loop infinito. Para corrigir tal problema, fazemos:

* metricsListFiltered não precisa ficar se atualizando a cada renderização e precisa assumir apenas um resultado somente. Portanto, movemos essa chamada para um useEffect. Para isso funcionar, deixamos ele declarado como um useState.
* Para remover a necessidade do setMetricCategory dentro de uma função, fizemos que essa função retorne um objeto e assim resgatamos qual parte do objeto queremos no código.

```jsx
const [selectedUnit, setSelectedUnit] = useState(unit);
const [metricsFiltered, setMetrics] = useState(null);

function getMetricsAndCategory(allMetrics, metricUnit) {
  for (let key in allMetrics) {
    let metricsList = allMetrics[key];

    if (metricsList.find((m) => m === metricUnit)) {
      return {
        list: metricsList,
        category: key,
      };
    }
  }
}

useEffect(() => {
  setMetrics(getMetricsAndCategory(metrics, unit));
}, []);
```
