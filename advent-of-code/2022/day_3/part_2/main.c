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
		int lines_read;
		lines_read = 0;
		int letters[3][52];
		memset(letters, 0, sizeof(letters));
		int i;
		i = 0;
		while(i < len - 1)
		{
			++letters[lines_read][get_priority(line[i]) - 1];
			++i;
		}
		while(lines_read < 2)
		{
			len = getline(&line, &n, f);
			++lines_read;
			int i;
			i = 0;
			while(i < len - 1)
			{
				++letters[lines_read][get_priority(line[i]) - 1];
				++i;
			}
		}

		i = 0;
		while(i < 52)
		{
			if(letters[0][i] != 0 &&
				letters[1][i] != 0 &&
				letters[2][i] != 0)
			{
				int a;
				a = 'A' + i - 26;
				if(i < 27) a = 'a' + i;
				printf("i: %d, \tc: %c\n", i, a);
				total += i + 1;
			}
			++i;
		}
	}
	printf("%lld", total);
	return 0;
}
