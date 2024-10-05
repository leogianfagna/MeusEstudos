# Resumo de reimplementações

Para lembrar de forma fácil as re-implementações, vamos resumir:

## Quando implementar

* `toString`, `equals`, `hashCode`: sempre
* clone: quando existem membros não estáticos que alteram o this.
* compareTo: quando há critério de comparação, onde um objeto pode ser maior, menor ou igual a outro.

## Implementação

* `toString`:
  * Retorna: String
  * Recebe: nada
  * O que fazer: retornar o que vai aparecer na tela.
* `equals`:
  * Retorna: Boolean
  * Recebe: Object (lembrar que, como vai precisar usar getClass() para comparar, então só pode receber um object.
  * O que fazer: Conferir cada atributo se é igual, retornar falso se não for. Conferir nulo, se é igual a this e se as classes são as mesmas.
* hashCode:
  * Retorna: int
  * Recebe: nada
  * O que fazer: inicializar `ret = 1` e multiplicar por cada atributo não estático da instância. Por exemplo: `ret = ret * 3 + ((Integer)this.horas).hashCode()`;
* `compareTo`:
  * Retorna: int
  * Recebe: Mesma classe (tipo Horario)
  * O que fazer: conferir cada atributo da instância this com a instância do parâmetro, retornar 1, -1 ou zero. Usar `Data d = (Data) modelo` e `modelo.horas` para comparar.
    * Implementar carteirinha **Comparable** com parametrização da classe que vai receber, ex \<Horario>.
* `clone`:
  * Retorna: Object
  * Recebe: nada
  * O que fazer: criar construtor de cópia e no método instancia uma nova variável com ele passando this como parâmetro.
    * Implementar carterinha **Clonable**.
    * Construtor de cópia é o this que recebe: `this.horas = modelo.horas`.

## Exemplo final com todos

```java
public class Horario implements Clonable, Comparable<Horario> {
    int horas, minutos, segundos;
    
    @Override
    public String toString() {
        return this.horas + ":" +
               ((this.minutos > 10) ? this.minutos : "0" + this.minutos) + ":" +
               ((this.segundos > 10) ? this.segundos : "0" + this.segundos);
    }
    
    @Override
    public boolean equals(Object obj) {
        if (obj == this) return true;
        if (obj == null) return false; 
        if (obj.getClass() != this.getClass()) return false;
        
        Horario h = (Horario)obj;
        if (h.horas != this.horas) return false;
        if (h.minutos != this.horas) return false;
        if (h.segundos != this.horas) return false;
        return true;
    }
    
    @Override
    public void hashCode() {
        int ret = 1;
        
        ret = ret * 2 + ((Integer)this.horas).hashCode();
        ret = ret * 3 + ((Integer)this.minutos).hashCode();
        ret = ret * 5 + ((Integer)this.segundos).hashCode();
        
        if (ret < 0) ret = ret * -1;
        return ret;
    }
    
    @Override
    public int compareTo(Horario obj) {
        if (this.horas > obj.horas) return 1;
        if (this.horas < obj.horas) return -1;
        
        if (this.minutos > obj.minutos) return 1;
        if (this.minutos < obj.minutos) return -1;
        
        if (this.segundos > obj.segundos) return 1;
        if (this.segundos < obj.segundos) return -1;
        
        return 0;
    }
    
    // Construtor de cópia
    public Horario(Horario modelo) throws Exception {
        if (modelo == null)
            throw new Exception("Modelo ausente");
            
        this.horas = modelo.horas;
        this.minutos = modelo.minutos;
        this.segundos = modelo.segundos;
    }
    
    @Override
    public Object clone() {
        Horario ret = null;
        
        try {
            ret = new Horario(this);
        } catch (Exception erro) {}
        
        return ret;
    }
}
```
