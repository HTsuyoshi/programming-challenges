int solution(vector<vector<int>> matrix) {
    int sum = 0;
    int naopode[matrix[0].size()]{};
    for (int i=0; i<matrix.size(); ++i)
    {
        for (int j=0; j<matrix[0].size(); ++j)
        {
            if (matrix[i][j] == 0){
                naopode[j] = 1;
            }
            if (naopode[j]) continue;
            sum += matrix[i][j]; 
        }
    }
    return sum;
}
