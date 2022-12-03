#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_priority(char letter)
{
	int priority;
	priority = 1;
	if (letter >= 'a') priority = letter - 'a' + 1;
	else priority = letter - 'A' + 26 + 1;
	return priority;
}

int main(int argc, char *argv[])
{
	FILE* f;
	f = fopen("input.txt", "r");
	if (!f) return 1;

	char* line;
	line = NULL;
	size_t n;
	n = 120;
	ssize_t len;
	len = 0;
	long long total;
	total = 0;
	while((len = getline(&line, &n, f)) != EOF)
	{
		int i;
		i = 0;

		int letters_1[52];
		memset(letters_1, 0, sizeof(letters_1));
		while(i < (len - 1)/2)
		{
			++letters_1[get_priority(line[i]) - 1];
			++i;
		}

		int letters_2[52];
		memset(letters_2, 0, sizeof(letters_2));
		while(i < len - 1)
		{
			++letters_2[get_priority(line[i]) - 1];
			++i;
		}

		i = 0;
		while(i < 52)
		{
			if(letters_1[i] != 0 &&
				letters_2[i] != 0)
				total += i + 1;
			++i;
		}
	}
	printf("%lld", total);
	return 0;
}
