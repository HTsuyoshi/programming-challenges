int pow_10(int n)
{
    if (n<=0) return 1;
    if (n==1) return 10;
    return pow_10(n-1) * 10;
}
bool solution(int n) {
    int i=0,
        t=n;
    while (t > 0)
    {
        ++i;
        t/=10;
    }
    while (i>0)
    {
        if (((int)(n / pow_10(i - 1))) % 2 == 1) return false;
        --i;
    }
    return true;

}
