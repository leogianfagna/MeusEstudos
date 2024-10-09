# Atributos de um botão

Para um botão funcionar levando até um href, por exemplo, ele deve usar a tag \<a> ao invés do \<button>. Por conta disso, algumas atribuições são necessárias para que ele fique bonito e funcional, por exemplo:

```css
.botao {
    background-color: #ff7a59;
    color: white;
    padding: 10px 20px;
    border: none;
    border-radius: 4px;
    cursor: pointer;
    text-decoration: none;
}

.botao:hover {
    background-color: #ff5733;
}
```

Um grande foco para:

* **text-decoration:** tira o underline e letra azul criada por ser um link
