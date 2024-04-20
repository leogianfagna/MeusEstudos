# ViewBinding

É uma funcionalidade introduzida pelo Android que <mark style="color:blue;">instancia todos os elementos da view</mark>, ou seja, tem como objetivo <mark style="color:green;">gerar automaticamente</mark> os elementos da interface do usuário declarados no arquivo XML. Esse recurso substitui o uso excessivo de `findViewById()`, que era inserido repetidamente para cada view que a interface havia.

Isso é possível pois essas instanciações contém referências diretas para cada view de cada arquivo de layout, que possuem um ID.

## Como habilitar o ViewBinding em um projeto

Para usar, há a necessidade de especificar no Gradle para que o Android entenda como gerenciar e compilar os recursos do projeto. Para isso, a informação é inserida no arquivo build.gradle:

<pre class="language-gradle"><code class="lang-gradle"><strong>android {
</strong>    ...
    buildFeatures {
        viewBinding = true
    }
}
</code></pre>

Depois disso, necessita executar um build no projeto para ser gerado as classes que faça essa funcionalidade, cada arquivo de layout vai receber a sua classe. O nome da classe de cada arquivo é convertido para o padrão PascalCase e acrescentado a palavra Binding no final. Então por exemplo:

> main\_activity.xml -> MainActivityBinding



## Como utilizar

Para funcionar corretamente, todas as views criadas no arquivo .xml devem conter o ID. O ViewBinding funciona referênciando apenas para aquelas que possuem um ID. Por exemplo:

```xml
<LinearLayout ... >
    <!-- Serão adicionadas pelo View Binding-->
    <TextView android:id="@+id/name" />
    <Button android:id="@+id/button"
        android:background="@drawable/rounded_button" />
        
    <!-- Não será adicionada pelo View Binding pois não possui um ID -->
    <ImageView android:cropToPadding="true" /> 
    
</LinearLayout>
```

Cada classe gerada para cada arquivo de layout possui um método chamado `getRoot()` que fornece uma referência raiz do arquivo de layout. A partir disso, deve fazer (esse método é exclusivo para as activitys):

1. No método `onCreate()`, criar uma instância da classe de vinculação gerada para o layout que será usada para acessar todas as visualizações definidas no layout

```kotlin
// ActivityCadastroBinding é o nome da classe gerada (lembrar do PascalCase!)
private lateinit var binding: ActivityCadastroBinding
```

2. No método `onCreate()`, chamar o método `inflate()` que está incluído na classe que foi gerada para o ViewBinding. Isso cria uma nova instância da classe para a activity usar. Inflar o layout significa transformar um arquivo de layout XML em uma hierarquia de visualização:

```kotlin
binding = ResultProfileBinding.inflate(layoutInflater)
```

3. No método `onCreate()`, receba uma referência à visualização raiz chamando o método `getRoot()` ou da forma a seguir:

```kotlin
val view = binding.root
```

4. No método `onCreate()`, transmita a visualização raiz para [`setContentView()`](https://developer.android.com/reference/kotlin/android/app/Activity?hl=pt-br#setcontentview\_1) para torná-la a visualização ativa na tela.

```kotlin
setContentView(view)
```

Apenas com esse código, <mark style="color:green;">está completo</mark> o uso do ViewBinding! Todas as views já estarão na tela aparecendo conforme está no layout.

Algumas views são esperadas que sejam utilizadas, seja como eventos, cliques, entre outras opções. Para isso, é necessário usar a instância da classe para referenciar qualquer view e fazer a utilização.

```kotlin
binding.name.text = viewModel.name
binding.button.setOnClickListener { viewModel.userClicked() }
```

Em um exemplo prático final, temos:

```kotlin
class LoginActivity : AppCompatActivity() {
    
    // Criação da variável Bindin (passo 1)
    private lateinit var binding: ActivityLoginBinding
    
    // Função já criada pelo Android Studio
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        
        // Passos 2, 3 e 4
        binding = ActivityLoginBinding.inflate(layoutInflater)
        val view = binding.root
        setContentView(view)
        
        // Criando uma funcionalidade para o botão
        // cadastroTenhoOutraConta = id no layout!
        binding.cadastroTenhoOutraConta.setOnClickListener {
            val i = Intent(this, InicioActivity::class.java)
            startActivity(i)
            finish()
        }
    }
}
```

## A implementação sem o uso do ViewBinding

A instância de uma classe de vinculação contém referências diretas a <mark style="color:purple;">todas as visualizações</mark> que têm um ID no layout correspondente. Sem o uso dele, é necessário referenciar todas, uma por uma.

### Sem usar ViewBinding

Instância cada elemento da View e depois, utilizando a classe R (classe do Android Studio que possui referência para todas as views do arquivo de layout), utiliza a instância para cada elemento da View.&#x20;

```kotlin
class InicioActivity : AppCompatActivity() {

    private lateinit var btnCadastro: Button
    private lateinit var btnLogar: Button

    override fun onCreate(savedInstanceState: Bundle?) {
        // ...

        btnCadastro = findViewById(R.id.btnCadastro)
        btnLogar = findViewById(R.id.btnLogar)

        btnCadastro.setOnClickListener {
        // ...
        }
    }
}
```

### Utilizando ViewBinding

Uma instância para o binding, inflar o layout receber referência e transmití-la.

```kotlin
class InicioActivity : AppCompatActivity() {

    private lateinit var binding: ActivityInicioBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        // ...
        binding = ResultProfileBinding.inflate(layoutInflater)
        val view = binding.root
        setContentView(view)


        binding.btnCadastro.setOnClickListener {
        // ...
        }
    }
}
```



## Como não se deve utilizar o ViewBinding

É muito importante não cometer erros na utilização do ViewBinding e da forma que ele funciona. Não se deve fazer:

1. **Ignorar seu ciclo de vida**: ele deve ser declarado dentro do método onCreate()
2. **Vinculação excessiva**: a utilização do ViewBinding é feita para evitar isso
3. **Não liberar memória**: deve utilizar unbind() ou liberando a variável no método onDestroy()
4. **Não verificar se é nulo**: sempre deve verificar se é nulo antes de utilizá-lo

Além disso, apesar de poderoso, não é recomendado utilizá-lo em algumas ocasiões. São elas e seus respetivos motivos:

1. **Projetos simples:** fica mais fácil usar `findViewById()` ou até mesmo vincular diretamente no XML utilizando `android:onClick`
2. **Aprendizado**: em projetos de aprendizado é melhor utilizar os conceitos básicos para um melhor entendimento
3. **Incompatibilidade** com bibliotecas: alguns projetos podem depender de bibliotecas de terceiros que não são compatíveis com o ViewBinding
4. **Desempenho**: projetos onde cada milisegundo é importante, o uso do ViewBinding, que é otimizado, ainda sim pode ser prejudicial
5. **Frameworks que geram código automaticamente**: muitos deles podem não ser compatíveis com o ViewBinding e usando métodos diretos como o `findViewById()`

## Como desabilitar o ViewBinding

Basicamente, é reverter todas as mudanças feitas para o uso do ViewBinding. A primeira coisa é desabilitar a configuração que permite o uso dele no Gradle, deixando como false. Após isso, remover as classes criadas automaticamente para cada arquivo de layout.

O código utilizando ViewBinding é diferente. Portanto, deve refazer os códigos sem a utilização de suas instanciações. Depois disso, basta recompilar o projeto.

