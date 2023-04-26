int solution(vector<int> inputArray) {
    std::vector<int>::iterator it = inputArray.begin();
    int out = *it * *((it + 1));
    do {
        if (*it * (*(it + 1)) > out) out = *it * (*(it + 1));
        it++;
    } while((it + 1)!= inputArray.end());
    return out;
}
