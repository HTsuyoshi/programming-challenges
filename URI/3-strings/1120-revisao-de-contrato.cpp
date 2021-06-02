#include <iostream>
#include <string>

using namespace std;

int main ()
{
    int i;
    char D;
    string N;
    cin >> D >> N;
    while (D != '0' && N != "0") {
	string tirarD = "";
	i=0;
	while (i<N.length()) {
	    if (N[i] != D)
		tirarD += N[i];
	    i++;
	}

	string saida = "";
	i=0;
	while (tirarD[i] == '0') i++;
	while (i<tirarD.length()) {
	    if (tirarD[i] != D)
		saida += tirarD[i];
	    i++;
	}

	if (saida == "")
	    cout << 0;
	else 
	    cout << saida << endl;

	cin >> D >> N;
    }
    return 0;
}
