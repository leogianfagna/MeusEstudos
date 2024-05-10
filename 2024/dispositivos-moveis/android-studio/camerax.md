# CameraX

## Implementação

### Preparação

Para começar usar, precisa adicionar as 3 dependências no Gradle do módulo do App.

```groovy
dependencies {
    //Dependência do CAMERAX
    implementation("androidx.camera:camera-view:1.3.3")
    implementation("androidx.camera:camera-lifecycle:1.3.3")
    implementation("androidx.camera:camera-camera2:1.3.3")
}
```

E essas permissões no manifest:

```xml
<!-- Define que o aparelho precisa ter camêra para ser instalado -->
<uses-feature android:name="android.hardware.camera.any"/>

<!-- Defnie a permissão para usar -->
<uses-permission android:name="android.permission.CAMERA"/>
```

O ViewBinding deve estar disponível no projeto.

### Layout

Usaremos o ConstraintLayout e criaremos uma view chamada PreviewView. O modo do ConstraintLayout possui uma diferença em que precisamos definir onde os componentes estarão presentes na tela, algo que era diferente do LinearLayout onde ia encaixando um abaixo do outro. Isso permite que views possam ficar em cima de views.

Iremos criar uma activity chamada CameraPreviewLayout com o seguinte layout:

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout
    xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:id="@+id/main"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".CameraPreviewActivity">

    <!-- Vai ocupar a tela inteira -->
    <androidx.camera.view.PreviewView
        android:id="@+id/cameraPreview"
        android:layout_width="match_parent"
        android:layout_height="match_parent"/>
    
    <!-- Posiciona na parte inferior da tela centralizada -->
    <com.google.android.material.button.MaterialButton
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Tirar foto"
        android:layout_margin="20dp"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintBottom_toBottomOf="parent" />

</androidx.constraintlayout.widget.ConstraintLayout>
```

### Kotlin

Agora as próximas etapas são feitas nas activitys em Kotlin.

#### Iniciar o preview da câmera solicitando permissão

Uma activity irá chamar a activity de preview e nela será perguntado a permissão para usar a câmera. Para isso, criamos uma variável global que é um PROVIDER. Os providers são janelas em Android Studio que solicitam as permissões durante o uso do app para o usuário. Essa instância vai receber o valor de TRUE ou FALSE e assim podemos usar em outros métodos.

```kotlin
private val cameraProviderResult =
    registerForActivityResult(ActivityResultContracts.RequestPermission()) {
        if (it) {
            abrirTelaDePreview()
        } else {
            Snackbar.make(binding.root, 
                "Você não concedeu permissões para usar a câmera", 
                Snackbar.LENGTH_INDEFINITE).show()
        }
    }
```

<mark style="color:purple;">`registerForActivityResult()`</mark> é um método da própria activity que trata o resultado do que ocorreu na solicitação (a tela que apareceu para o usuário). O it é o que vem através do lambda, que é basicamente se deu permissão ou não.

A variável está instanciada, mas ainda é preciso lançar ela para solicitar a  permissão. Então, dentro do ciclo de vida da activity, implementamos isso:

```kotlin
// cameraProviderResult é o nome da variável criada anteriormente
cameraProviderResult.launch(android.Manifest.permission.CAMERA)
```

#### Implementação do preview da câmera

Isso é feito na activity de preview da imagem. Começamos declarando uma série de variáveis globais essenciais para funcionar:

```kotlin
class CameraPreviewActivity : AppCompatActivity() {

    private lateinit var binding: ActivityCameraPreviewBinding

    // Controla as instâncias PROVIDER, não deixa abrir mais de uma tela de permissão
    private lateinit var cameraProviderFuture: ListenableFuture<ProcessCameraProvider>

    // Selecionar qual câmera iremos trabalhar
    private lateinit var cameraSelector: CameraSelector

    // Imagem capturada, já nasce como nula
    private var imageCapture: ImageCapture? = null

    // Objeto do android que cria uma thread para gravar a imagem (não
    // podemos usar a mesma thread pois se não pararia o preview)
    private lateinit var imgCaptureExecutor: ExecutorService

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityCameraPreviewBinding.inflate(layoutInflater)
        setContentView(binding.root)

        cameraProviderFuture = ProcessCameraProvider.getInstance(this)
        cameraSelector = CameraSelector.DEFAULT_BACK_CAMERA
        imgCaptureExecutor = Executors.newSingleThreadExecutor()

        startCamera()
    }

    private fun startCamera() {

        cameraProviderFuture.addListener({
            val cameraProvider = cameraProviderFuture.get()
            val preview = Preview.Builder().build().also {
                it.setSurfaceProvider(binding.cameraPreview.surfaceProvider)
            }

            try {
                // Abrir o preview
                cameraProvider.unbindAll()
                cameraProvider.bindToLifecycle(this, cameraSelector, preview)
            } catch (e: Exception) {
                Log.e("Camera Preview", "Falha ao abrir a camera")

            }

        }, ContextCompat.getMainExecutor(this))
    }
}
```

#### Implementação dos métodos para tirar foto

Vamos mudar a função startCamera pois antes ela estava apenas para preview. Essa mudança vai servir para o controlador da câmera entender que ela foi aberta para fazer uma captura de imagem. Para isso, criamos a seguinte variável e depois adicionamos ela no CameraProvider:

```kotlin
// Na função startCamera()
imageCapture = ImageCapture.Builder().build()

cameraProvider.bindToLifecycle(this, cameraSelector, imageCapture)
```

```diff
- cameraProvider.bindToLifecycle(this, cameraSelector, preview)
+ cameraProvider.bindToLifecycle(this, cameraSelector, imageCapture)
```

