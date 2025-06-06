# GitHub Pages

## Problemas com diretório de arquivos

As vezes  algum elemento importado (fonte, imagens, etc) não são encontrados na página do GitHub Pages mas funcionando no live preview. Isso ocorre porque quando postamos a página no Git o repositório é alterado. Para corrigir, utilizamos `../` que significa que vamos subir para o diretório pai.

```css
src: url('../assets/fonts/kafum/Kufam-Regular.ttf') format('opentype');
```

### Imagens em React

As imagens devem estar na pasta `public` para funcionar corretamente. Diferentemente da abordagem acima, para funcionar corretamente em React, deve seguir esse padrão de caminho (isso porque ao postar no gh-pages, a pasta `public` é removida da build e resta apenas o `assets`):

```jsx
src={"/assets/images/outra_pasta/image.png"}
```

## GitHub Pages com Vite (React)

É possível hospedar uma página no Github Pages com uma aplicação <mark style="color:blue;">React buildada com Vite</mark>.

### Preparar o repositório em React

Vamos supor que já foi criado um projeto e você está com ele aberto.

#### 1. Configurar o base do Vite

Adicione o campo `base` com o nome do repositório do GitHub no arquivo `vite.config.js`.

```jsx
import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'

// https://vite.dev/config/
export default defineConfig({
  plugins: [react()],
  base: '/NomeDoRepositório/',
})
```

#### 2. Configurar o deploy

Adicionar um script de deploy que envia as mudanças para os pages no arquivo `package.json`.

```json
  "scripts": {
    "dev": "vite",
    "build": "vite build", // Aqui
    "lint": "eslint .",
    "preview": "vite preview",
    "deploy": "gh-pages -d dist"
  },
```

#### 3. Criar o repositório

Se esses arquivos ainda não estão em um repositório GitHub, envie-os para um público.

#### 4. Buildar o projeto

O projeto precisa ser buildado para funcionar corretamente no GitHub Pages, use:

```bash
npm run build
```

#### 5. Publicar o pages

Esse comando cria uma nova branch, que essa branch será usada pelo GitHub pages para exibir o site. Ela terá arquivos de uma forma diferente da `main`, para funcionar corretamente:

```bash
npm run deploy
```

#### 6. Ativar o GitHub Pages

Visite as configurações do repositório e ative o pages (normalmente será ativado automaticamente). Lembrando que a página precisa estar baseado na branch criada, chamada `gh-pages`.

### Atualizar a aplicação depois de mudanças

Precisamos atualizar as duas branchs: `main` (que guardará os arquivos para manter o histórico de desenvolvimento) e a `gh-pages` (responsável por construir nossa página no GitHub funcional). O conteúdo dessas duas branchs são separados.

#### 1. Enviar alterações para a main

Processo normal, apenas atualizar o código:

```bash
git add .
git commit -m "..."
git push origin main
```

#### 2. Deploy no GitHub Pages

Buildar a nova página e enviar para a branch poder usá-la:

```bash
npm run build
npm run deploy
```

### Voltar a mexer no site do zero

Vamos supor que usamos clone em um repositório React. Nenhum comando de início vai funcionar, como `npm run dev`. Isso acontece pois no repositório GitHub não são subidas as dependências que fazem esses comandos funcionarem. Depois do clone, você deve executar:

```bash
npm install
```

Essa dica normalmente é adicionada no `README`, nas explicações de como buildar o projeto.
