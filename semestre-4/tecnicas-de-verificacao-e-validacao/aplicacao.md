# Aplicação

A aplicação do teste é seguir o [protocolo de teste](protocolos.md) criado na etapa anterior. O preenchimento do relatório deve ser feito de forma precisa, explícita, objetiva, clara e compreensível.

## Preenchimento dos campos

Os preenchimentos dos campos do cabeçalho seguem [exatamente os mesmos](protocolos.md#preenchimento-dos-campos) feitos no protocolo.

## Campo principal

Esse campo segue a linha de implementação que foi colocada no protocolo. Em exemplos visto em sala, repete todo o protocolo (não limpa a folha, e sim continua preenchendo mais abaixo). O que for definido a seguir será o que aparecerá de novo.

### 1. Valores de entrada

Começa informando quais serão os dados de entrada escolhidos para aquele teste (alguma das linhas do Dataset do protocolo).

### 2. Fluxo de execução

O fluxo descrito sobre como testar o software é seguido passo a passo, numerando cada etapa exatamente como está no teste. Essa parte exige:

* Print de cada passo com indicações de onde está sendo clicado.
* Escritas descritivas do que está acontecendo na tela.
* Cada alteração na tela (mesmo que mínima), é retirado print e descrito exatamente o que mudou minuciosamente.
* Validação dos resultados: A última etapa é a validação e aqui precisa escrever exatamente o que foi retornado e se o que aconteceu condiz com o fluxo GFC previsto.

## Observações

Aqui as observações são mais completas em comparação ao protocolo. Pode-se repetir os valores usados no teste, seguindo com informações relevantes e observações do que foi enfrentado no meio do teste (por exemplo, "etapa 7" ocorreu isso de diferente). Também pode-se observar erros de português ou outros aspectos.

É obrigatório informar no campo de observações:

* **Casas decimais:** se foi previsto quantas deveriam ser retornadas e quantas foi usadas na inserção.
* **Fluxo GFC:** Se seguiu o fluxo corretamente.
* **Retorno:** Informar o retorno e se ele condiz com a realidade.
* **Resultado:** Se o teste foi um sucesso dado o que era previsto.

## Caixa preta

A realização de teste para caixa preta não muda muito, continua sendo a respeito de seguir o protocolo. Contudo, as observações não vão incluir sobre fluxos e apenas se o teste condiz com o objetivo: se o teste foi válido ou não válido.
