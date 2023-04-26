int solution(string s1, string s2) {
    int alph1[26]{}, alph2[26]{};
    for (auto e : s1)
        alph1[e - 'a']++;
    for (auto e : s2)
        alph2[e - 'a']++;
        
    int out = 0;
    for (int i=0; i<26; ++i)
    {
        if (alph1[i] && alph2[i])out += min(alph1[i], alph2[i]);
    }
    return out;
}

int min(int a, int b)
{
    if (a < b) return a;
    return b;
}
