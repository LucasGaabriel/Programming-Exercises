import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class App {

	public static void main(String[] args) {
		
		try {
			File f = new File("info.txt");
			Scanner s = new Scanner(f);
			
			while(s.hasNextLine()) {
				String linha = s.nextLine();
				String[] partes = linha.split(" ");
				System.out.println(partes[1]);
			}
			
			s.close();
			
		} catch (FileNotFoundException e) {

			System.out.println("Arquivo não encontrado!");
		}
		
		

	}

}
