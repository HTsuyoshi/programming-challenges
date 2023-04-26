double fix_num(double n)
{
    if (fmod(n, 1) < 0.0001) return round(n);
    return n;
}
bool solution(vector<double> prices, vector<string> notes, double x) {
    double over = 0;
    int i = 0;
    regex high(".* higher than in-store");
    regex low(".* lower than in-store");
    while (i < prices.size())
    {
        if (notes[i][0] != 'S')
        {
            double rate;
            sscanf(notes[i].c_str(),"%lf%% higher than in-store", &rate);
            rate = rate / 100;
            double sum;
            if(regex_match(notes[i], low))
            {
                sum = (prices[i] / (1 - rate)) - prices[i];
                over -= sum;
            }
            else
            {
                sum = prices[i] - (prices[i] / (1 + rate));
                over += sum;
            }
        }
        ++i;
    }
    return (x >= fix_num(over));
}
