bool solution(string inputString) {
    int alph = 0,
        value = 0;
    std::string::iterator it = inputString.begin();
    for (; it!=inputString.end(); ++it)
    {
        value = *it - ('a') + 1;
        alph ^= 1 << value;
        std::cout << alph << std::endl;
    }
    return ((alph == 0) || ((alph & (alph - 1)) == 0));
}
