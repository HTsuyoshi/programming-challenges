import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
import java.lang.StringBuilder;
import java.io.*;

public class Ex1550 {

    static int inverter (int entrada) {
    if (entrada == 0)
    	return 0;
	StringBuilder string = new StringBuilder(String.valueOf(entrada));
	string = string.reverse();
	int qntDeZero = - 1;
	for (int i = 0; string.charAt(i) == '0'
		&& i < string.length(); i++)
	    qntDeZero++;
	if (qntDeZero > - 1) string = string.delete(0, qntDeZero);
	return Integer.parseInt(string.toString());
    }

    static int[] criarArray (int atual, int qntApertado) {
	int no[] = new int[2];
	no[0] = atual;
	no[1] = qntApertado;
	return no;
    }

    public static void main (String args[]) throws FileNotFoundException {
	//File arq = new File("/home/azurai/Repo/tarefas-usp/DPI/1550/entrada.txt");
    //Scanner ler = new Scanner(arq);
	Scanner ler = new Scanner(System.in);

	int T = ler.nextInt();
	ler.nextLine();
	for(int i = 0; i < T; i++) {
	    int A = ler.nextInt();
	    int B = ler.nextInt();
	    ler.nextLine();
	    int jaPassou[] = new int[10000];

	    int qntApertado = 0;
	    boolean achou = false;
	    Queue <int[]> fila = new LinkedList<>();
	    fila.add(criarArray(A, 0));

	    while (!achou) {
		int canal[] = fila.poll();
		if (canal[0] > 0 && canal[0] < 10000) {
			if(jaPassou[canal[0]] == 1)
				continue;
			jaPassou[canal[0]] = 1;
			if (canal[0] == B) {
				achou = true;
				qntApertado = canal[1];
			}
			fila.add(criarArray(canal[0] + 1, canal[1] + 1));
	    	fila.add(criarArray(inverter(canal[0]), canal[1] + 1));
		}
	    }
	    System.out.println(qntApertado);
	}

    }
}

