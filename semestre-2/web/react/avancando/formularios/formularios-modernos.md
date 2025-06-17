---
description: 'Documentação do react-hook-form: https://react-hook-form.com/form-builder'
---

# Formulários modernos

O grande problema de formulários feito sem bibliotecas ou de forma nativa é a necessidade de usar estados para criar labels controlados e **atualização de estado renderiza os componentes**, deixando pesado.

Para corrigir isso e também facilitar diversas funções, podemos usar o `react-hook-form` que:

* Salva os estados dos labels (fica persistente) e evita a necessidade de <mark style="color:blue;">controlled inputs</mark>.
* Previne renderização em mudanças.
* Já <mark style="color:green;">guarda em objetos os dados</mark> dos nossos formulários de forma fácil.
* Inicia o label com valor pré definido se já tem de um preset.

{% hint style="warning" %}
Evita as renderizações pela mudança no formulário, contudo, esse hook não tem controle sobre o uso de useState locais (criados pelo programador). Então, mudanças de estado vindas de outras maneiras ainda podem renderizar o formulário, tomar cuidado.
{% endhint %}

```bash
npm install react-hook-form
```

```jsx
import { useForm } from "react-hook-form";
```

## Funções para uso

Para <mark style="color:blue;">iniciar</mark>, a biblioteca já prepara as devidas funções que vamos precisar usar, como a de inserir no objeto, resgatar valores, definir manualmente, etc. Resgatamos essa função dessa forma, no componente principal que controla o formulário:

```jsx
const Form = () => {
  const { register, handleSubmit, setValue, getValues } = useForm();
  ...
}
```

Se outros componentes também fazem formulário, essas funções devem ser transferidas (via prop ou contexto) para os mesmos. Contudo, <mark style="color:red;">componentes que não sejam o principal não conseguem resgatar o valor default</mark> para o label caso exista, exigindo portanto usar uma tag `defaultValue`.

{% hint style="info" %}
### Atributos extra de inicialização

Podemos iniciar nosso formulário com um preset. Isso vai permitir resgatar valores do preset e na hora de preencher, só preenche os campos especificados. Sua exigência é o caminho onde ele será salvo no objeto.

```jsx
const formPreset = ...;
const { register, handleSubmit, setValue, getValues } = useForm({
  defaultValues: formPreset,
});
```
{% endhint %}

### Register

