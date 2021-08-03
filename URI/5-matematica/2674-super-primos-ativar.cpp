#include <iostream>
#include <math.h>
#include <string>
#include <list>

// Henrique Tsuyoshi Yara e Gustavo Tsuyoshi Ariga
// Usamos duas funcoes a primera testa se o numero eh primo testando ate a raizquadrada dele e a segunda funcao testa se todos os numeros sao diferentes de 1 4 6 8 ou 9

using namespace std;

int is_prime (int n)
{
    if (n == 1 || n == 0)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    for (int i = 3; i <= ceil( sqrt (n)); i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int is_super (int n)
{
    int super = 1;
    string nao_primos = "014689";
    string valor = to_string (n);
    int tamanho = valor.length();
    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < 6; j++)
            if (valor[i] == nao_primos[j])
                return 0;
    return super;
}


int main () 
{
    int a;
    while (cin >> a) {
        if (is_prime (a)) {
            if (is_super(a)) {
                cout << "Super" << endl;
            } else {
                cout << "Primo" << endl;
            }
        } else {
            cout << "Nada" << endl;
        }
    }
    return 0;
}

