#include<string>

bool is_numeric(char c)
{
    if (c >= '0' && c <= '9') return true;
    return false;
}

bool is_valid(std::string n)
{
    std::cout << n << std::endl;
    if ((std::stoi(n) < 0) || (std::stoi(n) > 255)) return false;
    if (n.size() != std::to_string(std::stoi(n)).size()) return false;
    return true;
}

bool solution(string inputString) {
    int n_dot = 3,
        n_num = 3,
        n = 0;
    std::string::iterator it = inputString.begin();
    for (; it!=inputString.end(); ++it)
    {
        std::cout << *it << std::endl;
        if (!is_numeric(*it) && ((*it) != '.')) return false;
        else if (is_numeric((*it)))
        {
            n++;
            if (n > 3) return false;
        }
        else if ((*it) == '.')
        {
            if (n != 0) {
                --n_num;
                if (!is_valid(std::string(it - n, it))) return false;
            }
            n_dot--;
            n = 0;
        }
    }
    if (!is_valid(std::string(it - n, it))) return false;
    if (n_dot != 0) return false;
    if (n_num != 0) return false;
    return true;
}
