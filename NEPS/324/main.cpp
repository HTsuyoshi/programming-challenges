#include <iostream>
using namespace std;

typedef long long int lli;
int main ()
{
	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);

 	int N, L, C;
    lli soma = 0;
 	cin >> N;

 	for(int i = 0; i < N; i++)
 	{
        cin >> L >> C;
        if (L > C)
            soma += C;
 	}

    cout << soma << endl;

    return 0;
}
