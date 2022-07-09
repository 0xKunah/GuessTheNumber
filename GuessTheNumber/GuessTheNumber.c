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
	int min = minNumber();
	int max = maxNumber();
	int tries = howManyTries();
	if (min > max) {
		printf("Le nombre minimal doit etre inferieur au nombre maximal \n");
		return main();
	}
	int number = randomNumber(min, max);

	while (tries > 0) {
		int currentTry;
		printf("Essaie de deviner a quel nombre je pense (%d - %d)\n", min, max);
		scanf_s("%d", &currentTry);

		if (currentTry == number) {
			printf("Bravo, c'est le bon nombre !\n");
			return main();
		}

		if (currentTry < number) {
			min = (currentTry > min ? currentTry : min);
			printf("Mon nombre est plus grand\n");
		}
		else if (currentTry > number) {
			max = (currentTry < max ? currentTry : max);
			printf("Mon nombre est plus petit\n");
		}
		printf("Il te reste %d essais\n", --tries);
	}
}