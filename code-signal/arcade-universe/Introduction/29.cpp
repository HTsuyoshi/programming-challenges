bool solution(string cell1, string cell2) {
    return ((((cell1[0] - 'A') + cell1[1] - '0') % 2) == (((cell2[0] - 'A') + cell2[1] - '0') % 2));
}
