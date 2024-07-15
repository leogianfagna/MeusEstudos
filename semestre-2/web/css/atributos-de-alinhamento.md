# Atributos de alinhamento

_Tutorial Try It de Nav bar:_ [_https://www.w3schools.com/howto/tryit.asp?filename=tryhow\_css\_topnav\_right_](https://www.w3schools.com/howto/tryit.asp?filename=tryhow\_css\_topnav\_right)

## Margin padrão do body

Na criação raíz, a tag body possui um atributo chamado <mark style="color:blue;">`margin`</mark> que define alguns pixels como uma margem até a borda (extremo) do site. Criando uma div para servidor como nav-bar, podemos ver esse atributo que não deixa ela encostrar em suas extremidades:

<figure><img src="../../../.gitbook/assets/criação nav bar css.png" alt=""><figcaption></figcaption></figure>

Definindo o margin como zero em uma classe da nav-bar não irá funcionar, pois esse é um atributo raíz do body. Portanto, devemos criar um estilo para o próprio body, onde definimos a margin como zero manualmente:

```css
body {
    margin: 0;
}

#nav {
    background-image: linear-gradient(to bottom right, #2A864F, black);
    border: 1px solid;
    margin: 0;
}
```

Zerando a margem, não teremos mais espaçamento entre as bordas do site, ficando desta forma:

<figure><img src="../../../.gitbook/assets/nav bar com css.png" alt=""><figcaption></figcaption></figure>

## Tamanho da div

No caso estaremos falando de uma nav bar. O tamanho horizontal é ocupar do início ao fim da página, mas e o vertical? Nesse cenário, vamos definir um <mark style="color:blue;">`padding`</mark> (preenchimento) partindo dos elementos que estão dentro dessa div. Podemos definir um preenchimento em tantos pixels e assim a div se espande proporcionalmente a partir dos elementos que definimos isso.

Em um cenário de nav-bar, temos a div da classe **elementosNav** e dentro dela as tags **\<a>** para cada menu da navegação.&#x20;

```html
<div class="elementosNav">
    <a>Link 1</a>
    <a>Link 2</a>
    <a>Link 3</a>
</div>
```

Em qual estilo devemos colocar o padding: em <mark style="color:green;">`.elementosNav`</mark> ou <mark style="color:green;">`.elementosNav a`</mark>? Vamos analisar:

### Usando padding para toda a div

Usar dessa forma indica que o `padding` será aplicado ao redor de todo o conteúdo dentro desta `<div>`, mas não diretamente aos elementos `<a>` dentro dela, como se todos os `<a>` dentro dela seriam apenas um único só elemento e o preenchimento inicia-se ao redor desse "único elemento". Ficando da seguinte forma:

<figure><img src="../../../.gitbook/assets/margin e padding css.png" alt=""><figcaption></figcaption></figure>

```css
.elementosNav {
    font-size: 20px;
    color: white;
    padding: 30px;
}
```

Podemos reparar que o espaçamento inicia-se a partir da junção dos elementos "ola" "ola" "ola", que são na verdade 3 \<a> seguidos, e não entre um e outro.

### Usando padding no texto

Isso vai aplicar o espaçamento apenas entre os elementos do texto, especificamente \<a>, não colocando nenhum espaçamento com base na div ou outros elementos.

<figure><img src="../../../.gitbook/assets/padding css.png" alt=""><figcaption></figcaption></figure>

```css
.elementosNav a { /* Especificado apenas para <a> */
    font-size: 20px;
    color: white;
    padding: 30px;
}
```

### Conclusão

Portanto, usamos o padding na classe que será direcionada para a div para fazer um preenchimento maior dela. O foco desse tópico é apenas o preenchimento da div, mas se quisermos também separar em pixels os elementos de \<a> um do outro (muito provável vai querer), utilizamos também o padding na classe para os textos, tendo assim, uma nav-bar pronta.

### Adições ao Padding

Quando utilizamos mais de um valor no atributo `padding` no CSS, estamos definindo diferentes valores de espaçamento interno (padding) para diferentes lados do elemento. A sintaxe de `padding` permite até quatro valores:

1. **Um valor (`padding: 10px;`)**:
   * Aplica o mesmo espaçamento interno a todos os quatro lados do elemento (topo, direita, base e esquerda).
2. **Dois valores (`padding: 10px 5px;`)**:
   * O primeiro valor é aplicado ao **topo e base**.
   * O segundo valor é aplicado às **laterais direita e esquerda**.
3. **Três valores (`padding: 10px 5px 20px;`)**:
   * O primeiro valor é aplicado ao **topo**.
   * O segundo valor é aplicado às **laterais direita e esquerda**.
   * O terceiro valor é aplicado à **base**.
4. **Quatro valores (`padding: 10px 5px 20px 15px;`)**:
   * O primeiro valor é aplicado ao **topo**.
   * O segundo valor é aplicado à **direita**.
   * O terceiro valor é aplicado à **base**.
   * O quarto valor é aplicado à **esquerda**.

## Alinhamento de div dentro de div

Em um exemplo, temos uma div apenas para centralizar os elementos dentro de uma nav-bar <mark style="color:purple;">`text-allign: center`</mark> para isso. Agora, foi criado mais uma div dentro com o objetivo de inserir alguns ícones. Contudo, queremos que esses ícones fiquem alinhados ao final da div pai. Nosso HTML está assim:

```html
<div id="nav">
    <div class="elementosNav">
        <a>Início</a>
        <a>Inscrição</a>
        <a>Sobre</a>
        <a>Contato</a>
        <a>Galeria</a>
        
        <!-- Inserindo aqui -->
        <div class="iconesNav">
            <p>Nossos ícones</p>
        </div>
    </div>
</div>
```

<figure><img src="../../../.gitbook/assets/alinhamento css 2.png" alt=""><figcaption></figcaption></figure>

Em amarelo, a div nova e em preto a div pai. Podemos ver que ela está dentro, mas queremos duas coisas para conseguir jogar no canto:

1. Que fique na mesma linha
2. Que se alinhe ao final da div pai, na direita

Para fazer isso, usamos o atributo <mark style="color:blue;">`float`</mark>. Esse atributo é utilizado para posicionar elementos ao lado esquerdo ou direito de seu contêiner. Ele tem como valor padrão none, mas ao usar tanto right ou left, ele é <mark style="color:red;">**retirado do fluxo normal do documento**</mark> e posicionado à direita ou esquerda dentro de seu contêiner pai, por isso que também não é necessário da tag <mark style="color:blue;">`display`</mark> para posicionar na mesma linha. O float já faz isso.

Além de **none**, **right** e **left**, ele também poderá ser **inherit**, que vai herdar o valor de float do elemento pai. Como resultado final, temos:

```css
.iconesNav {
    float: right;
}
```

<figure><img src="../../../.gitbook/assets/alinhamento css 1.png" alt=""><figcaption></figcaption></figure>

