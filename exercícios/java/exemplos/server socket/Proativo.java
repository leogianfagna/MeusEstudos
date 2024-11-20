import java.net.*;
import java.io.*;

public class Proativo {
	public static void main (String[] args) {
        String texto;

		try {
			Socket conexao = new Socket ("172.16.1.183", 10000);

            // Transmissor: envia mensagens para o cliente
			PrintWriter transmissor = new PrintWriter (conexao.getOutputStream());

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