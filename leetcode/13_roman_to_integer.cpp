#include <iostream>
#include <string>


class Solution {
public:
    int romanToInt(std::string s) {
		return 1;
    }
};

int test(std::string in, int out)
{
	Solution sol = Solution();
	if (sol.romanToInt(in) == out)
	{
		return 0;
	}

	std::cout << "in: " << sol.romanToInt(in) << " out: " << out << std::endl;
	return -1;
};

int main(int argc, char *argv[])
{
	std::string test_in[] = {"I", "V", "X", "L", "C", "D", "M"};
	int test_out[] = {1, 5, 10, 50, 10, 500, 1000};

	int i = 0;
	while(i < sizeof(test_out)/sizeof(int))
	{
		if (test(test_in[i], test_out[i])) return -1;
		++i;
	}
	return 0;
}
