int s(float value, float rate, int threshold, int i)
{
    if (value >= threshold) return i;
    return s(value*rate, rate, threshold, i + 1);
}

int solution(int deposit, int rate, int threshold) {
    return s(deposit, 1.0 + (rate/100.0), threshold, 0);
}
