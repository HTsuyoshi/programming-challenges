import java.util.Scanner;
import java.util.HashMap;
import java.lang.StringBuilder;

public class URI2593 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        String texto = ler.nextLine();
        int n = ler.nextInt();
        ler.nextLine();
        String[] comparar;
        comparar = (ler.nextLine() + " l").split(" ");

        HashMap<String, StringBuilder> posicao = new HashMap<String, StringBuilder>();
        for(int i=0; i<n; i++) {
            StringBuilder output = new StringBuilder("");
            posicao.put(comparar[i], output);
        }

        StringBuilder aux, compararSB;
        compararSB = new StringBuilder();
        int comecoPalavra = 0;
        for(int i=0; i<texto.length(); i++) {
            if(texto.charAt(i) == ' ') { 
                if(posicao.containsKey(compararSB.toString())) {
                    aux = posicao.get(compararSB.toString());
                    if(aux.toString().equals("")) aux.append(comecoPalavra);
                    else aux.append(" " + comecoPalavra);
                }
                compararSB = new StringBuilder();
                comecoPalavra = i + 1;
                continue;
            } else {
                compararSB.append(texto.charAt(i));
            }
        }
        if(posicao.containsKey(compararSB.toString())) {
            aux = posicao.get(compararSB.toString());
            if(aux.toString().equals("")) aux.append(comecoPalavra);
            else aux.append(" " + comecoPalavra);
        }

        for(int i=0; i<n; i++) {
            aux = posicao.get(comparar[i]);
            if (aux.toString().equals("")) System.out.println(-1);
            else System.out.println(aux.toString());
        }
    }
}
