#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE* f;
	f = fopen("input.txt", "r");
	if (!f) return 1;

	char* line;
	line = NULL;
	int calories;
	calories = 0;
	size_t i;
	while(getline(&line, &i, f) != EOF)
	{
		int new_calories;
		new_calories = atoi(line);
		int code;
		code = getline(&line, &i, f);
		while(code != 1 && code != -1)
		{
			new_calories += atoi(line);
			code = getline(&line, &i, f);
		}
		if (new_calories > calories)
			calories = new_calories;
	}

	printf("%d", calories);
	return 0;
}
