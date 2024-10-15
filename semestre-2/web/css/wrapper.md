# Wrapper

Esse conceito pode ser usado quando você quer que um estilo <mark style="color:orange;">somente seja aplicado caso</mark> ele também tenha algum estilo pai aplicado, sendo usado perfeitamente para <mark style="color:blue;">**aplicar estilos em certos casos**</mark>. Por exemplo, declaramos uma div com um certo estilo, mas se a div pai não tiver um outro estilo (ou id) declarado, esse estilo não vai funcionar.

## Exemplo prático

Supondo o seguinte estilo:

```css
.card {
    background-image: linear-gradient(to bottom, #333c42 50%, #1D1E24);
    border: transparent;
}
```

Esse é um estilo que é do Bootstrap e foi declarado no nosso css para poder fazer essas duas alterações. Mas agora, todos os cards criados em qualquer página vão ter essa mesma características. E se em uma outra página não quisermos isso e queremos que ele tenha uma outra cor, como fazemos isso usando o mesmo arquivo css?

Para isso, usamos um estilo ou id wrapper. Ele consiste em declarar um estilo primeiro, que vai ser a condição para que o segundo estilo seja aplicado, por exemplo:

<figure><img src="../../../.gitbook/assets/explicação de wrapper em css.png" alt=""><figcaption></figcaption></figure>

Então o estilo `card` <mark style="color:orange;">só vai funcionar caso ele também esteja herdando</mark> o estilo `kart-info`. Então, para resolver o problema acima, podemos fazer isso para que esse estilo só seja aplicado em uma determinada condição e não em todos os HTML. Podemos fazer isso também com ID, ficando assim o resultado final:

<figure><img src="../../../.gitbook/assets/wrapper css com id.png" alt=""><figcaption></figcaption></figure>

## Uso moderno

Recente foi possível fazer um novo uso da classe wrapper. Vamos supor que não apenas um, mas vamos customizar vários elementos wrapper. Isso ficaria desta forma:

```css
.kartodromos-view {
    margin-top: 50px;
    display: flex;
}

.kartodromos-view .card {
    background-color: #b0b2b3;
}

.kartodromos-view .card-header {
    background-color: var(--light-bg-color);
}

.kartodromos-view .active {
    background-color: #b0b2b3;
}
```

Com o resultado sendo exatamente o mesmo, podemos escrever de uma forma diferente, que fica mais legível que essas classes são aplicadas de forma wrapper, podendo modernizar a escrita desta forma:

```css
.kartodromos-view {
    margin-top: 50px;
    display: flex;
    
    & .card {
        background-color: #b0b2b3;
    }
    
    & .card-header {
        background-color: var(--light-bg-color)
    }
    
    & .active {
        background-color: #b0b2b3
    }
}
```

De número de linhas e espaçamento é a mesma coisa, mas isso fica mais legível para deixar todos os elementos wrapper dentro das chaves do primeiro elemento.
