# Elementos escondidos

Podemos deixar elementos invisíveis na nossa página e fazer eles aparecerem usando funções. Basicamente, usamos um css que deixa o elemento invisível e usando funções javascript, podemos fazer com que eles apareçam, mudando os atributos de sua classe.

## Forma simples

Temos o seguinte elemento. Vamos inicializá-lo como invisível:

```html
<p class="success" id="infoCopiado">Código copiado para o teclado!</p>
```

```css
.success {
  display: none;
}
```

Agora criamos uma função que toda vez que ela for chamada, irá alterar os atributos e exibí-la, alterando o display para **block:**

```javascript
function mostrarCopiado() {
    document.getElementById('infoCopiado').style.display = 'block';
}
```

## Forma complexa (com efeito de saída)

Existe um método chamado `setTimeout(função, tempo em ms)`em que ele chama a função especificada depois de uma certa quantia de milisegundos. Se essa função tiver um código que altera as propriedades da classe para esconder o elemento, podemos criar uma função que aparece o elemento e ele some depois de um tempo, da seguinte forma:

```javascript
var elemento = document.getElementById('infoCopiado');
elemento.style.display = 'block'; // Exibir

setTimeout(function() {
  elemento.style.display = 'none'; // Esconder novamente
}, 3000);
```

No caso acima, vai exibir e esconder depois de 3000 milisegundos (3s). Não foi chamada uma outra função a partir dele e sim criado uma função dentro do método setTimeout mesmo, abrindo as chaves ali mesmo.
