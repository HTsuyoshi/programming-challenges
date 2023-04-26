int solution(vector<int> inputArray) {
    int out = 0;
    for (int i=0; i<inputArray.size() - 1; i++)
    {
        if (inputArray[i] >= inputArray[i + 1])
        {
            int value = inputArray[i] - inputArray[i + 1] + 1;
            inputArray[i + 1] = inputArray[i + 1] + value;
            out += value;
        }
    }
    return out;
}
