#include <iostream>

using namespace std;

int main () 
{
    int N, M;
    cin >> N >> M;
    int matrix[N][M];

    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> matrix[i][j];

    /*
    for (int i=0; i<N; i++) {
        cout << i;
        for (int j=0; j<M; j++)
            cout << matrix[i][j];
        cout << endl;
    }
    */

    if (N == 0 && M == 0) {
        cout << "N" << endl;
        return 0;
    }

    int escada = 1, tem_zeros = 0, elemento_mais_esq = 501;

    for (int i=0; i<N; i++) {
        int tem_apenas_zero = 1, mais_esq_linha = 501;

        for (int j=M-1; j>=0; j--) {
            if (matrix[i][j] !=0 && j < mais_esq_linha)
                mais_esq_linha = j;

            if (tem_zeros == 1 && matrix[i][j] != 0) {
                escada = 0;
                break;
            }

            if (matrix[i][j] != 0)
                tem_apenas_zero = 0;
        }

        if (elemento_mais_esq == 501)
            elemento_mais_esq = mais_esq_linha;
        else {
            if (mais_esq_linha <= elemento_mais_esq)
                escada = 0;
            else
                elemento_mais_esq = mais_esq_linha;
        }

        if (tem_apenas_zero == 1)
            tem_zeros = 1;

        if (escada == 0)
            break;
    }


    if (escada == 1)
        cout << "S" << endl;
    else
        cout << "N" << endl;

    return 0;
}
