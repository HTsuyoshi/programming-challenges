int solution(vector<int> inputArray) {
    std::set<int> roots;
    for (int i : inputArray)
    {
        int j=1;
        while (j<(i/2) + 1){
            if (i % j == 0) roots.insert(j);
            ++j;
        }
        roots.insert(i);
    }
    int out=1;
    while (true)
    {
        std::set<int>::iterator result = roots.find(out);
        if (result == roots.end()) break;
        ++out;
    }
    return out;
}
