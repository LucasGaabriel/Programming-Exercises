import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class App {

	public static void main(String[] args) throws InformacoesIncompletasException {
		
		try {
			File f = new File("info.txt");
			Scanner s = new Scanner(f);
			
			ArrayList<String> linhas = new ArrayList<>();
			
			while(s.hasNextLine()) {
				String linha = s.nextLine();
				linhas.add(linha);
			}
			
			s.close();
			
			if(linhas.size() < 3) {
				throw new InformacoesIncompletasException("info.txt");
			}
			
			System.out.println("Finalizado!");
			
		} catch (FileNotFoundException e) {

			System.out.println("Arquivo não encontrado!");
		}
		
		

	}

}
