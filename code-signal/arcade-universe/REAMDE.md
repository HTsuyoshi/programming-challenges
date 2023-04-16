## Palindrome

bool solution(string is) {
    return is == string(is.rbegin(),is.rend());
}

## IPv4

bool solution(std::string s) {
    regex r("[0-9]{1,3}(.[0-9]{1,3}){3}");
    if(!regex_match(s,r))return false;
    int a,b,c,d;
    sscanf(s.c_str(),"%d.%d.%d.%d", &a,&b,&c,&d);
    return a<256 && b<256 && c<256 && d<256;
}
