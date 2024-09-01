# equals

Se tivermos duas instâncias criadas e tentarmos comparar elas com `i1 == i2` isso não vai funcionar. Isso porque, `i1` e `i2` são referências então este caso está comparando ponteiros (endereços de memória). Sendo instâncias de uma classe com muitos atributos, a forma de comparar se todos atributos são iguais de uma instância para outra é apenas usando o método `equals()`.

Mesmo se tivermos getters para todos os tipos de atributos presentes na classe, o uso deles <mark style="color:red;">não é o padrão</mark>. Contudo, esse método equals também não funciona corretamente herdado de object, portanto, deve ser re-implementado.

```java
@Override
public boolean equals(Object obj) // (1)
{
    if (obj == this) return true; // (2)
    if (obj == null) return false; // (3)
    if (obj.getClass() != this.getClass()) return false;

    Data d = (Data)obj;
    if (d.dia != this.dia) return false;
    if (d.mes != this.mes) return false;
    if (d.ano != this.ano) return false;

    return true;
}
```

Esse código faz diversas comparações entre o parâmetro enviado obj e o objeto da própria classe representado pelo this (lembrar de "estou falando de mim mesmo", a classe que ele está). Algumas observações:

1. O parâmetro equals tem que ser um objeto Object pois ele é herdado assim. Lembrando que tudo é herdado disso então `equals(Object obj)` simplesmente significa que esta classe pode receber tudo.
2. Compara o endereço de memória, pois caso seja equivalente, consequentemente terão todos os mesmos atributos e dados.
3. Como os atributos da classe não podem ser nulos por terem um construtor, se `obj` for igual a nulo consequentemente será diferente de `this` (objetos nulos não conseguem chamar métodos).
