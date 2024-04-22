# RecyclerView

O RecyclerView em si é uma view que contém as visualizações correspondentes e as exibe de forma reciclável, reutilizando a visualização de um elemento que estava na tela que deixou de aparecer. Sua implementação se dá com várias classes trabalhando juntas.

{% hint style="info" %}
**ViewGroup** é uma view de layout, assim como o LinearLayout.
{% endhint %}

## Classes que trabalham juntas

O RecyclerView é colocado no layout da mesma maneira que colocaria outro componente, como um botão ou um texto. RecyclerView é um ViewGroup, mas que contém as views a serem exibidas.

Cada item na lista tem um <mark style="color:blue;">ViewHolder</mark> associado a ele. Um ViewHolder é uma classe responsável por manter uma referência às Views individuais dentro de uma lista e evitar a necessidade de procurá-las repetidamente durante a rolagem da lista. Isso ocorre através de um objeto do tipo ViewHolder anexado à tag do item da lista. Também chamamos ele de embrulho por conter o layout desses itens.

Então, como dito acima, cada item da lista possui um ViewHolder anexado a ele. Quando o ViewHolder é criado, ele ainda não contém dados. Após a criação, o RecyclerView conecta o ViewHolder aos dados.&#x20;

O RecyclerView vai solicitando as views e as vinculando aos seus dados, tudo isso usando métodos através do <mark style="color:blue;">adaptador</mark>. Um adaptador cria objetos do tipo ViewHolder conforme necessário e vai definindo dados para as views.

Uma classe chamada LayoutManager que organiza as views e basta usar algum dos 3 gerenciadores de layout fornecidos pelo RecyclerView:

* [`LinearLayoutManager`](https://developer.android.com/reference/androidx/recyclerview/widget/LinearLayoutManager?hl=pt-br) organiza os itens em uma lista unidimensional.
* [`GridLayoutManager`](https://developer.android.com/reference/androidx/recyclerview/widget/GridLayoutManager?hl=pt-br) organiza os itens em uma grade bidimensional:
* [`StaggeredGridLayoutManager`](https://developer.android.com/reference/androidx/recyclerview/widget/StaggeredGridLayoutManager?hl=pt-br) é semelhante a `GridLayoutManager`, mas não exige que os itens de uma linha tenham a mesma altura ou largura

## Implementação

É necessário fazer a implementação do Adapter e do ViewHolder (classes).&#x20;

#### Passo 1: criar uma classe para o adaptador

Isso para ele receber um conjunto de dados (no parâmetro do construtor).

```kotlin
class CustomAdapter(private val dataSet: Array<String>) :
    RecyclerView.Adapter<CustomAdapter.ViewHolder>() {
     
    // ...   
}
```

#### Passo 2: criar a classe ViewHolder

Ela será responsável por manter uma referência à visão de cada item na lista. Todo código a partir de agora é dentro da classe CustomAdapter que criamos acima. Como essa classe é interna, ela vai estender de RecyclerView.ViewHolder.

```kotlin
class ViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val textView: TextView

        init {
            // Define click listener for the ViewHolder's View
            textView = view.findViewById(R.id.textView)
        }
}
```

#### Passo 3: criar as views

Invocado pelo gerenciador de layout e substituindo o conteúdo. O resultado da implementação de um RecyclerView fica:

```kotlin
class CustomAdapter(private val dataSet: Array<String>) :
        RecyclerView.Adapter<CustomAdapter.ViewHolder>() {

    class ViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val textView: TextView

        init {
            // Define click listener for the ViewHolder's View
            textView = view.findViewById(R.id.textView)
        }
    }

    // Create new views (invoked by the layout manager)
    override fun onCreateViewHolder(viewGroup: ViewGroup, viewType: Int): ViewHolder {
        // Create a new view, which defines the UI of the list item
        val view = LayoutInflater.from(viewGroup.context)
                .inflate(R.layout.text_row_item, viewGroup, false)

        return ViewHolder(view)
    }

    // Replace the contents of a view (invoked by the layout manager)
    override fun onBindViewHolder(viewHolder: ViewHolder, position: Int) {

        // Get element from your dataset at this position and replace the
        // contents of the view with that element
        viewHolder.textView.text = dataSet[position]
    }

    // Return the size of your dataset (invoked by the layout manager)
    override fun getItemCount() = dataSet.size

}

```
