# Javadoc

É uma ferramenta utilizada para gerar automaticamente uma documentação do código em formato HTML a partir de comentários especiais no código-fonte. Esses comentários, permitem descrever o comportamento, os parâmetros e o retorno dos métodos, além de fornecer detalhes sobre a funcionalidade geral das classes e interfaces. A documentação gerada é útil tanto para desenvolvedores que utilizam a API quanto para a manutenção e entendimento do código, facilitando a leitura e o uso correto do software.

## Detalhes

* São escritos antes de métodos `public` ou `protected` apenas.
* Iniciam com `/**`.
* Podem envolver tags HTML.
* Uso de notações com @.
* Primeira linha até o ponto final é uma visão geral sem detalhes. Restante pode haver mais explicações.

## Notações

* `@param:` faz para cada parâmetro.
* `@throws:` quando é lançado uma exceção, define para cada Exception.
* `@return:` lista com as possibilidades de retorno.

## Uso

Usar em um terminal "`javadoc *.java`" vai gerar um site (inclui arquivos HTML, CSS e JS) com a documentação definida nos comentários no código. Vai mostrar todos os métodos e detalhes inseridos nas anotações. Se esquecer de alguma notação vai gerar a documentação normalmente sem erros, mas ela vai sair deficiente.

