#include <iostream>

using namespace std;

char rotacionar (char letra, int rotacao)
{
    int valor = (letra - (int) 'A' - rotacao) % 26;
    if (valor < 0) valor += 26;
    return valor + (int) 'A';
}

int main ()
{
    int n, rotacao;
    string frase;
    cin >> n;
    while (n > 0) {
	cin >> frase;
	cin >> rotacao;
	for (int i=0; i<frase.length(); i++)
	    cout << rotacionar (frase[i], rotacao);
	cout << endl;
	n--;
    }
    return 0;
}
