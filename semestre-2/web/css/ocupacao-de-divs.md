# Ocupação de divs

Aqui estaremos falando de ocupação da div sem nos preocupar com o [posicionamento](posicionamento-de-divs.md) dela, seja a posição dela na tela, a orientação ou coisas do tipo. Esse tópico foi bem detalhado na página anterior. A ocupação é sobre a <mark style="color:blue;">área que ela vai ocupar</mark>, sendo ela fixa, estática, etc.

## Ocupação pré definida

Vamos supor que queremos que uma div ocupe um <mark style="color:purple;">espaço da tela pré definidos</mark> por nós e este espaço seja uma porcentagem da div pai dela. Para isso, precisamos usar esses atributos nesta div:

* `width`: estabelece a distância horizontalmente em porcentagem que vai ocupar da tela.
* `height`: estabelece a distância verticalmente em porcentagem que vai ocupar da tela.
* `margin`: é utilizado para centralizar blocos de elementos horizontalmente quando a largura já está definida. Sem ele, a div será alinhada no início da tela, tanto vertical como horizontal.
* `position`: usando "absolute" estabelecerá que ele não será empurrado pelos outros elementos. Sem ele, a div será empurrada para cima e a sua distância vertical não será esticada para baixo como deveria.
* preenchimento `top`,  `left`, `bottom`, `right`: servem para esticar todo o elemento do container posicionado. Sem eles, ele não será preenchido.

```css
#mainContainer {
    background-color: #1C212C;
    width: 50%;
    height: 80%;
    margin: auto;
    position: absolute;
    top: 0; left: 0; bottom: 0; right: 0;
}
```

Veja abaixo o resultado disso, onde a parte cinza é a div com os estilos marcados e a parte roxa é todo o body, que no caso, não tem mais nada:

<figure><img src="../../../.gitbook/assets/ocupação de div pré definida.png" alt=""><figcaption></figcaption></figure>

## Ocupação relativa

Uma div por padrão vai ocupar os elementos que ela contém, portanto, se queremos que o tamanho dela seja o suficiente para preenche-los, claramente não precisamos nos preocupar nestes estilos. Agora, vamos ver possibilidades em que temos <mark style="color:purple;">apenas uma dimensão pré definida</mark> e a outra ocupará o que possui de elementos.

Se tirarmos o elemento `height`, a div ocupará 100% do espaço vertical. Para solucionar o que queremos, precisamos agora de duas divs, uma que seja a pai que estamos trabalhando e trabalharemos com estes elementos:

#### Div pai

* `height`: Pode ser útil se o preenchimento é vertical, não é nosso caso.
* `margin`: Pode ser útil se o preenchimento é vertical, não é nosso caso.
* `display`, `justify-content` e `align-items`: São elementos de posicionamento para entregar flexibilidade à div pai. Os elementos de justificação e alinhamento são opcionais caso queremos centralizar a div filho no centro.

#### Div padrão

* `width`: estabelece a distância horizontalmente em porcentagem que vai ocupar da tela. Mesmo caso anterior.
* `margin-top`: estabelece a partir de qual ponto a div começa, claro que aqui é muito opcional dependendo do que se procura, que nem usar o `padding`.

Assim, nosso resultado final, temos:

```css
#pai {
    height: 100%;
    margin: 0;
    display: flex;
    justify-content: center;
    align-items: center;
}

#mainContainer {
    margin-top: 10%;
    background-color: #1C212C;
    width: 50%;
    padding: 20px;
}
```

<figure><img src="../../../.gitbook/assets/ocupação relativa de divs vertical.png" alt=""><figcaption></figcaption></figure>
