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
