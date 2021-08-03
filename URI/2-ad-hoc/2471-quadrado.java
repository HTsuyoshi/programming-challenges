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
        int N = ler.nextInt();
        int[][] matriz = new int[N][N];

        int[] somaVert = new int[N];
        int[] somaHorz = new int[N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matriz[i][j] = ler.nextInt();
                somaVert[i] += matriz[i][j];
                somaHorz[j] += matriz[i][j];
            }
        }

        int[] n1 = new int[3];
        int[] n2 = new int[3];
        for (int i = 0; i < N; i++) {
            if (n1[0] == 0) {
                n1[0] = somaVert[i];
                n1[1] = i;
            } else if (n2[0] == 0 && n1[0] != somaVert[i]) {
                n2[0] = somaVert[i];
                n2[1] = i;
            }
            if (n1[0] == somaVert[i]) {
                n1[2]++;
            }
            if (n2[0] == somaVert[i]) {
                n2[2]++;
            }
        }


        int indexV;
        if (n2[2] > n1[2]) {
            indexV = n1[1];
        } else {
            indexV = n2[1];
        }

        n1 = new int[3];
        n2 = new int[3];
        for (int i = 0; i < N; i++) {
            if (n1[0] == 0) {
                n1[0] = somaHorz[i];
                n1[1] = i;
            } else if (n2[0] == 0 && n1[0] != somaHorz[i]) {
                n2[0] = somaHorz[i];
                n2[1] = i;
            }

            if (n1[0] == somaHorz[i]) {
                n1[2]++;
            }

            if (n2[0] == somaHorz[i]) {
                n2[2]++;
            }
        }

        int indexH;
        int somaCerta;
        int somaErrada;
        if (n2[2] > n1[2]) {
            indexH = n1[1];
            somaCerta = n2[0];
            somaErrada = n1[0];
        } else {
            indexH = n2[1];
            somaCerta = n1[0];
            somaErrada = n2[0];
        }

        somaErrada -= matriz[indexV][indexH];

        if (somaCerta > somaErrada)
            System.out.print(somaCerta - somaErrada + " ");
        else
            System.out.print(somaErrada - somaCerta + " ");
        System.out.println(matriz[indexV][indexH]);



    }

}

