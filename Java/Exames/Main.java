import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {

        File f = new File("exames.csv");
        Scanner s = new Scanner(f);

        FileWriter fw = new FileWriter("exames_novos.csv");

        fw.write("Grupo;M1;M2\n");

        while(s.hasNextLine()){
            String line = s.nextLine();

            String[] parts = line.split(";");

            if(parts[1].equalsIgnoreCase("jovem"))
                fw.write("1;");
            else if(parts[1].equalsIgnoreCase("adulto"))
                fw.write("2;");
            else if(parts[1].equalsIgnoreCase("idoso"))
                fw.write("3;");


            if(parts[2].equalsIgnoreCase("normal"))
                fw.write("1;");
            else if(parts[2].equalsIgnoreCase("SDA"))
                fw.write("2;");
            else if(parts[2].equalsIgnoreCase("ITC"))
                fw.write("3;");


            if(parts[3].equalsIgnoreCase("normal"))
                fw.write("1\n");
            else if(parts[3].equalsIgnoreCase("alterado"))
                fw.write("2\n");
            else if(parts[3].equalsIgnoreCase("inconclusivo"))
                fw.write("3\n");
        }

        fw.close();
    }
}