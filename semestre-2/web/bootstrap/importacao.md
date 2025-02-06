---
description: https://getbootstrap.com/docs/5.3/getting-started/introduction/
---

# Importação

## HTML puro

É necessário **importar** separadamente o CSS (no `<head>`) e o Javascript (no `<body>`). Então, adicionar as seguintes linhas para importar:

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

## React

```bash
npm install react-bootstrap bootstrap
```

Depois basta importar os elementos que for usar em cada componente, como:

```jsx
import { Button } from 'react-bootstrap';
```
