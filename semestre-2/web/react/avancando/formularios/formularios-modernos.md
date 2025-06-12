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

[^1]: Apenas nos casos de componentes separados, como dito acima.
