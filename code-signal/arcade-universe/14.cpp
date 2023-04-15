bool solution(vector<int> a, vector<int> b) {
    int out = 0,
        n = 0;
    for (int i=0; i<a.size(); ++i)
        if (a[i] != b[i]) {
            n ^= a[i];
            n ^= b[i];
            out++;
        }
    return (n == 0 && ((out == 0) || (out == 2)));
}
