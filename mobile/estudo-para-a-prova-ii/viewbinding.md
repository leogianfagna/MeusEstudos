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

4. No método `onCreate()`, Transmita a visualização raiz para [`setContentView()`](https://developer.android.com/reference/kotlin/android/app/Activity?hl=pt-br#setcontentview\_1) para torná-la a visualização ativa na tela.

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

A instância de uma classe de vinculação contém referências diretas a todas as visualizações que têm um ID no layout correspondente.

