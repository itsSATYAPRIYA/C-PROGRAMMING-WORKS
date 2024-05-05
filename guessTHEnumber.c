#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numberToGuess, playerGuess, attempts = 0;
    srand(time(NULL));
    numberToGuess = rand() % 100 + 1;
    printf("welcome to the Number guessing game!!\n");
    printf("You have only 7 chances to guess the number between 1 and 100.\n");

    do {
        printf("Enter your guess : ");
        scanf("%d", &playerGuess);
        attempts++;

        if (playerGuess > numberToGuess) {
            printf("Guess is higher! Try again.\n");
        } else if (playerGuess < numberToGuess) {
            printf("Guess is lower! Try again.\n");
        } else {
            printf("Congratualations! You guessed the number in %d attempts.\n", attempts);
        }

        if (attempts == 7) {
            printf("You have no more chances left. The number was %d.\n", numberToGuess);
            break;
        }

    } while (playerGuess!= numberToGuess);

    return 0;
}