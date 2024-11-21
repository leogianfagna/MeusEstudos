# Polimorfismo

## Métodos abstratos

São uma ferramenta que fornecem mais recursos quando se trata de polimorfismo pois <mark style="color:blue;">especificam um padrão de comportamento</mark>. Um método abstrato pode ser usado para criar uma estrutura básica para um programa inteiro permitindo ajustar conforme necessário.

Eles são métodos que <mark style="color:blue;">não possuem implementação</mark> e apenas declaração, por exemplo:

> `abstract double calcularArea();`

* Só podem ser colocados em classes abstratas.
* Exigem implementação de quem herdar.
* Usam[^1] a palavra `abstract`.
* Métodos abstratos implementados recomendam o uso de `@Override`.

```java
// Interface que define métodos abstratos
interface Forma {
  abstract double area();
  abstract double perimetro();
}

// Classe que implementa esses métodos
class Quadrado implements Forma {
  double larg, alt;

  Quadrilateral(double l, double a) {
    this.larg = l;
    this.alt = a;
  }

  @Override
  public double perimetro() {
    return ((2 * length) + (2 * width));
  }

  @Override
  public double area() {
    return (length * width);
  }
  
}
```

## Classe abstrata

Uma classe passa a ser considerada abstrata a partir do momento que ela tem a partir de um método abstrato, não necessariamente toda a classe.

[^1]: Pode ser omitido dentro de interfaces.
