# Imagens

## Tamanho da imagem

Definida com `width` e `heigth`, o tamanho pode ser:

<figure><img src="../../../.gitbook/assets/tamanho da imagem em css.png" alt="" width="469"><figcaption></figcaption></figure>

## Centralizar a imagem

Isso vai <mark style="color:blue;">centralizar a imagem na div e cortar o restante</mark>, <mark style="color:green;">sem distorção</mark>.

```css
img {
    object-fit: cover;
    object-position: center;
}
```

## Efeito de zoom

Aplicar essas classes na tag `img`.

```css
.img-hover-zoom {
  transition: transform 0.3s ease-in-out;
}

.img-hover-zoom:hover {
  transform: scale(1.1);
}
```
