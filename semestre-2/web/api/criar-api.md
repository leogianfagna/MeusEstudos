# Criar API

1. Executar `npm init -y`.
2. Executar `npm install express nodemon`.
3. Definir script de inicialização:

```json
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1",
    "start": "nodemon ./index.js localhost 3000" // Inserir package.json
  },
```

#### Criar arquivo index.js

```javascript
const express = require('express')
const app = express()

app.use(
    express.urlencoded({
        extended: true
    }),
)

app.use(express.json())

// Rotas - endpoints
app.get('/', (req, res) => {
    res.json({ message: "Rota criada com sucesso" })
})

app.listen(3000)
```

Esse arquivo pode ser testado rodando o script com `npm start` e entrando no navegador [http://localhost:3000/](http://localhost:3000/).
