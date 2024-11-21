# Exceções

Uma exceção aciona quando existe a possibilidade de receber parâmetros inválidos e também quando a formação da instância é inválida.

## Testar nulo

Objetos de outras classes e vetores podem ser nulos. Qualquer tipo primitivo não pode ser nulo em Java. Por conta disso, receber uma dessas opções vai exigir testar se ele é nulo, lançando uma exceção caso seja.

```java
public boolean doSomething(Data dataRecebida) throws Exception {
    if (dataRecebida == null)
        throw new Exception("Modelo ausente");
    ...
}
```

## Parâmetro de métodos

Quando o parâmetro recebido não serve por conta de alguma condição da classe, também podemos lançar uma exceção.

```java
public void setMes (byte mes) throws Exception {
    if (mes < 1 || mes > 12)
        throw new Exception ("Mes invalido");

    this.mes=mes;
}
```

## Usar em construtores

Na hora de construir uma instância de uma classe, podemos também lançar exceções em construtores, de duas formas:

#### Validar e lançar exceção

```java
public Data (byte dia, byte mes, short ano) throws Excepion {
    if (!Data.isValida(dia, mes, ano)
        throw new Exception ("Data inválida.");
        
    this.dia = dia;
    this.mes = mes;
    this.ano = ano;
}
```

#### Usar métodos que lançam exceções

```java
public Horario (byte hora, byte minuto, byte segundo) throws Exception {
    this.setHora(hora);
    this.setMinuto(minuto);
    this.setSegundo(segundo);
}
```
