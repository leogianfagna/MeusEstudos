# Mudanças de lugar

Quando um elemento passa a ficar espremido pela diminuição da tela, pode ser inteligente fazer mudanças em seu comportamento ou mudá-lo de lugar, como por exemplo uma nav bar usando <mark style="color:purple;">media queries</mark>.

## Subir navbar lateral

Vamos supor que temos um aside lateral e ao espremer, queremos jogar para cima, como uma nav bar comum. Mesmo tendo programado para ficar do lado, apenas mudando estilos como `width` e `height` conseguimos mover ela de lugar.

#### Alterar orientação

Se temos uma navbar lateral e o conteúdo da nossa página na direita, isso só é possível pois temos um container maior (tipo body) sendo flex permitindo isso. Então precisamos mudar essa orientação:

```css
/* Esse era o que já tínhamos */
.body {
  display: flex;
  height: 100vh;
  overflow: hidden;
}

/* Isso vai mudar o comportamento do body para fazer nossa nova navbar funcionar */
@media screen and (max-width: 700px) {
  .body {
    display: block;
    overflow: auto;
  }
}
```

#### Alterar tamanhos

Esse exemplo mostra claramente como a mudança dos estilos de largura e altura mudam a posição do elemento na página. Se temos algo que preenchia completamente uma altura e passa a preencher a largura, isso muda completamente sua posição sem a necessidade de alterar o HTML, veja:

```css
aside {
  width: 240px; /* Mostra que vai até um certo ponto horizontalmente */
  height: 100%; /* Mostra que vai até em baixo da tela */
  background: #000000;
  box-sizing: border-box;
}

@media screen and (max-width: 700px) {
  aside {
    width: 100%; /* Agora ela ocupa a largura toda */
    height: fit-content; /* E deixa de ocupar toda a altura, e apenas seu conteúdo */
    position: relative;
  }
}
```

#### Esconder elementos sobrando

Se tiver elementos abaixo da navbar que estavam antes da página e que agora ficam flutuando sem sentido pela página, podemos simplesmente removê-los:

```css
@media screen and (max-width: 700px) {
  .page-header {
    display: none;
  }
}
```
