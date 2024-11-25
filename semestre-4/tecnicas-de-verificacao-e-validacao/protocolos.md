# Protocolos

O protocolo consiste na montagem dos testes em uma folha preparada. Essa folha deve preencher todos os campos.

Vimos na etapa sobre [Fluxos de GFC](etapas.md#fluxos-do-gfc) em que um diagrama gera vários possíveis caminhos. O correto a ser feito em um exercício completo é criar um protocolo de teste para cada fluxo possível. Se um GFC gerou 6 fluxos, teríamos então seis protocolos de teste.

## Preenchimento dos campos

<table><thead><tr><th width="178">Campo</th><th>O que fazer</th><th>Exemplo</th></tr></thead><tbody><tr><td>Nome do teste</td><td>Colocar o que vai ser testado naquele teste especificamente.</td><td>"Cálculo de notas não válidas".</td></tr><tr><td>Número</td><td>Colocar uma numeração que achar justa.</td><td>"001".</td></tr><tr><td>Responsável</td><td>Será a pessoa que vai realizar o teste usando aquele protocolo de base.</td><td>O nome da pessoa ou o seu próprio caso seja você.</td></tr><tr><td>Módulo</td><td>O nome da função testada com os parâmetros.</td><td>"def calculo(soma1, soma2)".</td></tr><tr><td>Objetivos</td><td>Descreve exatamente como o programa deve passar pelo fluxo GFC escolhido para o protocolo.</td><td>"Os objetivos deste teste são verificar o comportamento do software com valores de entrada que devem resultar na reprovação do aluno mas funcionamento correto do software."</td></tr><tr><td>Data de criação e alteração</td><td>Colocar a data que você trabalhou no protocolo nos <strong>dois</strong> campos.</td><td>"24/11/2024".</td></tr><tr><td>Responsável (na parte de criação e alteração)</td><td>O nome da pessoa que fez o testou ou alterou.</td><td>O seu próprio nome.</td></tr><tr><td>Descrição</td><td>Mostrado a seguir</td><td>Mostrado a seguir.</td></tr><tr><td>Observações</td><td>Mostrado a segu</td><td>Mostrado a segu</td></tr></tbody></table>

## Campo principal

Esse campo vai introduzir alguns dos elementos feitos nas [etapas](etapas.md), que ficam fora da folha do protocolo.&#x20;

### 1. Descrição

Escreve levemente sobre o [que se trata](#user-content-fn-1)[^1] e depois descreve com mais detalhes o objetivo, que seria o fluxo GFC escolhido. Precisa escrever sobre os valores típicos: se eles são válidos, qual dos valores típicos escolhidos vai resultar em um fluxo diferente, qual o objetivo desses valores e coisas desse tipo.

> Exemplo rápido: Teste para intervalo de valores de salário com valores não válidos. Espera execução completa do código e retorno: { -1, "FORA DO INTERVALO" }.

### 2. Dataset

O Dataset com todas as opções de valores que resultam no fluxo escolhido para o protocolo deve ser inserido. Ou seja, é inserido uma tabela inteira onde, qualquer linha escolhida, vai resultar onde queremos chegar.

### 3. Fluxo GFC

Uma imagem do diagrama GFC com o fluxo destacado, assim como o código com as linhas numeradas para melhor visualização. Adicionar um sub-título como "Fluxo do programa esperado" adicionando abaixo o [número do caminho](#user-content-fn-2)[^2].

### 4. Aplicação do teste

Criar um novo sub-título "Aplicação do teste" ou "Fluxo de execução do teste" que vai conter tópicos separados mostrando o passo a passo de como a pessoa deve executar o teste. Cada item é muito bem definido e explicado, não deixando dúvidas e bem coeso. Siga o exemplo:

* Explicação detalhada de como subir o código para o sistema que será utilizado. Aqui precisa mencionar o uso do Debug e também de como ativá-lo e começar a usar.
* Explicação de como executar o código.
* Explicação de inserção de dados. Aqui precisa fazer **um item para cada dado a ser inserido**, escrevendo algo simples como: "Digitar o salário bruto".&#x20;
* "Efetuar a chamada do código para teste. Efetuar a passagem dos dados por valor."
* "Acompanhar o fluxo de execução do código \<nome do método aqui> linha por linha, comparando com o fluxo GFC informado no protocolo."
* "Validar os resultados de saída e observações do software."

## Observações

Aqui as observações são mais simples e diretas, indicando algo que realmente precisa dizer. Um exemplo, pode informar nas observações algo relacionado á necessidade de aplicar um teste para cada linha do dataset.

## Caixa preta

Acima vimos como fazer o preenchimento do protocolo, mas vimos que a escolha do Dataset e a quantidade de protocolos é baseado no fluxo GFC. O caso de testes de caixa preto não existem fluxos GFC pois não há acesso ao código.

Portanto, quando o teste é baseado em caixa preta temos algumas mudanças:

* São apenas dois protocolos sempre: um para dados válidos e outro para não válidos.
* O Dataset fica maior pois não precisa remover linhas por causa dos fluxos.
* Adaptar a descrição e as instruções de fotos, já que não teremos mais a possibilidade de seguir "linha por linha".

De fato, passa a ser um protocolo de teste um pouco menor.

[^1]: Uma contextualização de como funciona um teste, por exemplo: "O teste de caixa branca vai consistir em executar o código fornecido pelo desenvolvedor, usando o compilador...".

[^2]: Aquele resultado gerado como: 1 2 ND 4 5 ND FIM.
