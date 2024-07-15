---
description: Lista de conceitos rápidos para fixação de aprendizado.
---

# Conceitos rápidos

## Gerais e importantes

* Thread Safe: não interfere na UI Thread, é da classe Async Task
* Callback: resposta
* Provider: janela que solicita permissão durante o uso do app

## Relacionado com interface

* Inflar layout: rechear o layout com as views
* ViewGroup: denominação para as views de layout (LinearLayout, ContraintLayout e RelativeLayout)

## Relacionado com RecyclerView

* RecyclerView: é uma view que possui outras e exibe de forma reciclável
* ViewHolder: embrulho, uma classe que mantem a referência das views em uso; cada item da lista recebe ele
* Adapter: cria objetos do tipo ViewHolder e vincula os dados
* LayoutManager: classe que organiza o RecyclerView e possui os gerenciadores para usar

## Relacionado com dependências

* Firebase Bom: Simplifica a gestão de dependências do Firebase em projetos Android

## Relacionado com Bluetooth

* BluetoothManager: classe que possui uma instância bm.adapter que gerencia as conexões. Invocar o método getSystemServices() passando uma constante chamada BLUETOOTH.SERVICES responde com uma instância dessa classe
* BluetoothAdapter: classe que representa nosso dispositivo, descobre e consulta aparelhos
* BluetoothLeScanner: classe com funcionalidades para escanear e filtrar dispositivos, callbacks de conexões e configurações.
