string solution(string inputString) {
    std::string out;
    for (auto c : inputString)
        out.push_back('a' + ((c - 'a') + 1) % 26);
    return out;
}
