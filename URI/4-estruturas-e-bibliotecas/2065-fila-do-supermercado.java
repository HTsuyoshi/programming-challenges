import java.util.*;

class Comparador implements Comparator<int[]> {
    public int compare (int[] array1, int[] array2) {
	if (array1[0] == array2[0]) {
	    if (array1[2] > array2[2])
		return 1;
	    else
		return -1;
	} else if (array1[0] < array2[0])
	    return -1;
	else
	    return 1;

    }
}

public class a {
    public static void main(String[] args) {
	Scanner ler = new Scanner(System.in);
	int N = ler.nextInt(), M = ler.nextInt();
	ler.nextLine();
	int custoTotal = 0, velocidade = 1, ordem = 2;

	PriorityQueue<int[]> funcionarios = new PriorityQueue<int[]>(new Comparador());
	String[] linha = ler.nextLine().split(" ");
	for (int i=0; i<N; i++) {
	    int[] novo = new int[3];
	    novo[custoTotal] = 0;
	    novo[velocidade] = Integer.parseInt(linha[i]);
	    novo[ordem] = i;
	    funcionarios.add(novo);
	}

	int[] clientes = new int[M];
	linha = ler.nextLine().split(" ");
	for (int i=0; i<M; i++)
	    clientes[i] = Integer.parseInt(linha[i]);

	int i = 0, maior = 0;
	while (i < M) {
	    int[] funcionario = funcionarios.poll();
	    funcionario[custoTotal] += clientes[i] * funcionario[velocidade];
	    funcionarios.add(funcionario);
	    maior = Math.max(maior, funcionario[custoTotal]);
	    i++;
	}

	System.out.println(maior);

    }
}
