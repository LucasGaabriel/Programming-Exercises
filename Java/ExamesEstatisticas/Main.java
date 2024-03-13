import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {

        File f = new File("exames.csv");
        Scanner s = new Scanner(f);

        FileWriter fw = new FileWriter("estatisticas.txt");

        int[] grupos = new int[3];
        int[] m1 = new int[3];
        int[] m2 = new int[3];

        while(s.hasNextLine()){
            String line = s.nextLine();

            String[] parts = line.split(";");

            if(parts[1].equalsIgnoreCase("jovem"))
                grupos[0]++;
            else if(parts[1].equalsIgnoreCase("adulto"))
                grupos[1]++;
            else if(parts[1].equalsIgnoreCase("idoso"))
                grupos[2]++;


            if(parts[2].equalsIgnoreCase("normal"))
                m1[0]++;
            else if(parts[2].equalsIgnoreCase("SDA"))
                m1[1]++;
            else if(parts[2].equalsIgnoreCase("ITC"))
                m1[2]++;


            if(parts[3].equalsIgnoreCase("normal"))
                m2[0]++;
            else if(parts[3].equalsIgnoreCase("alterado"))
                m2[1]++;
            else if(parts[3].equalsIgnoreCase("inconclusivo"))
                m2[2]++;
        }

        fw.write("Grupo\n");
        fw.write("* Jovem: " + grupos[0] + "\n");
        fw.write("* Adulto: " + grupos[1] + "\n");
        fw.write("* Idoso: " + grupos[2] + "\n");

        fw.write("M1\n");
        fw.write("* Normal: " + m1[0] + "\n");
        fw.write("* SDA: " + m1[1] + "\n");
        fw.write("* ITC: " + m1[2] + "\n");

        fw.write("M2\n");
        fw.write("* Normal: " + m2[0] + "\n");
        fw.write("* Alterado: " + m2[1] + "\n");
        fw.write("* Inconclusivo: " + m2[2] + "\n");

        fw.close();
    }
}