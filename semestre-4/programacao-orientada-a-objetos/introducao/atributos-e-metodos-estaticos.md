# Atributos e métodos estáticos

`public` e `private` são chamados de <mark style="color:purple;">qualificadores</mark>, assim como é o `static`. Contudo, essa qualificador neste caso é um a mais para o método e atributo, e não somente o único.

* private: atributo encapsulado, apenas dentro da classe.
* public: desencapsula, acessível em qualquer lugar.

## Objeto chamante

Sempre que há uma chamada de método temos o **chamante**, aquele que está à esquerda do ponto. O chamante nem sempre será um objeto e poderá ser uma classe, por exemplo:

<figure><img src="../../../.gitbook/assets/exemplo de objetos chamantes.png" alt=""><figcaption></figcaption></figure>

Um método que foi criado com static usa a classe como chamante enquanto caso não tenha, usa o objeto. Caso visto na documentação que mostra `static int` na coluna "Modifier and Type".

Por conta disso, o método cujo chamante é um objeto, usa as informações do objeto para sua função/chamada. Vendo os exemplos acima, o método parseInt() foi criado para que tudo que precise para funcionar, estará no parâmetro (é claro, pois não usa objetos). Já os demais, obriga o uso de objetos para chamar os métodos.

**Basicamente**, se um método não precisar de atributos de um objeto para funcionar, ele poderá ser static.

Métodos com qualificadores static não usam "this" dentro deles. Já quando não são static, usam o this para se referenciar ao atributo do objeto chamante. No exemplo da classe teclado, temos:

```java
// Declarando um atributo = nova instância
private static BufferedReader teclado = new BufferedReader(
                                        new InputStreamReader(
                                        System.in));
```

Vemos o static que serve para dizer que o atributo "teclado" pertence à classe e não ao objeto chamante. Em outras palavras, <mark style="color:blue;">usar static em atributos</mark> <mark style="color:blue;">vincula ele à classe</mark>.

> Quando todos os atributos da classe são static chamamos de <mark style="color:purple;">classe não replicável</mark>, o que significa que não criamos instância desta classe em outros códigos.

## Diferenças em exemplo

<figure><img src="../../../.gitbook/assets/exemplo de membros estaticos e não.png" alt=""><figcaption></figcaption></figure>

Neste exemplo prático fica nítido a diferença entre os dois, onde o método estático consegue fazer tudo apenas recebendo um parâmetro enquanto o método não estático tem que usar atributos do objeto (aqueles referenciados como this), por isso, eles devem ser chamados através de instâncias.

### Chamando dentro da própria classe

Uma classe pode chamar um método não estático dentro dela mesma, mas para isso, precisa ter uma instância da classe. Métodos não estáticos estão associados a uma instância da classe, e não à própria classe.

```java
public class Exemplo {

    public void metodoNaoEstatico() {
        fazAlgo();
    }
    
    public static void main(String[] args) {
        // Instância da classe
        Exemplo exemplo = new Exemplo();
        exemplo.metodoNaoEstatico(); // Objeto chamante é um objeto, não pode ser
                                     // a própria classe.
    }
}
```
