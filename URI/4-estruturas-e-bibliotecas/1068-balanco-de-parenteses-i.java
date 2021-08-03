import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner en = new Scanner(System.in);
        while (en.hasNextLine()) {
            char[] linha = en.nextLine().toCharArray();
            int parenteses = 0;
            boolean certo = true;
            for (int i = 0; i < linha.length; i++) {
                if (linha[i] == ')') parenteses--;
                if (parenteses < 0) {
                    certo = false;
                    break;
                }
                if (linha[i] == '(') parenteses++;
            }
            if(parenteses != 0) certo = false;
            if (certo) System.out.println("correct");
            else System.out.println("incorrect");
        }
    }
}
