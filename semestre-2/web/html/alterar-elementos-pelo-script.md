# Alterar elementos pelo script

A página a seguir mostra como alterar o valor, texto ou qualquer coisa de um elemento HTML, definido através de um ID. É o mesmo esquema mostrado na página anterior de elementos escondidos.

## Mudar texto

```javascript
document.getElementById('infoCopiado').innerText = 'Novo texto';
document.getElementById('infoCopiado').textContent = 'Novo texto';
```

## **Mudar o HTML interno de um elemento**:

```javascript
jdocument.getElementById('infoCopiado').innerHTML = '<strong>Novo texto com HTML</strong>';
```

## **Mudar o valor de um campo de formulário**:

```javascript
document.getElementById('meuInput').value = 'Novo valor';
```

Esse exemplo foi usado em um sistema meu de alterar as cores RGB em um site gerador de degradês, onde ele pegava o primeiro e o segundo RGB e trocava a ordem deles:

```javascript
// Resgatar os dois elementos que serão trocados
const corLabel = document.getElementById("color-" + n).value;
const corLabelAbaixo = document.getElementById("color-" + (parseInt(n) + 1)).value;

// Fazer a troca
document.getElementById("color-" + n).value = corLabelAbaixo;
document.getElementById("color-" + (parseInt(n) + 1)).value = corLabel;
```

## **Mudar o atributo de um elemento**:

```javascript
document.getElementById('minhaImagem').src = 'novaImagem.jpg';
document.getElementById('meuLink').href = 'https://novo-link.com';
```

## **Adicionar ou remover classes CSS**:

```javascript
document.getElementById('meuElemento').classList.add('novaClasse');
document.getElementById('meuElemento').classList.remove('classeExistente');

// Use className para setar uma classe, podendo remover todas desta forma:
document.getElementById('meuElemento').className = '';
```

## **Mudar múltiplos estilos de uma vez**:

```javascript
var elem = document.getElementById('meuElemento');
elem.style.backgroundColor = 'blue';
elem.style.fontSize = '20px';
```

## **Ocultar ou mostrar um elemento**:

```javascript
document.getElementById('meuElemento').style.display = 'none';  // Ocultar
document.getElementById('meuElemento').style.display = 'block';  // Mostrar
```

## **Adicionar um evento a um elemento**:

```javascript
document.getElementById('meuBotao').addEventListener('click', function() {
    alert('Botão clicado!');
});
```

## **Criar e adicionar um novo elemento ao DOM**:

```javascript
var novoElemento = document.createElement('div');
novoElemento.innerText = 'Este é um novo elemento';
document.body.appendChild(novoElemento);
```

## **Remover um elemento do DOM**:

```javascript
var elem = document.getElementById('elementoParaRemover');
elem.parentNode.removeChild(elem);
```
