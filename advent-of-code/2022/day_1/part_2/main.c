#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE* f;
	f = fopen("input.txt", "r");
	if(!f) return 1;

	char* line;
	line = NULL;
	int calories[1 << 16];
	memset(calories, 0, sizeof(calories));
	int calories_size;
	calories_size = 1;
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
		calories_size++;

		int j;
		j = 0;
		int put;
		put = new_calories;
		while(j < calories_size)
		{
			if(put > calories[j])
			{
				int aux;
				aux = calories[j];
				calories[j] = put;
				put = aux;
			}
			j++;
		}
	}

	int j;
	j = 0;
	int total;
	total = 0;
	while(j < 3)
	{
		total += calories[j];
		j++;
	}
	printf("%d\n", total);

	return 0;
}
