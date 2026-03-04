#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    printf("Turing Test Simulation\n\n");

    printf("Judge: What did you do yesterday?\n");

    int responder = rand() % 2;

    if (responder == 0)
        printf("Response: I spent the day studying and watching a movie.\n");
    else
        printf("Response: I processed some data and answered questions.\n");

    int guess = rand() % 2;

    if (guess == 0)
        printf("\nJudge guesses: Human\n");
    else
        printf("\nJudge guesses: AI\n");

    if (guess == responder)
        printf("Judge guessed correctly.\n");
    else
        printf("Judge guessed wrong.\n");

    return 0;
}
