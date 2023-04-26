vector<string> solution(vector<string> inputArray) {
    int max=0;
    vector<string> vec;
    for (auto e : inputArray)
    {
        if (e.size() > max) {
            max = e.size();
            vec.clear();
        }
        if (e.size() == max)
        {
            vec.insert(vec.end(), e);
        }
    }
    return vec;
}
