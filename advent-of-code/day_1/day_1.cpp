#include<iostream>

using namespace std;

int day_1(int n)
{
    int *values = new int[n],
        larger = 0,
        tmp,
        i = 0;

    while (i < n)
    {
        cin >> tmp;
        values[i] = tmp;
        i++;
    }

    i %= n;
    while (cin >> tmp)
    {
        if (values[i] < tmp) larger++;
        cout << values[i] << ' ' << tmp << endl;
        values[i] = tmp;
        i++;
        i %= n;
    }

    return larger;
}

int main() {
    int increase_time = day_1(3);
    cout << "The depth increase " << increase_time << " times." << endl;
    return 0;
}

