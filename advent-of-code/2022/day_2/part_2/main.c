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

	char result;
	char enemys_choice;
	long long total;
	total = 0;
	while(fscanf(f, "%c %c\n", &enemys_choice, &result) != EOF)
	{
		int choice_mapping[3][3];
		choice_mapping[ROCK][LOSE] = SCISSORS;
		choice_mapping[ROCK][DRAW] = ROCK;
		choice_mapping[ROCK][WIN] = PAPER;
		choice_mapping[PAPER][LOSE] = ROCK;
		choice_mapping[PAPER][DRAW] = PAPER;
		choice_mapping[PAPER][WIN] = SCISSORS;
		choice_mapping[SCISSORS][LOSE] = PAPER;
		choice_mapping[SCISSORS][DRAW] = SCISSORS;
		choice_mapping[SCISSORS][WIN] = ROCK;

		total += get_points(choice_mapping[enemys_choice - 'A'][result - 'X'], result - 'X');
	}

	printf("%lld", total);
	return 0;
}
