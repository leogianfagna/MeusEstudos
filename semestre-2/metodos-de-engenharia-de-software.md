# Métodos de Engenharia de Software

## Conceitos anteriores - revisão&#x20;

Revisão de conceitos aprendidos no semestre passado.&#x20;

### Scrum&#x20;

Conceito que veio do Rugby, é uma estrutura ágil de gestão de projetos que gerencia o trabalho por meio de valores, princípios e práticas.&#x20;

Valores são: pessoas e interações em vez de processos e ferramentas, software funcional em vez de documentação abrangente, mais colaboração com o cliente que negociação de contrato e resposta a mudanças ao invés de planos a serem seguidos.&#x20;

### Requisitos funcionais e não funcionais&#x20;

A grosso modo, os requisitos funcionais são uma funcionalidade específica que o sistema deve ter enquanto os não funcionais referem-se as características ou qualidades do sistema (desempenho, segurança, facilidade, entre outros).&#x20;

* Funcionais: o que será feito&#x20;
* Necessidades atendidas pelo software:&#x20;
* Inserir dados em um formulário&#x20;
* Realizar compras&#x20;
* Comunicar-se com um atendente&#x20;
* Não funcionais: como serão feitos&#x20;
* Tipo de sistema operacional&#x20;
* Hardware a ser utilizado&#x20;
* Banco de dados&#x20;
* Requisitos&#x20;

### Regras de negócios&#x20;

A regra de negócio traduz uma necessidade do negócio - como validações, restrições e etc - em regras lógicas, permitindo que desenvolvimento, produto e negócio de uma empresa se alinhem com relação a estas necessidades, se guiem por elas e apliquem as regras da forma mais clara possível, fazendo com que o desenvolvimento e o crescimento do produto possam fluir da melhor forma.&#x20;

As regras ajudam empresas a expressarem os objetivos, determinações, limitações e procedimentos de seus produtos de forma clara, tanto para quem trabalha no desenvolvimento do produto quanto para quem o utiliza. É comum o foco em partes do negócio que precisam de regras claras, como por exemplo, controle de acesso, cálculos e valores e políticas internas do produto, especialmente quando há legislação envolvida - como um cálculo de valor de imposto sobre um produto.&#x20;

Uma regra, por definição, deve ser sucinta, direta e compreensível, lidando apenas com um aspecto ou atividade do negócio e definindo procedimentos para cada um destes aspectos ou atividades. Por exemplo, da mesma forma que podemos pensar um programa como uma série de decisões feitas através de código, a atividade de um negócio também pode ser pensada da mesma forma.&#x20;

&#x20;

## Planejamento&#x20;

Sempre iniciamos com um planejamento, que é uma entrevista ao cliente e requisitos. Esse planejamento não é relacionado aos detalhes do software e sim, entender o escopo do problema.&#x20;

Há de entender a ideia da empresa e avaliar os riscos desse software. Dependendo do software, um possível bug tem graus do quão prejudicial pode ser e, por conta disso, deve-se ser feito uma análise de risco para justificar pedidos de segurança, valor, entre outros.&#x20;

São exemplos de softwares de alto risco: banco de dados de contas bancárias, máquinas hospitalares, piloto automático, software de freio ABS, etc.&#x20;

### Primeiro exemplo de entrevista e busca ao cliente&#x20;

Em um exemplo hipotético, o cliente pede:&#x20;

* Objetivo do software (ex: cadastrar contatos telefônicos)&#x20;
* Prazo de entrega&#x20;
* Plataforma utilizada (ex: WEB, precisa ter acesso em tempo real)&#x20;
* Restrições (ex: uso restrito em algumas áreas da empresa. Mesmo sendo da parte de requisitos, nesse caso, perguntar dados válidos)&#x20;
* Interface (amigável e responsivo)&#x20;
* Métodos de segurança (vai exigir segurança? Como criptografia, níveis de acesso)&#x20;
* Manutenção (ex: poder fornecer equipe em casos de problemas de acesso)&#x20;
* Sistema de acesso (features como login, senha, verificação em 2 etapas, biometria, token, etc)&#x20;
* Orçamento&#x20;
* Comunicação (ex: equipamentos, seguranças, regras de desligamento contratual, canal de comunicação privado cliente e fornecedor)&#x20;
* Integração (software de manutenção, compras, operação, emergência) &#x20;
