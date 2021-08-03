import java.util.Scanner;
import java.util.HashMap;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.NoSuchElementException;
import java.io.*;

public class Main { 

    public static void main(String[] args) throws FileNotFoundException {

        Scanner sc = new Scanner(System.in);

        while (sc.hasNextLine()) {

            /* Pegar os 3 numeros*/
            int O, D, K;
            O = sc.nextInt();
            D = sc.nextInt();
            K = sc.nextInt();
            sc.nextLine(); /* Quebra de linha */

            /* Parar */
            if (O == 0 && D == 0 && K == 0)
                break;

            /* Pegar os canais banidos */
            HashMap banidos = new HashMap();
            for (int i = 0; i < K; i++)
                banidos.put(sc.nextInt(), "A");

            /* Nao passar por onde ja passou */
            int jaPassou[] = new int[350000];

            /* Lista ligada*/
            Queue<int[]> fila = new ArrayDeque<int[]>();
            // ElementoFila origem = new ElementoFila();
            int origem[] = new int[2];
            origem[0] = O;
            origem[1] = 0;
            fila.add(origem);

            while (!fila.isEmpty() && fila.peek()[0] != D) {

                int[] canal = fila.poll();
                if (jaPassou[canal[0]] == 1)
                    continue;
                jaPassou[canal[0]] = 1;

                if (banidos.get(canal[0]) != null)
                    continue;

                if (canal[0] > 0 && canal[0] <= 100000) {
                    int novo[] = new int[2];
                    novo[0] = canal[0] + 1;
                    novo[1] = canal[1] + 1;
                    fila.add(novo);

                    novo = new int[2];
                    novo[0] = canal[0] - 1;
                    novo[1] = canal[1] + 1;
                    fila.add(novo);

                    if (canal[0] % 2 == 0) {
                        novo = new int[2];
                        novo[0] = canal[0] / 2;
                        novo[1] = canal[1] + 1;
                        fila.add(novo);
                    }

                    if (canal[0] < 55000) {
                        novo = new int[2];
                        novo[0] = canal[0] * 2;
                        novo[1] = canal[1] + 1;
                        fila.add(novo);

                        canal[0] = canal[0]* 3;
                        canal[1] = canal[1] + 1;
                        fila.add(canal);
                    }
                }
            }

            if (!fila.isEmpty() && fila.peek()[0] == D)
                System.out.println(fila.peek()[1]);
            else
                System.out.println("-1");
        }
    }
}

