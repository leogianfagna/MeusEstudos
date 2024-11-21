# Socket

Fundamentos de conexão pela rede entre dois programas precisam que cada um deles tenha uma característica:

## Reativo

Aceita a solicitação e recebe os dados.

* Precisa declarar o objeto <mark style="color:purple;">ServerSocket</mark>:
  * O construtor recebe um número de uma porta PARA SI.
    * As portas são identificadores dentro de uma máquina.
    * Dentro da máquina podem existir várias outras portas, outros reativos.
  * Esse objeto tem o método `accept`, que coloca o reativo em estado de espera e aceitação. Lembra comportamento de um `scanf`.
    * Retorna um objeto socket.
    * Essa espera do `accept` acaba quando o **PROATIVO** instancia um socket com a porta. Isso resulta em um socket de cada lado. Ou seja: tanto reativo quanto proativo tem o seu socket, mas um é feito através do accept e o outro instanciado de forma normal.
* Fecha o ServerSocket e todos os métodos abertos pendentes. Os `close` são feitos na ordem contrária a que você abriu, isso porque um depende do outro.

BufferedReader vai ser uma classe usada em ambas os tipos de conexões. No reativo será usado como um [receptor ](#user-content-fn-1)[^1]e no proativo será usado como teclado[^2].

## Proativo

Iniciativa de comunicação e envio de dados para o cliente.&#x20;

* Chega ao reativo através da porta instanciada no objeto Socket. Precisam usar a mesma porta.
* Fecha o Socket e todos os métodos abertos pendentes. Os `close` são feitos na ordem contrária a que você abriu, isso porque um depende do outro.

## Conclusão

Socket é como se fosse a ponta de um cano. A ponta do cano de cada lado é um socket que dá pra passar coisas e essas coisas precisam ser configuradas.&#x20;

Teoricamente, ambos podem mandar e receber dados. Neste caso, o reativo está preparado apenas para imprimir e ler os dados recebidos. Para simultaneamente ambos ler e receber (e também exibir na tela), é necessário um programa mais complexo que eles possam fazer coisas ao mesmo tempo de forma paralela, então usando THREADS.

Isso mesmo assim não seria tão simples. Imagine que está no meio de uma digitação no terminal e recebe algo no socket, vai aparecer no meio da escrita. Para fazer algo mais decente ainda, fazer um programa com janelas, onde as coisas (o que manda e o que recebe) não se misturam.

## Código

```java
public class Proativo {
	public static void main (String[] args) {
	        String texto;
	
		try {
			Socket conexao = new Socket ("172.16.1.183", 10000);
	
	            // Transmissor: envia mensagens para o cliente
			PrintWriter transmissor = new PrintWriter(
					conexao.getOutputStream());
	
	            // Leitura de dados para a transmissão
			BufferedReader teclado =
			    new BufferedReader (
			    new InputStreamReader (
			        System.in));
	
			do {
				texto=teclado.readLine();
				transmissor.println(texto); // envio
				transmissor.flush(); // envio imediato
			} while (!texto.toUpperCase().equals("FIM"));
	
			transmissor.close();
			conexao.close();
	
		} catch (Exception erro) {
			System.err.println(erro.getMessage());
		}
	}
}
```

```java
public class Reativo {
	public static void main (String[] args) {
        	String texto;

		try {
			ServerSocket pedido = new ServerSocket (10000);
			Socket conexao = pedido.accept();

            		// Receptor: Lê os dados recebidos do cliente
			BufferedReader receptor =
			    new BufferedReader (
			    new InputStreamReader (
			        conexao.getInputStream()));
			
			do {
				texto=receptor.readLine();
				System.out.println(texto);
			} while (!texto.toUpperCase().equals("FIM"));

			receptor.close();
			conexao.close();
			pedido.close();

		} catch (Exception erro) {
			System.err.println(erro.getMessage());
		}
	}
}
```

## Como usar

1. Abrir um Prompt de Comando.
2. Usar `ipconfig`.
3. Resgatar endereço `IPv4`. Inserir no construtor do Socket do **Proativo**.
4. Entrar no diretório do arquivo java com `cd <caminho>`.
   1. **Dica de ouro:** Arrasta a pasta para o cmd que ele já copia o caminho.
5. Compilar: `javac *.java`.
6. Rodar: `java <nome do arquivo>`.

[^1]: Vai ler os dados recebidos com o método `readLine`.

[^2]: Vai ler os dados digitados pelo usuário. Não é o responsável por enviar as informações.
