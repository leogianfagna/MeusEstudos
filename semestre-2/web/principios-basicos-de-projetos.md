# Princípios básicos de projetos

Usaremos o VSCode para programar. Todo projeto é localizado em um diretório (que seria uma pasta), inicialmente, inicia-se com o diretório vazio. Dentro do Visual Studio, o Explorer funciona para visualizar os arquivos do projeto.

O VSCode é uma IDE. IDE significa Ambiente de Desenvolvimento Integrado, ou seja, é uma ferramenta de desenvolvimento que agrega vários recursos em um só, como edição de código, acesso ao terminal, execução do script, debugar e compilar.

Então para começar, é necessário a criação de um repositório e abrir o mesmo usando o EXPLORER do programa.

<figure><img src="../../.gitbook/assets/repositório de projeto.png" alt=""><figcaption></figcaption></figure>

O termo “search” se difere do “find”. SEARCH é usado com mais profundeza, procurar dentro do projeto inteiro onde se localiza certa escrita. Já o FIND, é utilizado como uma espécie de Ctrl + F, para localizar dentro do arquivo que está aberto.

Vamos precisar de uma conta no GitHub para armazenar os repositórios. Ao abrir o Visual Studio pela primeira vez, fazer os downloads dos seguintes plugins (extensões):

<figure><img src="../../.gitbook/assets/extensões para programar em web.png" alt=""><figcaption></figcaption></figure>

A indicação é trabalhar com fontes de tamanho 16-18, que podem ser alteradas nas configurações do VSCode. Para começar, devemos criar arquivos dentro desse repositório. O primeiro arquivo será: index.html

## Assets

São todos os conteúdos que não são HTML, por exemplo, arquivos, recursos, Javascript, CSS, entre outros.

Sempre separar os estilos do HTML exceto em componentes autocontidos (aqueles que ficam todas as linguagens em um mesmo arquivo, como HTML, Javascript e CSS para construir um calendário.view). Isso é por questão de organização. Em um trabalho, o estagiário não tem permissão de alterar o style.

Em CSS, sempre adicionar os estilos para não esquecer de ninguém, mesmo se não for utilizar.

## Qualidade

Usando imagens em WEB, ter várias imagens (máximo de 100kb) ao invés de uma grande. Criando o style do site, colocar o widght menor que o tamanho da imagem, questão de qualidade para carregamento mais rápido e não carregar coisas não necessárias.

Sempre usar padrões encontrados em estatística. Números em uma tabela devem ser alinhados na direita, devido a área chamada semiótica.

### Padrões de nomes de arquivos

Por uma melhor qualidade, sempre seguimos padrões. A nomeação de arquivos dentro de um projeto Web, sejam eles `.css`, `.html` e `.js`, seguem uma formatação chamada <mark style="color:purple;">**Kebab Case**</mark>, que consiste no nome com letras minúsculas e separadas por hífens. Para CSS, também podemos usar **BEM Naming**, mas é algo avançado e não será comentado.

Então, por padrão, iremos usar esses tipos de nomes:

```
\html
   - index.html
   - status-page.html
   
\scripts
   - check-status.js
   - main-script.js

\styles
   - card-animation-presets.css
   - styles.css
```

### Padrões de variáveis

Nome de classes ou ids de elementos em HTML também seguem o mesmo padrão e formatação Kebab Case dito acima. Assim ficando:

```html
<div id="main-forms">
    <div class="list-items"></div>
</div>
```

```css
.cubes-formats {
  position: absolute;
  top: 50%;
  left: 50%;
  transform-style: preserve-3d;
}
```

## Arquitetando o projeto

Na criação de projeto web, seguir algumas etapas:

1. Estruturar a aparência (arquitetura espacial):
   1. Onde ficará cada coisa da página
2. Alinhamento
   1. Criar estilos de alinhamento
   2. Independente de um texto já está centralizado, deve criar o estilo para todos
3. Tipografia (qual fonte utilizar)
4. Design

