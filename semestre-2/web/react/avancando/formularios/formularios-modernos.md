---
description: 'Documentação do react-hook-form: https://react-hook-form.com/form-builder'
---

# Formulários modernos

O grande problema de formulários feito sem bibliotecas ou de forma nativa é a necessidade de usar estados para criar labels controlados e **atualização de estado renderiza os componentes**, deixando pesado.

Para corrigir isso e também facilitar diversas funções, podemos usar o `react-hook-form` que:

* Salva os estados dos labels (fica persistente).
* Previne renderização em mudanças.
* Já <mark style="color:green;">guarda em objetos os dados</mark> dos nossos formulários de forma fácil.
* Inicia o label com valor pré definido se já tem de um preset.

{% hint style="warning" %}
Evita as renderizações pela mudança no formulário, contudo, esse hook não tem controle sobre o uso de useState locais (criados pelo programador). Então, mudanças de estado vindas de outras maneiras ainda podem renderizar o formulário, tomar cuidado.
{% endhint %}

## Como funciona

Essa biblioteca já prepara as devidas funções que vamos precisar usar, como a de inserir no objeto, resgatar valores, definir manualmente, etc. Resgatamos essa função dessa forma:

```jsx
import { useForm } from "react-hook-form";

const Form = () => {
  const { register, handleSubmit, setValue, getValues } = useForm();
  ...
}
```

### Atributos extra de inicialização

Podemos iniciar nosso formulário com um preset. Isso vai permitir resgatar valores do preset e na hora de preencher, só preenche os campos especificados.

```jsx
const formPreset = ...;
const { register, handleSubmit, setValue, getValues } = useForm({
  defaultValues: formPreset,
});
```

## Rascunho

refactor nova table:

importo no form e uso isso:\
const { register, handleSubmit } = useForm({\
defaultValues: formTest,\
});

passo register como contexto para os FormInput poder\
usar

do próprio register eles conseguem resgatar o valor\
default (precisa da key)

não precisa ser controlled input, ele é resistente á renderizações (não sei na verdade, troquei a aba e ele se manteve)

import { useForm } from "react-hook-form";

export default function ProppantTable() {\
const formTest = {\
Reservoir: {\
prop: {\
Name: "marcos",\
Gender: "M",\
},\
people: {\
Metric: "",\
},\
},\
Geo: 1000,\
};\
const { register, handleSubmit } = useForm({\
defaultValues: formTest,\
});\
const onSubmit = (data) => console.log(data);

return (

\
\<input defaultValue="testt" {...register("Reservoir.prop.Name")} />\
\<select {...register("Reservoir.prop.Gender")}>femalemaleother\
);\
}

***

Acontece que ele resgatou o valor, sem precisar o defaultValue. Tem que\
ser assim. Pois ao alterar a métrica, vai ter que atualizar o valor\
direto do form e já resgatar o atualizado.

Testar se isso funciona assim! funciona sim

Então na teoria eu não vou precisar passar métricas e valores default,\
somente o path para o próprio input saber de quem se trata.

WIKI:\
isso explica muito:\
const { register, handleSubmit, setValue, getValues } = useForm({\
defaultValues: formPreset,\
});

depois saber que, se estão em componentes diferentes, exige defaultMetric

onChange precisa usar o dedicado deles:\
{...register(pathMetric, {\
onChange: (e) => {\
handleMetricSelection(e); // sua função extra\
},\
})}

const allValues = getValues();\
isso pega tudo

O React Hook Form evita re-renderizações causadas por atualizações do form state — ou seja, quando você usa register, setValue, getValues, etc.. Porém, ele não tem controle sobre os seus useState hooks locais.
