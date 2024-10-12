# Espaçamento

**Espaçamento fixo em pixels** não é a melhor escolha para responsividade, pois pode causar problemas de layout em dispositivos móveis ou diferentes dimensões, isso porque definir em pixels vai fazer com que ele tenha aquele espaçamento independente da tela.

Portanto, vamos ver três tipos de espaçamentos, responsivos e não, para saber usar cada um.

## Espaçamento entre elementos

Vamos supor a seguinte situação em que queremos fazer um espaçamento vertical entre os elementos `button` deste site:

<figure><img src="../../../.gitbook/assets/espaçamento zero.png" alt=""><figcaption></figcaption></figure>

O código atual dele é este:

```html
<h4 class="page-title">CATEGORIAS</h1>
<div style="display: flex; flex-direction: column;">
  <button type="submit" class="card-submit-button">60KG</button>
  <button type="submit" class="card-submit-button">70KG</button>
  <button type="submit" class="card-submit-button">80KG</button>
  <button type="submit" class="card-submit-button">90KG</button>
  <button type="submit" class="card-submit-button">100KG</button>
</div>
```

### Não responsivo - tamanho fixo

Para isso, temos duas formas:

1. Setar cada elemento com um `margin-bottom` com uma quantia de pixel.
2. Setar o estilo `gap` na div que guarda todos esses elementos.

O `margin-bottom` vai setar uma distância do elemento de cima, fazendo com que podemos criar esse espaçamento de forma fixa e definida para cada elemento. O `gap` vai definir a distância de cada um, já que estamos usando um flex-direction de coluna (ele só funciona com flex-box), ele vai entender que é para aplicar esse espaçamento em cima e em baixo, criando o espaçamento desejado. O resultado, de ambos os jeitos ficaria assim:

```html
<!-- Com margin-top -->
<h4 class="page-title">CATEGORIAS</h1>
<div style="display: flex; flex-direction: column;">
  <!-- Margin para cada elemento -->
  <button type="submit" class="card-submit-button" style="margin-bottom: 10px;">60KG</button>
  <button type="submit" class="card-submit-button" style="margin-bottom: 10px;">70KG</button>
  <button type="submit" class="card-submit-button" style="margin-bottom: 10px;">80KG</button>
  <button type="submit" class="card-submit-button" style="margin-bottom: 10px;">90KG</button>
  <button type="submit" class="card-submit-button" style="margin-bottom: 10px;">100KG</button>
</div>

<!-- Com gap -->
<h4 class="page-title">CATEGORIAS</h1>
<div style="display: flex; flex-direction: column; gap: 10px;"> <!-- Gap aqui -->
  <button type="submit" class="card-submit-button">60KG</button>
  <button type="submit" class="card-submit-button">70KG</button>
  <button type="submit" class="card-submit-button">80KG</button>
  <button type="submit" class="card-submit-button">90KG</button>
  <button type="submit" class="card-submit-button">100KG</button>
</div>
```

### Responsivo (também tamanho fixo)

O **Boostrap** também tem a opção de espaçamento de tamanhos fixos, neste caso, disponibilizando uma classe que adicionamos em cada elemento que vai criar esse espaçamento. As classes do Bootstrap geralmente já aplicam um comportamento responsivo e assim não precisamos se preocupar com diferentes dimensões.

A classe é `mb-x`, sendo x o tamanho do espaçamento. Existem inúmeras formas de fazer espaçamento usando Bootstrap e todas estão descritas [aqui na documentação](https://getbootstrap.com/docs/5.3/utilities/spacing/). O resultado final para isso ficaria desta forma:

```html
<h4 class="page-title">CATEGORIAS</h1>
<div style="display: flex; flex-direction: column; gap: 10px;">
  <!-- mb-3 em cada elemento -->
  <button type="submit" class="card-submit-button mb-3">60KG</button>
  <button type="submit" class="card-submit-button mb-3">70KG</button>
  <button type="submit" class="card-submit-button mb-3">80KG</button>
  <button type="submit" class="card-submit-button mb-3">90KG</button>
  <button type="submit" class="card-submit-button mb-3">100KG</button>
</div>
```

<figure><img src="../../../.gitbook/assets/resultado espaçamento.png" alt=""><figcaption></figcaption></figure>

Vendo essa documentação, podemos ver que tem muitos tipos. Inclusive, podemos substituir todos os `mb-3` por `row-gap-3` na div e não em cada elemento que teria o mesmo efeito. Há de pesquisar nessa wiki e ver qual é o mais ideal para a situação.
