# React

É uma [biblioteca](../glossario-extra.md) JavaScript para desenvolver aplicações front-end com uma arquitetura baseado em [<mark style="color:purple;">componentes</mark>](#user-content-fn-1)[^1]. Essas aplicações são chamadas de <mark style="color:purple;">SPA</mark> (Single Page Application) que significa que uma única [página renderiza](#user-content-fn-2)[^2] todas as páginas do sistema.

## Instalação

Podemos criar uma aplicação react usando Vite, uma <mark style="color:purple;">ferramenta moderna de build</mark> que foi criada para fornecer um ambiente de desenvolvimento mais rápido e eficiente, como [descrito aqui](https://www.freecodecamp.org/news/how-to-create-a-react-app-in-2024/). Nesse caso, usamos:

```bash
npm create vite@latest my-react-app -- --template react

cd my-react-app
npm install
npm run dev
```

## Extensões para uso

<figure><img src="../../../.gitbook/assets/extensao snippets react.png" alt=""><figcaption></figcaption></figure>

[^1]: Separa o site em pedaços, como barra de navegação. Eles são **reutilizados**. Menos código e mais projeto.

[^2]: Tem várias páginas mas não há carregamento de página.
