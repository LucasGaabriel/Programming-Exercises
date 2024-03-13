import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class App3 {

    public static void main(String[] args) throws ValorNaoNumericoException {

        try {
            File f = new File("entrada.txt");
            Scanner s = new Scanner (f);

            ArrayList<Double> numeros = new ArrayList<>();

            while(s.hasNextLine()){
                String x = s.nextLine();

                try {

                    numeros.add(Double.parseDouble(x));

                } catch (NumberFormatException e) {

                    throw new ValorNaoNumericoException("entrada.txt", x);

                }
            }

            numeros.sort(null);

            double min = numeros.get(0);
            double max = numeros.get(numeros.size() - 1);

            double soma = 0;

            for(Double d : numeros) {
                soma += d;
            }

            double media = soma / numeros.size();

            double mediana;

            if(numeros.size() % 2 == 0) {
                mediana = ( numeros.get(numeros.size() / 2) + numeros.get((numeros.size() / 2) + 1) ) / 2;
            }
            else {
                mediana = numeros.get(numeros.size() / 2);
            }

            soma = 0;

            for(Double d : numeros) {
                soma += Math.pow((d - media), 2);
            }

            double dp = Math.sqrt(soma/numeros.size());

            FileWriter writer = new FileWriter("saida.txt");

            writer.write("Mínimo: " + min + "\n");
            writer.write("Máximo: " + max + "\n");
            writer.write("Média: " + media + "\n");
            writer.write("Mediana: " + mediana + "\n");
            writer.write("Desvio Padrão: " + dp);

            s.close();
            writer.close();

        } catch (FileNotFoundException e) {

            System.out.println("Arquivo não pôde ser lido.");

        } catch (IOException e) {

            System.out.println("Arquivo não pôde ser aberto para escrita.");

        }

    }

}