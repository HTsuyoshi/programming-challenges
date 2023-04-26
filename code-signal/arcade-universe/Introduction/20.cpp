int max(int a, int b)
{
    if (a > b) return a;
    return b;
}

int solution(vector<int> inputArray) {
    int i=0,
        max_diff=inputArray[0] - inputArray[1];
    while (i != inputArray.size() - 1)
    {
        int result = max(inputArray[i] - inputArray[i + 1], inputArray[i + 1] - inputArray[i]);
        max_diff = max(max_diff,result);
        ++i;
    }
    return max_diff;
}
