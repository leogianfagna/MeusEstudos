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
