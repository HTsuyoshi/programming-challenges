import java.io.IOException;
import java.util.Scanner;

/**
 * IMPORTANT: 
 *      O nome da classe deve ser "Main" para que a sua solução execute
 *      Class name must be "Main" for your solution to execute
 *      El nombre de la clase debe ser "Main" para que su solución ejecutar
 */
public class Main {

    public static void main(String[] args) throws IOException {

        Scanner ler = new Scanner(System.in);
        while (ler.hasNextInt()) {

            int L = ler.nextInt();
            int[] array = new int[L];
            for (int i = 0; i < L; i++)
                array[i] = ler.nextInt();
            ler.nextLine();

            int maior = 0;
            for (int i = 0; i < L; i++)
                if (array[i] > maior)
                    maior = array[i];

            if (maior < 10)
                System.out.println(1);
            else if (maior < 20)
                System.out.println(2);
            else
                System.out.println(3);
        }

    }


}

