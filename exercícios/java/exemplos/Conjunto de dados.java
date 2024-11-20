public class Conjunto<X> {
    private Object[] elem;
    private int qtd = 0;
    private int capacidadeInicial;

    public Conjunto(int capInicial) throws Exception {
        if (capInicial <= 0)
            throw new Exception("Capacidade invalida");

        this.elem = new Object[capInicial];
        this.capacidadeInicial = capInicial;
    }

    public Conjunto() {
        this.elem = new Object[10];
        this.capacidadeInicial = 10;
    }

    // Cria um vetor completamente novo com a capacidade inserida. Passa cada
    // elemento do vetor antigo para o novo. É chamado no método inclua(), caso vá
    // incluir um elemento com o vetor cheio. O tamanho do vetor é definido
    // previamente.
    private void redimensioneSe(int novaCap) {
        Object[] novo = new Object[novaCap];

        for (int i = 0; i < this.qtd; i++) {
            novo[i] = this.elem[i];
        }

        this.elem = novo;
    }

    // Retorna object de { boolean, int }:
    // 1. Se encontrou: true + posição
    // 2. Não encontrado: false + posição possível de inserir
    private Object[] ondeEsta(X x) {

        for (int i = 0; i < this.qtd; i++) {

            if (x.equals(this.elem[i])) {
                Object[] ret = { true, i };
                return ret;
            }
        }

        Object[] ret = { false, this.qtd };
        return ret;
    }

    // Inclui o elemento x no vetor
    public void inclua(X x) throws Exception {
        if (x == null)
            throw new Exception("Elemento ausente");

        Object[] onde = this.ondeEsta(x);
        boolean elementoJaExiste = (Boolean) onde[0];
        int posicao = (Integer) onde[1];
        int ultimoElementoArray = this.qtd - 1;

        if (elementoJaExiste)
            throw new Exception("Elemento repetido");

        // Chama o método redimensioneSe() com o dobro do tamanho. Procedimento padrão
        // de otimização
        if (this.qtd == this.elem.length)
            redimensioneSe(2 * this.elem.length);

        // For que nunca será executado pois nunca vai satisfazer a condição. Não sei
        // por que está aí
        for (int i = ultimoElementoArray; i >= posicao; i--)
            this.elem[i + 1] = this.elem[i];

        this.elem[posicao] = x;
        this.qtd++;
    }

    @SuppressWarnings("unchecked")
    public X getElemento(int posicao) throws Exception {
        if (posicao < 0 || posicao >= this.qtd)
            throw new Exception("Posição inválida.");

        return (X) this.elem[posicao];
    }

    @Override
    public String toString() {
        String ret = "{";

        if (this.qtd >= 1)
            ret += this.elem[0];

        for (int i = 1; i < this.qtd; i++) {
            ret += "," + this.elem[i];
        }

        return ret + "}";
    }

    // Precisa conferir também as variáveis da classe, como qtd e capacidade + cada
    // elemento dos vetores.
    @Override
    @SuppressWarnings("unchecked")
    public boolean equals(Object obj) {
        if (obj == this)
            return true;
        if (obj == null)
            return false;
        if (obj.getClass() != this.getClass())
            return false;

        Conjunto<X> conj = (Conjunto<X>) obj;
        if (conj.qtd != this.qtd)
            return false;
        if (this.capacidadeInicial != conj.capacidadeInicial)
            return false;

        // Checagem que leva em consideração a mesma ordem colocada no vetor
        for (int i = 0; i < this.elem.length; i++) {
            if (conj.elem[i] != this.elem[i]) {
                return false;
            }
        }

        for (int i = 0; i < this.elem.length; i++) {
            Object[] resultadoBusca = ondeEsta((X) conj.elem[i]);

            if ((boolean) resultadoBusca[0] != false) {
                return false;
            }
        }

        return true;
    }

    // Precisa multiplicar pelas variáveis da classe e cada elemento do vetor. Como
    // os elementos dos vetores já são objetos, eles já herdam o método hashCode e
    // não é necessário fazer um casting
    @Override
    public int hashCode() {
        int ret = 1;

        ret = 13 * ret + ((Integer) this.capacidadeInicial).hashCode();
        ret = 11 * ret + ((Integer) this.qtd).hashCode();

        // Sem necessidade de casting
        for (int i = 0; i < this.qtd; i++) {
            ret = 2 * ret + this.elem[i].hashCode();
        }

        if (ret < 0)
            ret = -ret;

        return ret;
    }

    public Conjunto(Conjunto<X> modelo) throws Exception {
        if (modelo == null)
            throw new Exception("Modelo ausente.");

        this.qtd = modelo.qtd;
        this.capacidadeInicial = modelo.capacidadeInicial;
        this.elem = new Object[modelo.elem.length];

        for (int i = 0; i < this.qtd; i++) {
            this.elem[i] = modelo.elem[i];
        }
    }

    @Override
    public Object clone() {
        Conjunto<X> ret = null;

        try {
            ret = new Conjunto<X>(this);
        } catch (Exception e) {}

        return ret;
    }
}