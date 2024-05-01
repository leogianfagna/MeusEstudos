---
description: De uma activity.
---

# Estrutura layout

A estrutura layout de uma activity está em um arquivo XML (arquivo de marcação) que definem uma interface. Ela é composta:

1. Raíz do layout: define o tipo de layout (como LinearLayout)
2. As views: são elementos de interface
3. Atributos: controlar posicionamento e comportamentos das views
4. Identificadores: com ID, usados para usar de referência nos códigos em Kotlin

Todos esses elementos são organizados de uma forma de hierarquia onde um é composto de outros que é composto e outros e sucessivamente, formando uma hierarquia entre eles.



## Criação da estrutura

Lembrar de saber escrever essa estrutura abaixo!

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.appcompat.widget.LinearLayoutCompat
    xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    android:id="@+id/main"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    app:constraint_referenced_ids="main"
    tools:context=".TesteLayout">
    
    <!-- Toda a estrutura aqui -->
    
</androidx.appcompat.widget.LinearLayoutCompat>
```

As marcações xmlns são "namespaces". Os namespaces são usados para definir e identificar elementos e atributos específicos dentro do documento XML. Eles ajudam a organizar e distinguir os diferentes tipos de recursos e configurações que estão sendo definidos no arquivo.&#x20;

Esses namespaces, em tese, são necessários pois eles fazem muitas <mark style="color:green;">referências necessárias</mark> para o funcionamento. Por exemplo, essas referências necessárias levam para definir os atributos em uso, tais como:&#x20;

<figure><img src="../../.gitbook/assets/namespaces em xml layouts.png" alt=""><figcaption></figcaption></figure>

Então, sem essa referência, esses elementos não funcionariam. A declaração delas não funciona como se fossem como uma biblioteca, mas sim, como são definidos e como eles devem ser interpretados. Essa primeira declaração já é necessária para todo o layout, já que, como é feita na raíz, todo o restante é herdado.



## Gerenciadores de layout

Eles são basicamente organizadores de views e existem diversos no Android. Podemos citar:

* LinearLayout: organiza as visualizações em uma única linha ou coluna, simples e eficiente.
* RelativeLayout: as visualizações são organizadas baseadas no espaçamento entre elas mesmas ou em relação aos limites do layout pai. Útil quando as visualizações precisam estar posicionadas baseadas em regras.
* ConstraintLayout: permite flexibilidade e responsividade, é poderoso e permite criar layouts complexos, úteis e eficientes

Na hora de usar um desses gerenciadores, podemos utilizar uma versão chamada <mark style="color:purple;">`Compat`</mark>, ficando da seguinte forma: <mark style="color:purple;">`LinearLayoutCompat`</mark>.&#x20;

Ela é basicamente uma classe que está na biblioteca do AndroidX que é semelhante à classe antiga (a LinearLayout padrão), mas com adições e que sejam compatíveis com as versões antigas do Android. Ou seja, utilizar uma versão dessa implica em ter compatibilidade com outras versões de celulares.



## A biblioteca AppCompat

É muito importante entender essa biblioteca para entender todas as views que veremos. Essa biblioteca extende das classes nativas do Android que servem para implementar as views que possam ser compatíveis também com as versões antigas do Android. Por isso, o nome de algumas views podem ser mais extensas que o normal, por conta do nome dessa biblioteca.

Uma view comum de texto pode ser escrita da seguinte forma:

```xml
<TextView
        android:layout_width="match_parent"
        android:layout_height="match_parent"
        android:text="Texto aqui" />
```

Mas usando a biblioteca, o que fica bem parecido, a marcação pai passa a ser dessa forma:

```xml
<androidx.appcompat.widget.AppCompatTextView
        android:layout_width="match_parent"
        android:layout_height="match_parent"
        android:text="Texto aqui" />
```

## Views comuns

As views mais comuns e básicas e como implementar:

### Caixa de texto

Pode ser usada pelo <mark style="color:green;">textView</mark> ou a versão compatível <mark style="color:green;">AppCompatTextView</mark>.

```xml
<androidx.appcompat.widget.AppCompatTextView
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:text="Qualquer coisa"
        android:textSize="30sp"
        android:textAllCaps="true"
        android:fontFamily="sans-serif-condensed-medium"
        android:textColor="@color/black"
        android:lineHeight="30dp" />
```

### Inserir ou editar texto

Usado para preenchimento de dados, usado com <mark style="color:green;">editText</mark> ou <mark style="color:green;">AppCombatEditText</mark>. Utiliza-se do atributo <mark style="color:blue;">hint</mark> ao invés do text.

```xml
<androidx.appcompat.widget.AppCompatEditText
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:hint="Teste"
        android:textColorHint="@color/black"
        android:textSize="35sp"
        android:fontFamily="sans-serif-condensed-medium"
        android:background="@color/cardview_light_background"
        android:padding="15dp" />
```

### Botões

Pode ser usada pelo <mark style="color:green;">Button</mark> ou a versão compatível <mark style="color:green;">AppCompatButton</mark>.

```xml
    <androidx.appcompat.widget.AppCompatButton
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Clique aqui"
        android:textColor="@color/white"
        android:textAllCaps="false"
        android:textSize="35dp"
        android:background="@color/black"
        android:padding="10dp" />
```



## Atributos comuns

Os atributos são aqueles especificados dentro de uma view. Cada View possui seu atributo e eles serão diferentes se ela será uma View de layout ou apenas um componente.

### Atributos de componentes

São eles, os atributos comuns para textos:

1. `android:text`: Define o texto exibido pela view de texto.
2. `android:textSize`: Define o tamanho do texto.
3. `android:textColor`: Define a cor do texto.
4. `android:textStyle`: Define o estilo do texto (normal, negrito, itálico, etc.).
5. `android:textAlignment`: Define o alinhamento do texto (esquerda, direita, centro, justificado).
6. `android:hint`: Define um texto de dica que desaparece quando o texto é inserido.
7. `android:inputType`: Define o <mark style="color:red;">tipo de entrada</mark> (texto, número, senha, etc.) para `EditText`.
8. `android:maxLength`: Define o número máximo de caracteres permitidos em um `EditText`.
9. `android:lines` / `android:maxLines`: Define o número de linhas exibidas em um `EditText` ou `TextView`.
10. `android:ellipsize`: Define como o texto é truncado quando não cabe na view.

O <mark style="color:purple;">`inputType`</mark> pode ter vários tipos de dados inseridos, como datas, números (especificando entre decimais, inteiros, etc), texto, telefone, E também temos para botões:

1. `android:text`: Define o texto exibido pelo botão.
2. `android:background`: Define o fundo do botão.
3. `android:textColor`: Define a cor do texto do botão.
4. `android:onClick`: Define o método a ser chamado quando o botão é clicado.
5. `android:enabled`: Define se o botão está habilitado ou não.
6. `android:drawableStart` / `android:drawableEnd`: Define os drawables (ícones) exibidos ao lado do texto.
7. `android:padding`: Define o preenchimento interno do botão.

### Atributos de layout

1. `android:layout_width`: Define a largura da view.
2. `android:layout_height`: Define a altura da view.
3. `android:layout_gravity`: Define o alinhamento da view dentro de seu contêiner pai.
4. `android:layout_weight`: Define como a view deve ser dimensionada em um layout ponderado (usa-se nas views de componentes)
5. `android:layout_margin`: Define as margens em torno da view.
6. `android:orientation`: Define a orientação do layout (`horizontal` ou `vertical` para `LinearLayout`).
