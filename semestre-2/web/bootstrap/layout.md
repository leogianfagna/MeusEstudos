# Layout

Na construção de um layout, precisamos saber:

## [Container](https://getbootstrap.com/docs/5.3/layout/containers/)

No Bootstrap, um **container** é um componente fundamental utilizado para envolver o conteúdo de uma página e alinhar adequadamente seus elementos dentro de uma estrutura de layout. O container serve como um **elemento de contenção** que define a largura máxima do conteúdo de acordo com o tamanho da tela (ou viewport) e facilita o uso do sistema de grid responsivo do Bootstrap.

Existem dois tipos principais de containers no Bootstrap:

1. **`container`**: É um container fixo que tem larguras predefinidas em pixels para cada ponto de quebra (breakpoint) do layout responsivo. À medida que o tamanho da tela aumenta ou diminui, o container ajusta sua largura de acordo com os limites do ponto de quebra, mantendo margens automáticas para centralizar o conteúdo.
2. **`container-fluid`**: Esse tipo de container tem 100% de largura e ocupa toda a largura disponível da tela, independentemente do ponto de quebra. Ele é usado quando você deseja que o conteúdo seja expandido para cobrir a tela inteira, sem limites laterais.

```html
<div class="container">
  <h1>Meu Conteúdo</h1>
  <p>
    Este conteúdo está dentro de um container fixo que se adapta ao tamanho da tela.
  </p>
</div>
```

## Flex

Funciona para gerenciar rapidamente o layout com um conjunto completo de utilitários flexbox responsivos. Para implementações mais complexas, CSS personalizado pode ser necessário. Usar o atributo `d-flex` ativa o flexbox, mas existem vários outros tipos desses.

Para ver melhor, podemos ver [essa documentação](https://getbootstrap.com/docs/5.3/utilities/flex/) e usar os atributos que melhor cabem nas nossas necessidades. Veja um exemplo de como fica um layout usando e não usando:

<figure><img src="../../../.gitbook/assets/uso do atributo d-flex em bootstrap.png" alt=""><figcaption></figcaption></figure>
