# Anotações

* Pode haver mais de um construtor e cada um deles é usado baseado nos parâmetros fornecidos.
* Usar apenas `this()` faz chamar o construtor da própria classe. Pode incluir parâmetros se o construtor aceitar. Isso também permite um construtor chamar o outro:

```java
protected Figura() {
    this Figura(Color.BLACK); // Chama o construtor abaixo
}

protected Figura(Color color) {
    this.color = color;
}
```
