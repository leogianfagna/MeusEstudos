# Flutter

## Mandamentos do flutter

1. Todo aplicativo Flutter tem um ponto de entrada por uma função main. Nela, é invocada uma outra função chamada runApp que recebe como parâmetro uma instância de uma classe que representa o aplicativo. O corpo dela é só uma linha usando arrow function (não abre chaves).

```dart
void main() => runApp(const MyApp());
```

2. Quase todas as coisas são Widgets
3. Um Widget pode ser StatelessWidget (sem estado) ou StatefulWidget (controlando estado)
   1. A diferença entre uma classe sem estado para outra é a forma como tratam a atualização da interface do usuário e a capacidade de reagir a mudanças dinâmicas
4. O aplicativo em si é definido por uma classe que geralmente herda (extends) de StatelessWidget
5. Todo widget que sobrescreve o método build é algo visual
6. No método build da classe (que é o MyApp no exemplo) que representa o aplicativo, irá retornar uma instância de um widget, por exemplo, MaterialApp.
7. Observar que os parâmetros em Flutter são nomeados

```dart
return MaterialApp(
      title: 'Flutter Demo',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(primarySwatch: Colors.blue),
      home: const MyHomePage(title: 'Cálculo de valor futuro'),
);
```

8. No Android temos activitys que representam telas, no Flutter as telas são widgets e normalmente as chamamos de páginas. Quando queremos criar uma página, criamos duas classes:
   1. O widget em si
   2. O estado do widget
9. Toda página que é um StatefulWidget precisa sobrescrever/implementar o método createState() e esse método apenas terá uma instância da classe que gerencia o estado da tela
10. A classe que cuida do comportamento e do estado de uma página Flutter, geralmente colocamos o caractere `_` na frente. Então o underline vai diferenciar qual classe é a página e qual classe é a que controla

<figure><img src="../../.gitbook/assets/states em flutter.png" alt=""><figcaption></figcaption></figure>

11. No exemplo do contador, a classe que controla o estado da página principal também contém o layout dela
12. Scaffold é um container de layout que é um padrão pronto e possui 3 partes:
    1. Onde definimos o AppBar
    2. Onde definimos o corpo do layout (body)
    3. No caso do exemplo, um floatingActionButton

## Widgets

No Flutter, um widget é um bloco de construção fundamental da interface do usuário. Tudo no Flutter é um widget, incluindo elementos de layout, controle, e até mesmo o tema. Widgets são usados para criar a interface do usuário e definir como ela deve se comportar.

### **StatelessWidget**

Este tipo de widget é imutável, o que significa que ele não pode mudar seu estado após ser construído. Ele é ideal para elementos de UI que não precisam responder a interações do usuário ou mudanças de estado.

### **StatefulWidget**

Diferente do StatelessWidget, este tipo pode mudar seu estado durante a execução do aplicativo. Ele é composto por duas classes:

* **StatefulWidget**: Define o widget em si.
* **State**: Mantém o estado do widget e é responsável por criar a interface com base no estado atual.

## Estado

É a <mark style="color:blue;">**representação dos dados atuais**</mark> que um widget possui e que pode ser modificado para atualizar a interface do usuário. Refere-se a <mark style="color:blue;">**qualquer informação que pode mudar**</mark> durante a execução de um aplicativo e que precisa ser refletida na interface do usuário, por exemplo, a mudança de um valor de uma variável.

No exemplo de um contador, a variável `_count` armazena o número de cliques feito. Mas como ela pode ser exibida para o usuário se muda a todo momento? A interface é reconstruída com o novo valor de `_count`.&#x20;

O estado é o armazenamento desses dados. Então se há variáveis que possuem valores atribuídos, listas, objetos, instâncias ou referências, o estado armazena tudo isso. Portanto, se o valor de uma instância mudar, o estado muda também. Por isso, utiliza-se o método <mark style="color:purple;">`setState()`</mark> para notificar o sistema que o estado foi alterado e assim, atualizar a página.

O método <mark style="color:purple;">`setState()`</mark> normalmente é utilizado dentro das funções que vão alterar o estado do aplicativo e também, por questão de clareza, a lógica que altera eles também fica dentro da chamada desse método, por exemplo:

```dart
// Uma função que é chamada em algum momento
void _calcularFV() {
  setState(() {
    fv = pv * pow((1 + taxaJuros), nPeriodos);
    fv = double.parse(fv.toStringAsFixed(2));
  });
}

// setState é frequentemente usado em resposta a eventos de UI, como cliques
// de botão, mudanças de texto, etc.
TextField(
  onChanged: (value) {
    setState(() {
      pv = double.tryParse(value) ?? 1000.0;
    });
  },
);

```

Esse método, como dito, é chamado para notificar mudança de estado, portanto, se toda a lógica ficar fora dele e ele ainda for chamado depois, vai funcionar. Por questão de legibilidade, é feito da forma acima. Mas, abaixo um exemplo que também funcionaria:

```dart
void _calcularFV() {
  fv = pv * pow((1 + taxaJuros), nPeriodos);
  fv = double.parse(fv.toStringAsFixed(2));
  
  setState(() {
    // Código vazio, mas o método foi chamado mesmo assim!
  });
}
```

| Classe sem estado                                                                                                             | Classe que controla estado                                                                                                         |
| ----------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------- |
| Não podem armazenar informações que mudam ao longo do tempo.                                                                  | Podem armazenar informações que mudam ao longo do tempo, como contadores, entradas do usuário, etc.                                |
| Uso: títulos, ícones estáticos, layouts fixos.                                                                                | Uso: formulários de entrada, contadores, listas que mudam dinamicamente, animações interativas.                                    |
| Deve ser reconstruída do zero para qualquer mudança. Não vai guardar as variáveis, portanto, não funciona que nem o Stateful. | Pode ser atualizada em resposta a eventos, como cliques de botão, entradas de texto, ou mudanças de dados provenientes de uma API. |
| Sem necessidade de controlar ciclo de vida, são mais leves.                                                                   | Tem uma classe associada que contém o estado atual e é responsável por reconstruir a interface do usuário quando o estado muda     |

