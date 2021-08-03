
import java.util.*;

class Comparador implements Comparator<Pais> {
	@Override
	public int compare(Pais pais1, Pais pais2) {
		if(pais1.ouro > pais2.ouro) return -1;
		if(pais1.ouro < pais2.ouro) return 1;
		if(pais1.prata > pais2.prata) return -1;
		if(pais1.prata < pais2.prata) return 1;
		if(pais1.bronze > pais2.bronze) return -1;
		if(pais1.bronze < pais2.bronze) return 1;
		return pais1.nome.compareTo(pais2.nome);
	}
}

class Pais {
	String nome;
	int ouro;
	int prata;
	int bronze;
	
	Pais (String nome){
		this.nome = nome;
		ouro = 0;
		prata = 0;
		bronze = 0;
	}
	
}

public class uri2018 {
	
	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		String pais;
		HashMap<String, Pais> tabela = new HashMap<String, Pais>();
		while (ler.hasNextLine()) {
			ler.nextLine();
			for (int i = 1; i < 4; i++) {
				
				pais = ler.nextLine();
				if (tabela.containsKey(pais)) {
					Pais paisAux = tabela.get(pais);
					if(i==1)paisAux.ouro++;
					if(i==2)paisAux.prata++;
					if(i==3)paisAux.bronze++;
					tabela.replace(pais, paisAux);
				} else {
					Pais novoPais = new Pais(pais);
					if(i==1)novoPais.ouro++;
					if(i==2)novoPais.prata++;
					if(i==3)novoPais.bronze++;
					
					tabela.put(pais, novoPais);
				}
			}
		}
		System.out.println("Quadro de Medalhas");
		Collection<Pais> tabelaNaoOrdenada = tabela.values();
		PriorityQueue<Pais> tabelaOrdenada = new PriorityQueue<Pais>(new Comparador());
		
		for(Pais paisPrint : tabelaNaoOrdenada) {
			tabelaOrdenada.add(paisPrint);
		}
		Pais paisPrint = tabelaOrdenada.poll();
		while (paisPrint != null) {
			System.out.printf("%s %d %d %d%n", paisPrint.nome, paisPrint.ouro, paisPrint.prata, paisPrint.bronze);
			paisPrint = tabelaOrdenada.poll();
		}
		ler.close();
	}

}

