---
description: Método clone e o risco de encapsulamento.
---

# Encapsulamento

Como objetos são ponteiros e através deles existe a possibilidade de alterar o valor de um atributo que não deveria ser alterado (como um private), usando o endereço de memória.

#### Exemplo de alteração de um valor ponteiro

Veja abaixo como um valor que é private[^1] pode ser alterado através do ponteiro.

<figure><img src="../../../.gitbook/assets/ferindo encapsulmento.png" alt=""><figcaption></figcaption></figure>

Esse caso é possível porque a classe Data [possui métodos que alteram atributos](#user-content-fn-2)[^2]. Como o parâmetro data é a instância original e não uma cópia, isso significa que todos eles estão compartilhando o mesmo endereço de memória.

Se todos tem o mesmo endereço de memória, se a variável for alterada em qualquer lugar, o novo valor vai valer para todos os outros.

<figure><img src="../../../.gitbook/assets/instancias com mesmo endereco de memoria.png" alt=""><figcaption></figcaption></figure>

### Previnindo o risco no encapsulamento

Não podemos deixar ponteiros para uso (pontas soltas) e por isso, precisamos definir nas variáveis cópias[^3] e não as instâncias originais. A mesma coisa vale para get, sendo que tem que retornar a cópia da cópia para não dar acesso ao ponteiro original.

```java
public void setNascimento(Data n) {
    // Maneira 1: Exige construtor de cópia
    this.nascimento = new Data(n);
    
    // Maneira 2: Exige construtor de cópia
    this.nascimento = (Data)n.clone();
    
    // Maneira 3: Não exige construtor de cópia
    this.nascimento = new Data(n.getDia(), n.getMes(), n.getAno());
}
```

### Quando devemos clonar

É padrão uma classe implementar a interface Cloneable quando ela pode alterar atributos dentro dela. Esse contexto é suficiente para decidirmos se isso pode gerar perigo no encapsulamento ou não, portanto, quando uma classe possui essa interface, devemos nos precaver nesta questão.

Para isso, devemos executar uma verificação de instância para determinar se o objeto é clonável usando o operador `instanceof`:

<pre class="language-java"><code class="lang-java">public void setNascimento(Data n) {
    
<strong>    if (n instanceof Cloneable)
</strong>        this.nascimento = (Data) n.clone();  // Deep copy
    else
        this.nascimento = n;                 // Shallow copy
    
}


public X getElemento(int i) throws Exception {
    
    if (this.elem[i] instanceof Cloneable)
        return (X)this.elem[i].clone();
    else
        return this.elem[i];
    
}
</code></pre>

[^1]: Lembrando que ele só poderia ser alterado usando métodos da classe `CertidaoNascimento`.

[^2]: Como o `setDia()`. Caso não possuísse, não haveria problema pois a variável nascimento não poderia ser alterada externamente.

[^3]: As cópias vão ter endereços de memória diferentes.
