import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class App {

	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		
		System.out.print("Nome: ");
		String nome = s.nextLine();
		
		System.out.print("Idade: ");
		int idade = s.nextInt();
		s.nextLine();
		
		System.out.print("Hobbie: ");
		String hobbie = s.nextLine();
		
		try {
			FileWriter writer = new FileWriter("info.txt");
			
			writer.write("Nome: " + nome + "\n");
			writer.write("Idade: " + idade + "\n");
			writer.write("Hobbie: " + hobbie);
			
			writer.close();
			
		} catch (IOException e) {
			
			System.out.println("Arquivo não pôde ser aberto!");
		}
		
		s.close();
	}

}
