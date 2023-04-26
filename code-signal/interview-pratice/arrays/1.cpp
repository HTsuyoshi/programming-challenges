int solution(vector<int> a) {
    std::set<int> s;
    for (int i:a)
        if (s.find(i) != s.end()) return i;
        else s.insert(i);
    return -1;
}
