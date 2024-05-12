---
description: https://getbootstrap.com/docs/5.3/getting-started/introduction/
---

# Bootstrap

Boostrap é uma biblioteca de componentes visuais dividida em dois arquivos: CSS e Javascript. Essas bibliotecas servem para desenvolver telas de <mark style="color:green;">**front-end mais rapidamente**</mark>, aproveitamento componentes já criados.

Usa-se muito a ideia de **container**: um espaço vazio onde coisas podem ser colocadas. Um container fluid é uma classe que mostra que um elemento vai ficar do lado do outro.

## Como usar

É necessário importar separadamente o CSS (no `<head>`) e o Javascript (no `<body>`). Então, adicionar as seguintes linhas para importar:

```html
<!DOCTYPE html>
<html lang="pt-BR">
<head>
  <title>O título da página</title>
  
  <!-- Adicionar essas linhas para importar o css-->
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-T3c6CoIi6uLrA9TneNEoa7RxnatzjcDSCmG1MXxSR1GAsXEV/Dwwykc2MPK8M2HN" crossorigin="anonymous">
</head>
<body>
  <!-- Adicionar essa linha para importar o javascript -->
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz" crossorigin="anonymous"></script>
</body>
```

Depois disso, a adição de elementos é baseado em nome das classes que foram declaradas no CSS do Boostrap. Basta importar já componentes prontos usando a documentação do Boostrap.

Você pode criar suas próprias variáveis no css. Por exemplo, criou-se a variável “data-bs-theme” no Boostrap e especificou ela no HTML. Nesse caso, foi usada para trocar o tema para escuro.

Neste caso, se você colocar no body, a página inteira vai ficar no estilo dark. Se colocar no nav, somente a barra ficará em modo dark.
