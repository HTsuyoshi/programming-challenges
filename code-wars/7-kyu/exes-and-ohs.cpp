bool XO(const std::string& str)
{
  int o=0, x=0;
  unsigned long i=0;
  while (i<str.size()) {
    if (str[i] == 'o' || str[i] == 'O') o++;
    if (str[i] == 'x' || str[i] == 'X') x++;
    i++;
  }
  if (o == x)
    return true;
  return false;
}
