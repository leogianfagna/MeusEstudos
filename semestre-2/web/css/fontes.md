# Adicionando fontes

Para adicionar as fontes manualmente no projeto, precisa instalá-las. Usei o Dafont para instalar fontes e adicionei em uma pasta no diretório raíz, chamado **fonts**:

<figure><img src="../../../.gitbook/assets/estrutura projeto html.png" alt=""><figcaption></figcaption></figure>

Depois, no arquivo de css, definimos a fonte em uma tag chamada @font-face. Vamos definir o nome que queremos para a fonte e importá-la com o caminho que ela está guardada, dessa forma:

```css
@font-face {
    font-family: 'Roboto-Light'; /* Pode ser qualquer nome */
    src: url('/fonts/Roboto-Light.ttf') format('opentype');
    font-weight: normal;
    font-style: normal;
}

@font-face {
    font-family: 'Roboto-Bold';
    src: url('/fonts/Roboto-Bold.ttf') format('opentype');
    font-weight: normal;
    font-style: normal;
}
```

Nesse caso, definimos a fonte Roboto-Bold e Roboto-Light. Depois, basta atribuir essa fonte ainda no CSS para as classes, ids ou tipos que iremos utilizar.

```css
body {
    font-family: 'Roboto-Bold', sans-serif;
    background-color: #f7f9fa;
    margin: 0;
    padding: 0;
}

.fonteFina {
    font-family: 'Roboto-Light', sans-serif;
}
```

Nesse caso:

* A fonte bold está sendo utilizada em todo o BODY do HTML, por inteiro.
* A fonte light está sendo utilizada somente nas tags que estão com a classe chamada fonteFina.
