string solution(string inputString) {
    bool stop = 0;
    while (!stop) {
    std::string out = "";
    std::string::iterator i, s, e;
    i = inputString.begin();
    s = inputString.begin() - 1;
    e = inputString.begin() - 1;
    for (; i!=inputString.end(); ++i)
    {
        if (*i == ')' && s == inputString.begin() - 1) {
            out.push_back(*i);
            continue;
        }
        if (*i == ')') {
            e = i - 1;
            for (; e != s; e--)
                out.push_back(*e);
            s = (inputString.begin() - 1);
            e = (inputString.begin() - 1);
            continue;
        }
        if (*i == '(' && s != inputString.begin() - 1) {
            while (s != i)
            {
                out.push_back(*s);
                s++;
            }
            s = i;
            continue;
        }
        if (*i == '(') {
            s = i;
            continue;
        }
        if (s != (inputString.begin() - 1)) continue;
        out.push_back(*i);
    }
        inputString = out;
        stop = 1;
        for (auto e : inputString)
        {
            if (e == '(') {
                stop = 0;
                break;
            }
        }
    }
    return inputString;
}
