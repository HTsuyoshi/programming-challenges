int get_average(int x, int y, vector<vector<int>> image)
{
    int avg=0;
    avg += image[x - 1][y - 1];
    avg += image[x - 1][y];
    avg += image[x - 1][y + 1];
    avg += image[x][y - 1];
    avg += image[x][y];
    avg += image[x][y + 1];
    avg += image[x + 1][y - 1];
    avg += image[x + 1][y];
    avg += image[x + 1][y + 1];
    return (int)(avg/9);
}

vector<vector<int>> solution(vector<vector<int>> image) {
    vector<vector<int>> out;
    for (int i=1; i<(image.size() - 1); ++i)
    {
        vector<int> vec;
        for (int j=1; j<(image[0].size() - 1); ++j)
        {
            vec.push_back(get_average(i, j, image));
        }
        out.push_back(vec);
    }
    return out;
}
