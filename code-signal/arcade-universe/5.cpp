int calculate(int i)
{
    if (i == 0) return 0;
    if (i == 1) return 1;
    if (i == 2) return 5;
    return calculate(i - 1) + (i*2 + (2 * (i - 2)));
}

int solution(int n) {
    return calculate(n);
}
