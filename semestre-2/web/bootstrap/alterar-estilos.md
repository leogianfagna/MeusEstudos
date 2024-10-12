# Alterar estilos

Vamos supor que queremos alterar alguma coisa que foi herdada do estilo criado pelo Boostrap. Para isso, podemos:

* Criar um estilo próprio nosso e alterar as tags que são utilizadas pelo Bootstrap, dando prioridade para o nosso estilo.
* Criar o mesmo nome do estilo do Bootstrap no nosso css, adicionando apenas os elementos a ser alterados, assim como acima.

Para isso funcionar, não precisa de muito. Aparentemente, o navegador dá prioridade para nossos estilos ao invés do Bootstrap, portanto, apenas fazer essas alterações são suficientes.

## Sombreamento de inputs

Por padrão, um input de um form criado pelo Bootstrap fica azul ao redor. Desta forma:

<figure><img src="../../../.gitbook/assets/exemplo de borda padrao bootstrap.png" alt=""><figcaption></figcaption></figure>

Para alterar isso, alteramos o atributo `focus` da classe **form-control** e **form-select**, que são usados para esses inputs (o select é só necessário se usarmos ele). Se tiver outros tipos de forms, basta fazer a mesma coisa para cada um.

Esse caso, estamos alterando essa borda para laranja, com um sombreamento um pouco mais sútil e mais para baixo.

```css
.form-control:focus {
    box-shadow: 0 0.5rem 1rem rgba(214, 73, 18, 0.411);
    border-color: rgb(255, 91, 41);
}

.form-select:focus {
    box-shadow: 0 0.5rem 1rem rgba(214, 73, 18, 0.411);
    border-color: rgb(255, 91, 41);
}
```

<figure><img src="../../../.gitbook/assets/exemplo de borda editada bootstrap.png" alt=""><figcaption></figcaption></figure>

## Cores padrões

O bootstrap disponibiliza cores padrões para serem usadas. Se estamos editando os próprios estilos deles, podemos usar alguma das cores já pré feitas por eles, tais quais:

<figure><img src="../../../.gitbook/assets/cores padroes do bootstrap.png" alt=""><figcaption></figcaption></figure>

Para usar, fazemos a mesma coisa, mas invés de inserir direto a cor, vamos inserir ela como uma <mark style="color:purple;">forma de variável</mark>:

```css
.button {
  background-color: var(--bs-blue);
  color: var(--bs-white);
}
```
