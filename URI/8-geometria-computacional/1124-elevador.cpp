#include <iostream>

using namespace std;

int menor (int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int maior (int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main () 
{
    int L, C, R1, R2;
    cin >> L >> C >> R1 >> R2;
    while (!(L==0 && C==0 && R1==0 && R2==0)) {
        int maior_raio = maior (R1, R2);

        if (maior_raio * 2 > menor (L, C)) {
            cout << "N" << endl;
            cin >> L >> C >> R1 >> R2;
            continue;
        }

        int soma_raios = R1 + R2;
        int aux1 = L - soma_raios;
        int aux2 = C - soma_raios;
        if (soma_raios * soma_raios > aux1*aux1 + aux2*aux2)
            cout << "N" << endl;
        else
            cout << "S" << endl;


        cin >> L >> C >> R1 >> R2;
    }
    return 0;
}
