# SOLID

## Princípio da Substituição de Liskov

Esse princípio diz que uma classe herdada possa ser usada no lugar da classe pai sem que o programa quebre. Ou seja, se eu criar uma classe e outra herdar dela, o comportamento dela deverá ser o mesmo.

Na prática, se temos um método e ele espera um objeto de uma classe, esse princípio garante que poderíamos usar qualquer objeto de qualquer classe herdada sem problemas, exemplo:

```java
// Um método que espera um objeto do tipo DataMiner
void executarMineracao(DataMiner minerador, String caminho) {
    minerador.mine(caminho);
}
```

Vamos supor que temos 3 classes que herdam de DataMiner: `DocDataMiner`, `CSVDataMiner` e `PDFDataMiner`. Com esse princípio bem consolidado, nós poderíamos usar qualquer um dos objetos!

```java
executarMineracao(new DocDataMiner(), "arquivo.doc");
executarMineracao(new CSVDataMiner(), "dados.csv");
executarMineracao(new PDFDataMiner(), "relatorio.pdf");
```

### Exemplo correto

Esse exemplo é um comportamento correto. Veja que instanciamos um objeto do tipo Animal com a classe Cachorro (perceba que deveria ser Animal com Animal). Mesmo assim, o comportamento seguiu conforme esperado.

```java
class Animal {
    void fazerSom() {
        System.out.println("Algum som");
    }
}

class Cachorro extends Animal {
    void fazerSom() {
        System.out.println("Latido");
    }
}
```

```java
Animal meuAnimal = new Cachorro();
meuAnimal.fazerSom(); // "Latido"
```

### Exemplo violado

Isso mostra de forma clara que a classe filho viola o comportamento esperado, alterando altura em um lugar indevido. Se fizéssemos a mesma coisa do exemplo acima, ao utilizar setLargura, iríamos ter um comportamento diferente.

```java
class Retangulo {
    int largura;
    int altura;

    void setLargura(int l) {
        this.largura = l;
    }
    
    void setAltura(int a) {
        altura = a;
    }
}

class Quadrado extends Retangulo {
    void setLargura(int l) {
        largura = l;
        altura = l; // quebra o comportamento esperado
    }
}
```
