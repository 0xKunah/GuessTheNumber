#include "GuessTheNumber.h";
#include <stdio.h>;
#include <time.h>
#include <stdlib.h>

int randomNumber(int min, int max) {
	srand(time(NULL));
	int r = rand() %(max-min);
	return r + min;
}

int minNumber() {
	int min;
	printf("Nombre minimal: ");
	scanf_s("%d", &min);
	return min;
}

int maxNumber() {
	int max;
	printf("Nombre maximal: ");
	scanf_s("%d", &max);
	return max;
}

int howManyTries() {
	int tries;
	printf("Nombre d'essais: ");
	scanf_s("%d", &tries);
	if (tries <= 0) return howManyTries();
	return tries;
}

void main() {
	int min = getMinNumber();
	int max = getMaxNumber();
	if (min > max) {
		printf("Le nombre minimal doit etre inferieur au nombre maximal \n");
		return main();
	}
	int number = getRandomNumber(min, max);
	printf("%d", number);
}