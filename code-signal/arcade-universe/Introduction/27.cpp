bool solution(string name) {
    regex r("[a-z-A-Z_][a-zA-Z0-9_]*");
    
    return regex_match(name, r);
}
