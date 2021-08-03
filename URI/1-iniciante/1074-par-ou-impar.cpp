#include <iostream>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (a % 2 == 0 && a != 0)
            cout << "EVEN ";
        else if (a % 2 == 1 || a % 2 == -1)
            cout << "ODD ";
        else {
            cout << "NULL" << endl;
        }
            
        if(a != 0){
            if (a > 0)
                cout << "POSITIVE" << endl;
         else 
               cout << "NEGATIVE" << endl;
        }
    }
 
    return 0;
}
