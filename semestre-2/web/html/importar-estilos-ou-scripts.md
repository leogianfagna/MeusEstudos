# Importar estilos ou scripts

#### Para apressados:

```html
<link rel="stylesheet" href="/src/css/styles.css">
<script src="/src/js/meuScript.js"></script>
```

A criação do CSS ou de Javascript que serão usadas na página podem ser colocadas no próprio HTML, dessa forma:

#### Estilos CSS

```html
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Landing Page HubSpot</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f7f9fa;
            margin: 0;
            padding: 0;
            // ....
```

#### Scripts Javascript

```html
<div id="nav-bar-pronta"></div>
<script>
    fetch('nav.html')
        .then(response => response.text())
        .then(data => {
            var elemento = document.getElementById('nav-bar-pronta');
            elemento.innerHTML = data;
        })
        .catch(error => console.error('Erro ao carregar o arquivo:', error));
</script>
```

## Importando de um arquivo de referência

Mas, podemos deixar eles em outro arquivo e apenas importá-los para a nossa página. Um arquivo CSS devem ser importadas dentro do <mark style="color:red;">`<head>`</mark> da sua página HTML. Isso garante que o estilo seja aplicado à medida que a página é carregada, prevenindo o "flash" de conteúdo não estilizado.

```html
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Landing Page HubSpot</title>
    
    <!-- Incluir arquivo de referência css -->
    <link rel="stylesheet" href="/src/css/styles.css">
    
    <!-- Incluir o arquivo de referência javascript -->
    <script src="/src/javascripts/cadastrar/cadastrar_aeronaves.js"></script>
</head>
```

O atributo "rel" vem de relacionamento, ele diz qual é a função do arquivo que você está importando. O tipo stylesheet significa folha de estilos, mas existem outros tipos como "preconnect", "alternate", "author", "bookmark", "icon" e entre outros. O "href" vem de referência, ele indica onde está o arquivo que você quer importar, que pode ser um arquivo dentro de uma pasta.

Já arquivos Javascript, é uma boa prática importá-los por último, antes de fechar a tag <mark style="color:red;">`<body>`</mark>. Isso permite que o HTML seja carregado e renderizado antes de tentar executar qualquer JavaScript.

```html
<body>
    <!-- Conteúdo da página -->
    <script src="script.js"></script>
</body>
```

Uma vez que implementado no \<head> ou em cima de algumas divs, pode ser possível que o conteúdo não tenha carregado ainda e o script não funcione, dependendo de como ele funciona. Portanto, se não funcionar, verifique onde ele está implementado.

Existem alguns atributos que definem como eles são baixados pelo navegador, como de forma assíncrona, antes, etc. São eles: async ou defer.

```html
<script src="script.js" async></script>
<script src="script.js" defer></script>
```
