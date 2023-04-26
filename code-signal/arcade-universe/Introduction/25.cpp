vector<int> solution(vector<int> inputArray, int elemToReplace, int substitutionElem) {
    vector<int> out;
    for (int i: inputArray)
    {
        if (i == elemToReplace) out.push_back(substitutionElem);
        else out.push_back(i);
    }
    return out;
}
