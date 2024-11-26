# Exercícios prova 2

## Gerenciamento de arquivos

#### 1) Defina e diferencie formatação física, particionamento e formatação lógica.

Formatação física é aquela feita pelo fabricante do disco, dividindo o conjunto de cilindros em trilhas e setores fisicamente. Todo esse conjunto faz parte da memória do disco e o particionamento é a divisão dela em partes específicas para que o sistema operacional guarde suas próprias estruturas. A formatação lógica é a que prepara cada particionamento feito organizando os dados.

#### 2) Explique a diferença entre estruturas de diretório em um único nível, em árvore e em grafo. Apenas a estrutura em grafo permite links. Que tipo de considerações adicionais de implementação os links podem trazer?

Estruturas de diretório são uma coleção de dados sobre arquivos que diz como que eles estão salvos e organizados.

* Único nível: mantém todos os arquivos em um único diretório.
* Árvore: permite diversos sub-diretórios organizados hierarquicamente.
* Grafo: segue a lógica da árvore mas permite múltiplos caminhos para o mesmo diretório.

Uma consideração adicional para links é que o mesmo diretório pode estar presente em vários outros. Eles podem causar loops e devem se manter sincronizados com os outros.

#### 3)&#x20;
