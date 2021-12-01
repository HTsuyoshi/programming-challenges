#include<iostream>

using namespace std;

int main() {
    int depth = 0,
        prev_depth = 0,
        larger_than_prev = 0;

    cin >> prev_depth;
    while (cin >> depth)
    {
        if (depth > prev_depth)
            larger_than_prev++;
        prev_depth = depth;
    }

    cout << "The depth increase " << larger_than_prev << " times." << endl;
    return 0;
}

