# Imagem de fundo com conteúdo sobreposto

<figure><img src="../../../../.gitbook/assets/css imagem de fundo.png" alt=""><figcaption></figcaption></figure>

Conteúdo sobreposto estamos falando de colocar a imagem como background do elemento. O posicionamento do texto text-box é feito de forma estática, que acaba funcionando mesmo assim para qualquer dimensão.

```html
<header>
  <div className="text-box">
    <h1>Título</h1>
    <p>Descrição</p>
    <button>Botão</button>
  </div>
</header>
```

```css
.text-box {
  text-align: start;
  margin: 180px 0px 451px 41px;
  position: relative;
  top: 125px;
}

header {
  background: url("../public/background-img.png") no-repeat 50% center;
  background-size: cover;
  background-position: center;
  display: flex;
  flex-direction: column;
  position: relative;
  opacity: 0.9;
  overflow: hidden;
  min-height: 85vh;
}
```