Lida com a inserção automática no formulário. Só de chamar o método register nas tags, ele imputa o dado no objeto do form enquanto vai sendo alterado no input. Do próprio register ele consegue resgatar o valor que está salvo na key especificada, por isso evita controlled inputs e [necessidade de defaultValue](#user-content-fn-1)[^1].

```jsx
<label>
    <span>Nome completo</span>
    <input {...register("user.name")}></input>
</label>
```

#### Eventos dedicados e opções

Quando existe o register, por conta do comportamento de não renderização e outros, eventos devem ser utilizados os dedicados à biblioteca. Colocar `onChange` na tag por exemplo, não vai funcionar chamadas de funções.

Todas as opções e funções extras são chamadas como parâmetros de um objeto do `register`, algumas delas são:&#x20;

* Definir valor inserido como um número.
* Ativar funções quando alterar.

```jsx
<input
  type={"number"}
  defaultValue={presetValue}
  className={"data-input"}
  
  {...register("user.name", {
    valueAsNumber: true,
    onChange: () => {
      labelRef.current?.classList.remove("error-label");
    },
  })}
></input>
```

### SetValue

Define um valor na chave especificada. Pode ser usada na necessidade de fazer alterações manuais, pois lembrando que o register já altera automaticamente. Por exemplo, ao alterar uma opção, automaticamente define um valor na outra.

Essa função felizmente <mark style="color:green;">atualiza o que está sendo exibido no input</mark>. Ou seja, ao usar setValue para um novo valor, esse valor é imediatamente atualizado para a tela do usuário.

```jsx
const handleMetricSelection = (e) => {
  const newMetric = e.target.value;
  const convertedValue = convertValue(newMetric);
    
  setValue("unit.metric", convertedValue);
};
```

### GetValues

Função para resgatar os valores inseridos no formulário ou de um campo específico. Aceita como parâmetro o caminho no objeto, mas se não informado, resgata tudo em um grande objeto.

```jsx
const formData = getValues();
const currentValue = getValues("user.age");
```

## Tabelas

Para a criação de tabelas dinâmicas, acrescenta o contexto `useFieldArray` dessa mesma biblioteca. Ela acrescenta funções de tabela necessárias para controlar basicamente tudo.

{% hint style="info" %}
## Entendendo o Controller

O Controller é um componente utilitário fornecido pelo react-hook-form para registrar campos de formulário que <mark style="color:orange;">não podem ser controlados diretamente</mark> com o `register`, que são eles elementos controlados por outro elemento que não pertence ao react ou react-hook-form, por exemplo uma tabela virtualizada[^2] ou o próprio useFieldArray[^3].

O control vai servir como comunicador para manter a ligação dos elementos quando exigido.&#x20;
{% endhint %}

### Ligação entre os fields e o formulário principal

Precisa resgatar o control do useForm para fazer a ligação com o useFieldArray. Neste caso, usa valores default para iniciar a tabela. Caso não existisse, os elementos da tabela iriam exigir a tab `defaultValue`.

No useFiledArray, o campo name condiz com qual campo estamos trabalhando do nosso formulário. Ele precisa ser o mesmo para conseguir fazer as alterações de forma automática.

```jsx
const { control, register, getValues, setFocus } = useForm({
  defaultValues: {
    AdvancedTable: {
      rows: [emptyLine] // Linhas inseridas aqui
    },
  },
});

const { fields, append, prepend, remove, swap, move, insert } = useFieldArray(
  {
    control,
    name: "Advanced.Correlatos.rows",
  }
);
```

### Inserção do formulário

O elemento `field` que temos no fieldArray consegue resgatar todas as linhas registradas. Por isso, iteramos elas para mostrar todas as existentes. O register precisa receber o local exato de onde o dado se encontra (mesmo esquema com o formulário normal), mas aqui, ele será identificado com um index para saber de qual linha se trata.

```jsx
<form>
  <ul>
    {fields.map((item, index) => (
      <li key={item.id}>
        <input {...register(`AdvancedTable.rows.${index}.coluna1`)}/>
        <input {...register(`AdvancedTable.rows.${index}.coluna2`)}/>
        <input {...register(`AdvancedTable.rows.${index}.coluna3`)}/>
      </li>
    ))}
  </ul>
</form>
```

### Inserção e remoção de linhas

Ver a [documentação do useFieldArray](https://react-hook-form.com/docs/usefieldarray) para saber todos os métodos, eles são poderosos. Mas para fazer a inserção com ENTER ou a remoção com BACKSPACE, basta incluir um evento dentro do input para ficar escutando.

Basicamente, vai usar as funções remove e insert que são <mark style="color:blue;">baseada em posições</mark>. As posições podem ser obtidas pois estão sendo iteradas com map (elas são o index). Usa o evento para descobrir qual tecla usou.

{% hint style="warning" %}
A inserção de linhas precisa conter o conteúdo da nova linha e obviamente precisa ser a mesma estrutura da tabela (não exige id, que é controlado pelo próprio hook). Foi usado uma variável `emptyLine`, que é um objeto com cada campo vazio `""`.
{% endhint %}

```jsx
// Index veio do map, então sabemos qual é a posição da linha em questão no
// vetor de linhas do formulário
const handleKeyDown = (e, index) => {
  if (e.key === "Backspace") {
    if (!e.target.value && fields.length > 1) {
      remove(index);
      
      // Usar setFocus para focar na linha acima e melhorar a experiência
      // Como o índice acabou de mudar com remove, o setTimeout "ludibria" e
      // passa a conseguir acessar a linha correta
      setTimeout(() => {
        setFocus(`Advanced.Correlatos.rows.${index - 1}.well`);
      }, 0);
    }
  }

  if (e.key === "Enter") {
    e.preventDefault();
    insert(index + 1, emptyLine);
  }
};

{fields.map((item, index) => (
  <input
      onKeyDown={(e) => handleKeyDown(e, index)}
      {...register(`Advanced.Correlatos.rows.${index}.${key}`)}
  />
))}
```

### Tabela virtualizada

Quando temos uma tabela virtualizada as coisas mudam, pois as referências são perdidas toda vez que a tabela rodar. Por conta disso, o input puro não pode ser mais usado pois o register não pode ser mais controlado e assim entra o `Controller` (explicado no começo da seção).

Ele já tem a função register puramente dentro dele, por isso não vemos esse método dentro. Dentro do controle, teremos:

* render: Especificamos o que será renderizado, podemos colocar um componente ou inserir os elementos direto. Esse exemplo é com um input direto e algumas classes.
* name: Campo em que essa linha pertence. Usa rowIndex (número) e columnKey (string) para identificar qual a linha e qual é o campo dentro do objeto.
* control: Passa o objeto control para fazer a ligação.

{% hint style="info" %}
## Linha de uma tabela

A linha de uma tabela é representada com um objeto:

![](../../../../../.gitbook/assets/image.png)

Por isso, no name é  necessário especificar o objeto a ser modificado (usamos columnKey, que resgata o nome correto através de um objeto de tradução):



```jsx
// Variável global
const colIndexTranslater = {
  0: "well",
  1: "skin",
  2: "perm",
  3: "year",
};

// E na renderização do componente
{({ columnIndex, rowIndex, style }) => {
  const columnKey = colIndexTranslater[columnIndex];
```
{% endhint %}

```jsx
<Controller
  render={({ field }) => (
    <input
      {...field}
      onKeyDown={(e) =>
        handleKeyDown(e, rowIndex, columnKey)
      }
      className="table-value-input"
      type="text"
    />
  )}
  name={`Advanced.Correlatos.rows.${rowIndex}.${columnKey}`}
  control={control}
/>
```

[^1]: Apenas nos casos de componentes separados, como dito acima.

[^2]: É controlado pelo virtualize. O grid (criador da tabela virtual), quebra a conexão direta do register pois fica recriando, exigindo um controle mais complexo.

[^3]: Salva objetos internamente, em um estado chamado de oculto.
