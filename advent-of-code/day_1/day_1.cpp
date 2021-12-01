#include<iostream>
#include<fstream>

using namespace std;

int day_1(int n, fstream& input)
{
    int *values = new int[n],
        larger = 0,
        tmp,
        i = 0;

    while (i < n)
    {
        input >> tmp;
        values[i] = tmp;
        i++;
    }

    i %= n;
    while (input >> tmp)
    {
        if (values[i] < tmp) larger++;
        values[i] = tmp;
        i++;
        i %= n;
    }

    return larger;
}

int main() {
    fstream input("./input_1.txt", ios::in);
    int increase_time = day_1(1, input);
    cout << "Task 1: The depth increase " << increase_time << " times." << endl;
    input.close();

    input.open("./input_2.txt", ios::in);
    increase_time = day_1(3, input);
    cout << "Task 2: The depth increase " << increase_time << " times." << endl;
    input.close();
    return 0;
}

