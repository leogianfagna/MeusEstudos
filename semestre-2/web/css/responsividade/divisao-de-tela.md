# Divisão de tela

A divisão de telas com `width 50%` (ou o tamanho desejado) para duas classes <mark style="color:red;">não é responsivo</mark>, apesar de funcionar visualmente em telas grandes. Para uma divisão de telas funcionar, precisamos de um elemento pai que forneça o [espaçamento entre elas](#user-content-fn-1)[^1] e o flex box.

## Coração do layout com flexbox

A propriedade flex pode permitir comportamentos do tipo: especificar qual o tamanho que eu quero para o meu elemento, mas definir se ele pode encolher ou crescer conforme o tamanho da tela. Essas características vão criar o comportamento responsivo:

```css
flex: grow shrink basis;
```

* Grow (booleano): indica se pode crescer.
* Shrink (booleano): indica se pode espremer.
* Basis (número): valor da base inicial.

Essa propriedade deve ficar dentro dos elementos que definem o tamanho, ou seja, os elementos filhos do container.

Se queremos dividir a tela em dois, na teoria seria 50% de tamanho. Mas <mark style="color:orange;">devemos declarar valores menores</mark> como 48%, que isso cria a margem que utilizaremos no `gap` entre os elementos.

### Empilhar elementos

É uma propriedade muito importante pois devemos pensar em empilhar os elementos caso não há espaço para eles, pois se não eles vão ficar se espremendo. Para isso, utilizmos o `flex-wrap` no pai, que define <mark style="color:blue;">empilhar os elementos automaticamente ao faltar espaço</mark>. Por ser uma propriedade flexível, esse mesmo elemento precisa ser flex.

### Controlar o tamanho do conteúdo

Se temos um elemento de largura 50% por exemplo, ao adicionar margens e espaçamentos (paddings) teremos um elemento final maior que isso. Portanto, se tivermos dois elementos desse um do lado do outro, isso <mark style="color:red;">vai criar uma barra de rolagem</mark> pois ultrapassamos os 100% (contando que incluímos as margens).

A propriedade `box-sizing` permite definirmos para `border-box`, que <mark style="color:blue;">garante que</mark> [<mark style="color:blue;">tudo</mark>](#user-content-fn-2)[^2] <mark style="color:blue;">estará dentro do tamanho declarado</mark>. Isso é, podemos adicionar margens e espaçamentos que esses 50% vai conter tudo isso, e não ultrapassará esse valor.

{% hint style="success" %}
É comum incluir isso como regra global no CSS:

```css
* {
  box-sizing: border-box;
}
```
{% endhint %}

### Resultado final

Veja que o tamanho final para duas telas foi definido em 48%, e então colocamos um gap de 2%. O valor do gap não precisa preencher todo o espaço faltante, tanto até que dois componentes de 48% resultam em 96%, faltando 4% e não 2%. O valor dois foi colocado apenas como melhor estética.

```css
.tab-container {
    display: flex;
    flex-wrap: wrap;
    gap: 2%;
}

/* Criado para ocupar até ~50% com flexibilidade */
.lado-esquerdo,
.lado-direito {
  flex: 1 1 48%;     
  box-sizing: border-box;
}
```

### Mais de uma divisão

Se quisermos a tela dividida mais de uma vez, por exemplo em 3 partes iguais, podemos alterar os 48% para 30%. Quando faltar espaço para uma tela, automaticamente irá empilhar apenas aquela que faltou espaço em baixo das outras.

[^1]: Usando gap. Colocar o espaçamento dentro de um dos lados, com margin-right por exemplo, quebra o comportamento responsivo.

[^2]: Margens, espaçamentos, bordas, etc.
