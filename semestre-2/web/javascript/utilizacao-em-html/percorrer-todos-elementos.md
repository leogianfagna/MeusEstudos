# Percorrer todos elementos

Uma função incrível pode percorrer todos os elementos do nosso HTML para tentar algo específico. Vamos supor que temos diversos [elementos escondidos](../../html/elementos-escondidos.md) e queremos exibir todos chamando uma função, muito útil ao selecionar uma opção em que precisamos exibir tudo e depois esconder o que queremos.

Podemos criar essa função para fazer tal funcionalidade:

```javascript
function mostrarTudo() {
    const elementosOcultos = document.querySelectorAll("*[style*='display: none']");
    elementosOcultos.forEach(elemento => {
        elemento.style.display = 'block';
    });
}
```

Essa função primeiro capta todos os elementos cujo display esteja marcado como <mark style="color:red;">`none`</mark> depois percorre cada um deles usando uma função lambda e o método `forEach()`, alterando seu estilo para <mark style="color:red;">`block`</mark>, fazendo com que eles apareçam.

Usando o método `querySelectorAll()`, podemos fazer diferentes tipos de pesquisas e conseguir dados desejados.

Se podemos percorrer elementos, se temos uma lista com vários "radios", podemos usar esse método para descobrir todos os radios que estão selecionados. Veja esse exemplo abaixo que começa primeiro definindo em qual div está localizado esses elementos, usando a variável "motivosOffline":

```javascript
function getSelectedMotivo() {
    const motivosOffline = document.getElementById("div-motivos-offline");
    const radioButtons = motivosOffline.querySelectorAll("input[type='radio']");

    for (const radioButton of radioButtons) {
      if (radioButton.checked) {
        // Encontrar o label associado ao rádio selecionado
        const label = radioButton.nextElementSibling;
        return label.textContent;
      }
    }

    return null;
}
```
