# Instância oca

Toda regra tem exceção. Quando a classe não tiver atributos não estatíticos não precisa re-implementar pois esses métodos usam apenas eles.

Uma classe só com atributos e métodos estáticos, usar "new" para ela vai criar uma instância oca. Exemplo classe Math. Para usar uma classe assim, é só usar o nome da classe:

```java
Math.pow()
Math.log()

// A própria classe neste caso é uma instância e deixa de ser o MOLDE.
```

Quando tem uma classe com termos estáticos e não estáticos, ela passa a ser ter um duplo papel: ela é o model e também a instância.
