# Clean Code

Parte da estrutura de um projeto consiste em seguir o **clean code**.

## Abstração

**Regras de negócios** não devem estar na main ou em outra função, e sim dentro da classe a qual lhe pertence. Se tem uma uma classe chamado triângulo, a regra de cálculo de área (é a sua regra de negócio) deve estar declarado dentro da classe triângulo, e não sendo calculada em outra classe.

## Limite de caractere por linha

É uma técnica clean code limitar no máximo `100` caracteres por linha, quebrando o código em novas linhas caso ultrapasse o limite.
