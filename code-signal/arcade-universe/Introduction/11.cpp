int get_sum(int n, int size)
{
    int sum = 0;
    while (size > 0)
    {
        sum += n % 10;
        n /= 10;
        --size;
    }
    return sum;
}

int pow_10(int n)
{
    if (n <= 1) return 10;
    return 10 * pow_10(n - 1);
}

bool solution(int n) {
    int size = 0,
        nl = n;
    while (nl > 0)
    {
        nl = (int) (nl / 10);
        size++;
    }
    int half = (int)(size / 2);
    int a = get_sum(n/pow_10(half), half);
    int b = get_sum(n % pow_10(half), half);
    return a == b;
}
