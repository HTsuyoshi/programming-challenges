import java.io.IOException;
import java.util.*;
/**
 * IMPORTANT: 
 *      O nome da classe deve ser "Main" para que a sua solução execute
 *      Class name must be "Main" for your solution to execute
 *      El nombre de la clase debe ser "Main" para que su solución ejecutar
 */
public class Main {
    static HashMap<String, String> passou = new HashMap<String, String>();
    static LinkedList<String> listaImprimir = new LinkedList<String>();
    static void imprimir (StringBuilder argumento) {
        if (passou.get(argumento.toString()) == "a")
            return;
        if (argumento.length() == 1) {
            listaImprimir.addFirst(argumento.toString());
            passou.put(argumento.toString(), "a");
            return;
        }
        listaImprimir.addFirst(argumento.toString());
        passou.put(argumento.toString(), "a");
        for (int i = 0; i < argumento.length(); i++){
            StringBuilder aux = new StringBuilder(argumento.toString());
            aux.deleteCharAt(i);
            imprimir(aux);
        }
    } 

    public static void main(String[] args) throws IOException {
        Scanner ler = new Scanner(System.in);
        while (ler.hasNextLine()) {
            String linha = ler.nextLine();
            StringBuilder palavra = new StringBuilder(linha);
            imprimir (palavra);
            listaImprimir.sort(null);
            for (int i = 0; i < listaImprimir.size(); i++)
                System.out.println(listaImprimir.get(i));
            passou = new HashMap<String, String>();
            listaImprimir = new LinkedList<String>();
            System.out.println();
        }
    }

}
