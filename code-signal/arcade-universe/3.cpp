bool solution(string inputString) {
    bool result = true;
    std::string::iterator start = inputString.begin();
    std::string::iterator end = inputString.end() - 1;
    std::string::iterator mid = start + (int)(((end - start)/2) + 1);
    while (1) {
        if (*start != *end)
        {
            std::cout << *start << *end << std::endl;
            result = false;
            break;
        }
        if (start == mid) break;
        --end;
        ++start;
    };
    return result;
}
