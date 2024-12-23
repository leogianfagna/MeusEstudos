# React

É uma [biblioteca](../glossario-extra.md) JavaScript para desenvolver aplicações front-end com uma arquitetura baseado em [<mark style="color:purple;">componentes</mark>](#user-content-fn-1)[^1]. Essas aplicações são chamadas de <mark style="color:purple;">SPA</mark> (Single Page Application) que significa que uma única [página renderiza](#user-content-fn-2)[^2] todas as páginas do sistema.

## Instalação

Apenas node é necessário para rodar uma aplicação react, que utiliza o comando `npx` (que o `x` vem de execute). Para iniciar, abrir um repositório no VsCode e executar o comando:

```bash
npx create-react-app nome-projeto
```

Essa versão acima pode estar deprecated. Neste caso, podemos criar uma aplicação react usando Vite, como [descrito aqui](https://www.freecodecamp.org/news/how-to-create-a-react-app-in-2024/). Nesse caso, usamos:

```bash
npm create vite@latest my-react-app -- --template react

cd my-react-app
npm install
npm run dev
```

[^1]: Separa o site em pedaços, como barra de navegação. Eles são **reutilizados**. Menos código e mais projeto.

[^2]: Tem várias páginas mas não há carregamento de página.
