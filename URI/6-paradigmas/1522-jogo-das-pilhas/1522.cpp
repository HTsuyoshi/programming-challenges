#include <iostream>
#include <map>

#define DEUCERTO 1
#define NAODEU 2

using namespace std;

int stack [3][200];
int N;
map <string, int> jaPassou;

bool busca (int a, int b, int c) {
	string combinacao = to_string(a) + to_string(b) + to_string(c);

	if (jaPassou[combinacao] > 0)  {
		if (jaPassou[combinacao] == 1)
			return true;
		else
			return false;
	}

	if (a > N || b > N || c > N) {
		jaPassou[combinacao] = NAODEU;
		return false;
	}

	if (a == N && b == N &&  c == N) {
		jaPassou[combinacao] = DEUCERTO;
		return true;
	}

	if (stack[0][a] % 3 == 0 && busca (a + 1, b, c)) {
		jaPassou[combinacao] = DEUCERTO;
		return true;
	}
	if (stack[1][b] % 3 == 0 && busca (a, b + 1, c)) {
		jaPassou[combinacao] = DEUCERTO;
		return true;
	}
	if (stack[2][c] % 3 == 0 && busca (a, b, c + 1)) {
		jaPassou[combinacao] = DEUCERTO;
		return true;
	}

	if ((stack[0][a] + stack[1][b]) % 3 == 0 && busca (a + 1, b + 1, c)) {
		jaPassou[combinacao] = DEUCERTO;
		return true;
	}
	if ((stack[0][a] + stack[2][c]) % 3 == 0 && busca (a + 1, b, c + 1)) {
		jaPassou[combinacao] = DEUCERTO;
		return true;
	}
	if ((stack[1][b] + stack[2][c]) % 3 == 0 && busca (a, b + 1, c + 1)) {
		jaPassou[combinacao] = DEUCERTO;
		return true;
	}

	if ((stack[0][a] + stack[1][b] + stack[2][c]) % 3 == 0 && busca (a + 1, b + 1, c + 1)) {
		jaPassou[combinacao] = DEUCERTO;
		return true;
	}
	
	jaPassou[combinacao] = NAODEU;
	return false;
}

int main () {
	cin >> N;
	while (N != 0) {
		jaPassou.clear();

		for (int i= 0; i<N; i++)
			for (int j=0; j<3; j++) 
				cin >> stack [j][i];

		if (busca (0, 0, 0))
			cout << 1 << endl;
		else 
			cout << 0 << endl;

		cin >> N;
	}
}
