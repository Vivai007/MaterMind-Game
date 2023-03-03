#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CODE_LENGTH 4
#define MAX_GUESSES 12

int main()
{
    int code[CODE_LENGTH];
    int guess[CODE_LENGTH];
    int num_guesses = 0;
    int num_correct = 0;
    int num_almost_correct = 0;
    int i, j;

    srand(time(NULL));

    // Generate random code
    for (i = 0; i < CODE_LENGTH; i++) {
        code[i] = rand() % 6 + 1;
    }

    // Print instructions
    printf("Welcome to Mastermind!\n");
    printf("The code contains numbers from 1 to 6.\n");
    printf("You have %d guesses to crack the code.\n", MAX_GUESSES);

    // Loop until code is cracked or max guesses are reached
    while (num_correct < CODE_LENGTH && num_guesses < MAX_GUESSES) {
        // Get user's guess
        printf("\nGuess %d: ", num_guesses + 1);
        for (i = 0; i < CODE_LENGTH; i++) {
            scanf("%d", &guess[i]);
        }

        // Check guess for correctness
        num_correct = 0;
        num_almost_correct = 0;
        for (i = 0; i < CODE_LENGTH; i++) {
            if (guess[i] == code[i]) {
                num_correct++;
            } else {
                for (j = 0; j < CODE_LENGTH; j++) {
                    if (guess[i] == code[j]) {
                        num_almost_correct++;
                        break;
                    }
                }
            }
        }

        // Print feedback
        printf("You guessed %d number(s) correctly and %d number(s) are in the wrong position.\n",
               num_correct, num_almost_correct);
        num_guesses++;
    }

    // Print game outcome
    if (num_correct == CODE_LENGTH) {
        printf("\nCongratulations! You cracked the code in %d guesses.\n", num_guesses);
    } else {
        printf("\nSorry, you ran out of guesses. The code was:");
        for (i = 0; i < CODE_LENGTH; i++) {
            printf(" %d", code[i]);
        }
        printf("\n");
    }

    return 0;
}
