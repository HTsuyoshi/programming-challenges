int get_average(int x, int y, vector<vector<bool>> matrix)
{
    int bombs=0;
    if (x - 1 >= 0)            if (y - 1 >= 0) 
        if (matrix[x - 1][y - 1])bombs += 1;
    if (x - 1 >= 0)
        if (matrix[x - 1][y])bombs += 1;
    if (x - 1 >= 0)            if (y + 1 < matrix[0].size())
        if (matrix[x - 1][y + 1])bombs += 1;
    if (y - 1 >= 0)
        if (matrix[x][y - 1])bombs += 1;
    if (x + 1 < matrix.size()) if (y - 1 >= 0)
        if (matrix[x + 1][y - 1])bombs += 1;
    if (x + 1 < matrix.size())
        if (matrix[x + 1][y])bombs += 1;
    if (x + 1 < matrix.size()) if (y + 1< matrix[0].size())
        if (matrix[x + 1][y + 1])bombs += 1;
    if (y + 1 < matrix[0].size())
        if (matrix[x][y + 1])bombs += 1;
    return bombs;
}


vector<vector<int>> solution(vector<vector<bool>> matrix) {
    vector<vector<int>> out;
    for (int i=0; i<matrix.size(); ++i)
    {
        vector<int> vec;
        for (int j=0; j<matrix[0].size(); ++j)
        {
            vec.push_back(get_average(i, j, matrix));
        }
        out.push_back(vec);
    }
    return out;
}
