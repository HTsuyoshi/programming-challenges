import java.util.Scanner;
import java.lang.StringBuilder;
import java.util.HashMap;

public class MainDebug {

	static HashMap<String, Integer> ja_passou = new HashMap<String, Integer>();
	
	public static int menor(int a, int b) {
		if (a > b)
			return b;
		return a;
	}

	public static void imprimir_filas(int a, int b, int c, int[][] filas, int N, int qnt_recursao) {
		for (int i = menor(a, menor(b, c)); i < N; i++) {
			StringBuilder linha = new StringBuilder("");
			for (int rec = 0; rec < qnt_recursao; rec++)
				linha.append(" ");

			if (i >= a || i >= b || i >= c) {
				if (i >= a)
					linha.append("***" + filas[0][i] + "***");
				else
					linha.append("       ");
				linha.append(" ");
				if (i >= b)
					linha.append("***" + filas[1][i] + "***");
				else
					linha.append("       ");
				linha.append(" ");
				if (i >= c)
					linha.append("***" + filas[2][i] + "***");
				else
					linha.append("       ");

				System.out.println(linha.toString());
			}
		}

		System.out.println();
	}

	
	
	public static boolean busca(int stack_1, int stack_2, int stack_3, int[][] filas, int N, int qnt_recursao) {
		/* Debug */
		StringBuilder linha = new StringBuilder("");
		for (int rec = 0; rec < qnt_recursao; rec++)
			linha.append(" ");
		linha.append("busca (" + stack_1 + ", " + stack_2 + ", " + stack_3 + ")");
		System.out.println(linha);
		imprimir_filas(stack_1, stack_2, stack_3, filas, N, qnt_recursao);
		/* Debug */

		/* Verificar se ja passou pelo caminho */
		String stack = String.valueOf(stack_1) + String.valueOf(stack_2) + String.valueOf(stack_3);
		if (ja_passou.get (stack) != null) {
			if (ja_passou.get (stack) == 1)
			// Se ja passou e achou um caminho retorne true
			return true;
			else if (ja_passou.get (stack) == 2)
			// Se ja passou e nao achou um caminho retorne false
			return false;
		}

		if (stack_1 == N && stack_2 == N && stack_3 == N) {
			/* Debug */
			System.out.println("Achou um caminho!");
			System.out.println();
			/* Debug */

			ja_passou.put (stack, 1);
			return true;
		}

		if (stack_1 > N || stack_2 > N || stack_3 > N) {
			/* Debug */
			System.out.println("Passou do limite da stack");
			System.out.println();
			/* Debug */

			ja_passou.put (stack, 2);
			return false;
		}

		if (stack_1 < N && filas[0][stack_1] % 3 == 0
				&& busca(stack_1 + 1, stack_2, stack_3, filas, N, qnt_recursao + 1)) {
			ja_passou.put (stack, 1);
			return true;
		}
		if (stack_2 < N && filas[1][stack_2] % 3 == 0
				&& busca(stack_1, stack_2 + 1, stack_3, filas, N, qnt_recursao + 1)) {
			ja_passou.put (stack, 1);
			return true;
		}
		if (stack_3 < N && filas[2][stack_3] % 3 == 0
				&& busca(stack_1, stack_2, stack_3 + 1, filas, N, qnt_recursao + 1)) {
			ja_passou.put (stack, 1);
			return true;
		}

		if (stack_1 < N && stack_2 < N && (filas[0][stack_1] + filas[1][stack_2]) % 3 == 0
				&& busca(stack_1 + 1, stack_2 + 1, stack_3, filas, N, qnt_recursao + 1)) {
			ja_passou.put (stack, 1);
			return true;
		}
		if (stack_1 < N && stack_3 < N && (filas[0][stack_1] + filas[2][stack_3]) % 3 == 0
				&& busca(stack_1 + 1, stack_2, stack_3 + 1, filas, N, qnt_recursao + 1)) {
			ja_passou.put (stack, 1);
			return true;
		}
		if (stack_2 < N && stack_3 < N && (filas[1][stack_2] + filas[2][stack_3]) % 3 == 0
				&& busca(stack_1, stack_2 + 1, stack_3 + 1, filas, N, qnt_recursao + 1)) {
			ja_passou.put (stack, 1);
			return true;
		}

		if (stack_1 < N && stack_2 < N && stack_3 < N
				&& (filas[0][stack_1] + filas[1][stack_2] + filas[2][stack_3]) % 3 == 0
				&& busca(stack_1 + 1, stack_2 + 1, stack_3 + 1, filas, N, qnt_recursao + 1)) {
			ja_passou.put (stack, 1);
			return true;
		}

		/* Caso depois de todos os testes nao tenha achado um caminho coloque um 2 */
		ja_passou.put (stack, 2);
		return false;
	}

	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		int N = ler.nextInt();
		
		while (N != 0) {
			int[][] filas = new int[3][N];
			ja_passou.clear();
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < 3; j++) {
					filas[j][i] = ler.nextInt();
				}
			}

			if (busca(0, 0, 0, filas, N, 0)) {
				System.out.println(1);
			} else {
				System.out.println(0);
			}

			N = ler.nextInt();
		}
		ler.close();

	}
}
