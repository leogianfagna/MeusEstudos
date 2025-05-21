# Responsividade

A responsividade nas aplicações web implicam no uso de técnicas de design e de desenvolvimento que possibilitam a <mark style="color:blue;">adaptação das telas</mark> para diferentes dispositivos e tamanhos de tela. Isso é altamente necessário e precisa ser presente em todas as aplicações.

Basicamente, a solução de responsividade gira em torno de usar as <mark style="color:green;">classes disponíveis do Bootstrap</mark> <mark style="color:green;">com unidades relativas</mark> fornecidas pelo próprio css. Usando esses dois, conseguimos um bom resultado. O Bootstrap facilita muito por ser todo responsivo e a documentação necessária está em sua grande maioria na categoria **Utilities**.

## Unidades relativas

Pixels podem ser muito rígidos, enquanto unidades como **`rem`** ou **`em`** se adaptam melhor em diferentes resoluções, pois se ajustam com <mark style="color:blue;">base no tamanho da fonte</mark>. Por ser baseado no tamanho da fonte, o <mark style="color:orange;">uso delas é recomendado para espaçamentos internos, margens e texto</mark>. Essas unidades possuem uma pequena diferença:

* rem: sempre se baseia no tamanho da fonte do elemento raiz que seria a página.
* em: é uma unidade relativa ao tamanho da fonte do elemento pai imediato. Pode ser mais útil já que se o pai tiver fontes diferentes, ele vai se adaptar ao pai.

## Espaçamento com classes

Se precisamos espaçar uma div da outra verticalmente, podemos usar as próprias classes do Bootstrap para fazer isso que vão garantir responsividade. Basicamente, queremos espaçar isso:

<figure><img src="../../../../.gitbook/assets/espaçar divs com classes.png" alt=""><figcaption></figcaption></figure>

Em vez de usar um margin-top diretamente, usamos a classe `mt-x` ou `mb-x` (depende se queremos para cima ou para baixo) do Boostrap, substituindo o X pelo tamanho desejado.

```html
<!-- Antes -->
<div class="container text-center" style="margin-top:100px">

<!-- Depois-->
<div class="container text-center mt-5">
```

## Imagens

Uma imagem colocada na página vai sempre ser exibida por inteira independente da dimensão, podendo criar barras de rolagens em diferentes dispositivos. Em casos que usamos `width="100%"` para preencher toda a horizontal, uma imagem vai ser esticada dessa forma:

<figure><img src="../../../../.gitbook/assets/imagem sem responsividade.png" alt="" width="340"><figcaption></figcaption></figure>

Usando a classe `"img-fluid"` do Bootstrap, conseguimos deixar a imagem responsiva e fluída. Existem vários tipos de classes na documentação do Bootstrap que vão criar diferentes resultados, todas elas podem ser [vistas aqui](https://getbootstrap.com/docs/5.3/content/images/). Com essa classe, o resultado em telas pequenas fica:

<figure><img src="../../../../.gitbook/assets/imagem com responsividade.png" alt="" width="375"><figcaption></figcaption></figure>
