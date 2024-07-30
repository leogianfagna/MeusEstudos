import 'package:flutter/material.dart';
import 'dart:math';

void main() => runApp(const MyApp());

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: const MyHomePage(title: 'Cálculo de valor futuro'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  final String title;

  const MyHomePage({
    required this.title,
  });

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  double fv = 0;
  double pv = 1000;
  int nPeriodos = 3;
  double taxaJuros = 0.05;

  void _calcularFV() {
    setState(() {
      fv = pv * pow((1 + taxaJuros), nPeriodos);
      fv = double.parse(fv.toStringAsFixed(2));
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            const Text(
              'O valor futuro, em reais, será de:',
            ),
            Text(
              'R\$ $fv',
              style: Theme.of(context).textTheme.headlineMedium,
            ),
            // Novo elemento na tela
            SizedBox(height: 20),
            TextField(
              decoration: InputDecoration(labelText: 'Valor presente'),
              keyboardType: TextInputType.number,
              onChanged: (value) {
                setState(() {
                  pv = double.tryParse(value) ?? 1000.0;
                });
              },
            ), // Fim do novo elemento
            
            // Mais um novo elemento
            SizedBox(height: 20),
            TextField(
              decoration: InputDecoration(labelText: 'Taxa de Juros'),
              keyboardType: TextInputType.number,
              onChanged: (value) {
                setState(() {
                  taxaJuros = double.tryParse(value) ?? 0.05;
                });
              },
            ),
            SizedBox(height: 20),
            TextField(
              decoration: InputDecoration(labelText: 'Número de períodos'),
              keyboardType: TextInputType.number,
              onChanged: (value) {
                setState(() {
                  nPeriodos = int.tryParse(value) ?? 3;
                });
              },
            ),
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _calcularFV,
        tooltip: 'Calcular',
        child: const Icon(Icons.calculate),
      ),
    );
  }
}

// Leonardo Ferraro Gianfagna
// RA: 18174490