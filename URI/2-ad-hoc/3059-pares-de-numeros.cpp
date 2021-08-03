#include <iostream>

// Henrique Tsuyoshi Yara N 11796083

using namespace std;

int main()
{
    int N, I, F, output = 0;
    cin >> N >> I >> F;
    
    int vetor[N];
    
    for (int i=0; i<N; i++)
        cin >> vetor[i];
    
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++){
            if (i == j)
                continue;
            int valor = vetor[i] + vetor[j];
            if (valor >= I && valor <= F){
                output++;
            }
        }
    
    cout << output/2 << endl;
    return 0;
}
