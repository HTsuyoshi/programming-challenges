vector<string> solution(vector<string> picture) {
    int size = picture[0].size() + 2;
    std::vector<string> out;
    std::string border;
    border.assign(size, '*'); 
    out.insert(out.begin(), border);
    std::vector<string>::iterator it = picture.begin();
    for (; it != picture.end(); it++)
    {
        (*it).insert((*it).begin(), '*');
        (*it).insert((*it).end(), '*');
        out.insert(out.end(), *it);
    }
    out.insert(out.end(), border);
    return out;
}
