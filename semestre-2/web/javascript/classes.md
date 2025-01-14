# Classes

Javascript também é orientado a objetos então possuem classes e instanciações. É muito parecido com [classes em Java](../../../semestre-4/programacao-orientada-a-objetos/estrutura/classes.md), estudado no semestre 4.

## Exemplo prático

Existem algumas diferenças se comparados com uma classe em Java:

* Várias classes podem ser criadas em um único arquivo de Javascript.
* Métodos dentro das classes não precisam da palavra `function` antes delas.
* O construtor é feito através de um método chamado no início `constructor()`.
* Não é necessário declarar as variáveis antes, o `this.nomeVariavel` já faz isso. Essas variáveis são mutáveis então podem ser alteradas com setters.

```javascript
class Product {
    constructor(name, price) {
        this.name = name;
        this.price = price;
    }

    testarClasse() {
        console.log("Nome: " + this.name);
    }
}

const teste = new Product("Qualquer nome", 100);
teste.testarClasse();
```

## Heranças

As classes também podem ser herdadas de outra, usando a palavra `extends`. Essa forma de [herança](../../../semestre-4/programacao-orientada-a-objetos/pilares/heranca.md) ocorre da mesma forma em Java.

```javascript
class ProductAttributes extends Product {
    constructor(name, price, color) {
        super(name, price);
        this.color = color;
    }

    showColors() {
        this.color.forEach(element => {
            console.log(element);
        });
    }
}
const novoProduto = new ProductAttributes("Chapéu", 49.90, ["Preto", "Cinza", "Branco"]);
console.log(novoProduto);
```
