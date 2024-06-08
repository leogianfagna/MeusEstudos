# AlertDialog

É um popup que aparece para o usuário. Ele pode ser apenas um aviso e o usuário clicar para fora dele para esconder ou pode ser usado para telas de confirmação, <mark style="color:blue;">**podemos adicionar diversos botões que quisermos**</mark>. Nesse caso, fiz um dessa forma:

<figure><img src="../../../../.gitbook/assets/image (1).png" alt=""><figcaption></figcaption></figure>

## Usando o padrão do próprio Android

Não possui estilos customizados que nem acima. Apenas a tela com os botões. Para isso, basta implementar essa função:

```kotlin
// Exemplo que usa dois botões, um "Sim" e um "Não"

private fun showAlertDialog() {
    val builder = AlertDialog.Builder(this)
    builder.setMessage("Deseja mesmo cancelar a locação?")
        .setPositiveButton("Sim") { dialog, id ->
            // Fazer alguma coisa, tipo chamar uma função
        }
        .setNegativeButton("Não") { dialog, id ->
            // Fazer alguma coisa, tipo chamar uma função
        }
    builder.create().show()
}
```

Depois, basta chamar essa função para aparecer o alerta, pode deixar em um método setOnClickListener, tanto faz!

## Customizando estilos

O estilo pode ser altamente customizável, para isso, criamos <mark style="color:blue;">**arquivos de layout**</mark>. Usaremos esses arquivos para criar o estilo do nosso AlertDialog. No exemplo acima, criei esse estilo:

```xml
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="wrap_content"
    android:layout_height="wrap_content"
    android:orientation="vertical"
    android:padding="16dp"
    android:background="#E8F3FF">

    <TextView
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:text="Deseja mesmo cancelar a locação?"
        android:gravity="center"
        style="@style/subTitle" />

    <!-- View dos botões -->
    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:orientation="horizontal"
        android:layout_marginTop="16dp"
        android:gravity="center">

        <Button
            android:id="@+id/btnSim"
            android:layout_width="132dp"
            android:layout_height="51dp"
            android:text="Sim"
            android:layout_marginEnd="8dp"
            style="@style/btnPrimary" />

        <Button
            android:id="@+id/btnNao"
            android:layout_width="132dp"
            android:layout_height="51dp"
            android:text="Não"
            style="@style/btnPrimary" />

    </LinearLayout>
    
</LinearLayout>
```

Podemos nomear com qualquer nome, esse nome será inserido no método para inflar e chamar o alerta. Depois, é só criar a função do alerta usando o seguinte código:

```kotlin
private fun showAlertDialog() {
    // Substituir o nome do arquivo nessa linha
    val dialogView = LayoutInflater.from(this).inflate(R.layout.<<ARQUIVO DE ESTILO AQUI>>, null)

    val alertDialog = AlertDialog.Builder(this)
        .setView(dialogView)
        .create()

    dialogView.findViewById<Button>(R.id.btnSim).setOnClickListener {
        // Fazer alguma coisa
        alertDialog.dismiss()
    }

    dialogView.findViewById<Button>(R.id.btnNao).setOnClickListener {
        // Fazer outra coisa
        alertDialog.dismiss()
    }

    alertDialog.show()
}
```

Reparar que, agora que possui um layout, cada view (ou botão) foi instanciada com o ID dela para que possamos clicar e funcionar. Então, lembrar de instanciar cada botão e fazer as coisas que precisam quando sucesso!
