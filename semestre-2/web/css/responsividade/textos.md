# Textos

## Tamanho do texto

Se um texto está dentro de uma caixa, se essa caixa diminuir de tamanho baseado na janela do usuário (responsividade), esse texto poderá ser quebrado, pois ele mantém o mesmo tamanho de fonte mas a caixa diminui. Por exemplo:

<figure><img src="../../../../.gitbook/assets/tamanho de caixa na web.png" alt=""><figcaption></figcaption></figure>

Seria interessante o <mark style="color:green;">tamanho da fonte diminuir conforme o tamanho do elemento pai</mark>. Para isso, podemos usar a unidade de medida `vw` no tamanho da fonte, que é uma unidade baseada com as configurações do tamanho do viewport.

```css
.input-name {
  width: 200px;

  /* Texto responsivo */
  text-wrap: wrap;
  font-size: 1vw;
}
```

Como resultado, podemos ter qualquer tamanho de tela que o texto vai se diminuir e não sair das caixas. Ambos os exemplos mostram telas diminuídas:

<figure><img src="../../../../.gitbook/assets/propriedade vw para textos responsivos.png" alt=""><figcaption></figcaption></figure>
