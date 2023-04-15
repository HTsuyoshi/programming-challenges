int solution(int year) {
    return (int) (year / 100) + (year % 100 != 0);
}
