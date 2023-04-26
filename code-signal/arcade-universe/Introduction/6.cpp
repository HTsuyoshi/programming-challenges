bool solution(vector<int> sequence) {
    std::vector<int>::iterator it = sequence.begin();
    int a = 0;
    while (it + 1 != sequence.end())
    {
        if (!(*it < *(it + 1))) 
        {
            ++a;
            if (a == 2) return false;
            std::cout << a << std::endl;
            if (it == sequence.begin())
            {
                sequence.erase(it);
            }
            else
            {
                if (*(it + 1) <= *(it - 1)) sequence.erase(it + 1);
                else
                {
                    sequence.erase(it);
                    --it;
                }
            }
            continue;
        }
        ++it;
    }
    return true;
}
