# compareTo

Esse método serve para ver se algo é maior, menor ou igual a outra coisa a ser comparada. Sempre quando existir um <mark style="color:blue;">critério de comparação</mark>, devemos implementar o método compareTo(). O método deve retornar -1 ou 1 e esse número será usado em condições if, pela classe que está interessada em saber esse resultado.

Um exemplo de comparação são datas, elas são comparáveis pois existem datas menores ou maiores que as outras. Quando elas são comparáveis, precisamos da <mark style="color:blue;">carteirinha</mark>.

## Carteirinha

Uma carteirinha <mark style="color:green;">afirma algo</mark>. No caso do Java, a carteirinha é a adição da nomenclatura <mark style="color:purple;">**Comparable**</mark> que vai servir para afirmar que é comparável. Sem a "carteirinha", o método comparteTo ainda funciona e pode ser chamado, mas essa classe não será reconhecida como comparável o que pode fazer com que não funcione corretamente para estruturas tipo árvores.

Para entender melhor o que foi dito acima, em exemplos metafóricos, pensar na carteirinha de um estudante. Se o estudante estiver sem a carteirinha ele ainda sim será um estudante (faz coisas de estudantes) mas ele não poderá entrar no cinema.

Implementar a carteirinha e não implementar o método de compareTo vai gerar um erro de compilação.

## Implementação

```java
public class Data implements Comparable<Data> {

    @Override
    public int compareTo(Data d)
    {
        if (this.ano < d.ano) return -1;
        if (this.ano < d.ano) return 1;
        
        if (this.mes < d.mes) return -1;
        if (this.mes < d.mes) return 1;
        
        if (this.dia < d.dia) return -1;
        if (this.dia < d.dia) return 1;
        
        return 0; // Será igual
    }
}
```
