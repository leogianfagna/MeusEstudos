# Posicionamento de divs

Como colocar uma div ou elemento ao lado do outro, sendo na horizontal ou na vertical? Esses aspectos são definidos através do atributo `flex-direction`.

## Flexbox

O `display: flex` é uma propriedade CSS que ativa o **Flexbox**, um modelo de layout moderno que facilita a criação de <mark style="color:blue;">layouts flexíveis e responsivos</mark>, isso quer dizer que os itens flexíveis se ajustam automaticamente ao tamanho do container pai. Isso é muito importante sabermos pois usando ele iremos utilizar o atributo que mencionamos acima, que vai indicar a <mark style="color:green;">direção</mark>.

## Flex Direction

Essa imagem vai esboçar como as divs se encontram usando cada um dos elementos de direcionamento:

<figure><img src="../../../.gitbook/assets/exemplos de direcionamento css.png" alt=""><figcaption></figcaption></figure>

Portando, o body (ou um container que contém tudo) está direcionado para cada item ficar em baixo do outro com `column`, assim como o título principal (queremos que a descrição do título fique abaixo dele). Já os cards abaixo, queremos que fiquem um do lado do outro então usamos `row`.

Para ver a diferença, se trocarmos o atributo no <mark style="color:red;">body</mark> para `row`, teremos esse resultado:

<figure><img src="../../../.gitbook/assets/direcionamento com row css.png" alt=""><figcaption></figcaption></figure>

Por definição, o estilo row é o padrão utilizado. Então, não indicar essa característica vai aplicar esse padrão para tudo, podendo criar essa dúvida de <mark style="color:purple;">como deixar uma div/elemento de baixo da outra</mark>.

## Outras características do `display: flex`:

Muitas das seguintes caracterísitcas são aspectos de alinhamento, descritas em "[Atributos de alinhamento](alinhamento.md)".

1. **Alinhamento ao longo do eixo principal e cruzado:**
   * `justify-content`: Alinha os itens ao longo do eixo principal (horizontal por padrão).
   * `align-items`: Alinha os itens ao longo do eixo cruzado (vertical por padrão).
   * `align-content`: Alinha as linhas flexíveis se houver espaço extra no eixo cruzado.
2. **Controle de espaço entre os itens:**
   * Propriedades como `gap`, `justify-content`, `align-items` e `align-content` permitem controlar o espaço entre os itens e como eles se distribuem dentro do container.
3. **Flexibilidade de tamanho dos itens:**
   * Propriedades como `flex-grow`, `flex-shrink` e `flex-basis` permitem que os itens flexíveis cresçam, encolham e se ajustem conforme necessário para preencher o espaço disponível.
