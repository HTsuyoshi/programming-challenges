#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum play{ ROCK=0, PAPER=1, SCISSORS=2 };
enum result{ LOSE=0, DRAW=1, WIN=2};

int get_points(int choice, int result)
{
	int choice_mapping[3][3];
	choice_mapping[ROCK][LOSE] = (ROCK + 1) + (LOSE * 3);
	choice_mapping[ROCK][DRAW] = (ROCK + 1) + (DRAW * 3);
	choice_mapping[ROCK][WIN] = (ROCK + 1) + (WIN * 3);
	choice_mapping[PAPER][LOSE] = (PAPER + 1) + (LOSE * 3);
	choice_mapping[PAPER][DRAW] = (PAPER + 1) + (DRAW * 3);
	choice_mapping[PAPER][WIN] = (PAPER + 1) + (WIN * 3);
	choice_mapping[SCISSORS][LOSE] = (SCISSORS + 1) + (LOSE * 3);
	choice_mapping[SCISSORS][DRAW] = (SCISSORS + 1) + (DRAW * 3);
	choice_mapping[SCISSORS][WIN] = (SCISSORS + 1) + (WIN * 3);
	return choice_mapping[choice][result];
}

int main(int argc, char *argv[])
{
	FILE* f;
	f = fopen("input.txt", "r");
	if (!f) return 1;

	char my_choice;
	char enemys_choice;
	long long total;
	total = 0;
	while(fscanf(f, "%c %c\n", &enemys_choice, &my_choice) != EOF)
	{
		int result;
		result = 0;
		if(my_choice == 'X' && enemys_choice == 'A') result = 1;
		if(my_choice == 'X' && enemys_choice == 'B') result = 0;
		if(my_choice == 'X' && enemys_choice == 'C') result = 2;
		if(my_choice == 'Y' && enemys_choice == 'A') result = 2;
		if(my_choice == 'Y' && enemys_choice == 'B') result = 1;
		if(my_choice == 'Y' && enemys_choice == 'C') result = 0;
		if(my_choice == 'Z' && enemys_choice == 'A') result = 0;
		if(my_choice == 'Z' && enemys_choice == 'B') result = 2;
		if(my_choice == 'Z' && enemys_choice == 'C') result = 1;

		total += get_points(my_choice - 'X', result);
	}

	printf("%lld", total);
	return 0;
}
