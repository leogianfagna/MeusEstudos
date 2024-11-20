import java.net.*;
import java.io.*;

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