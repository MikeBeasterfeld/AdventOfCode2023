#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    char input[1000];

    // printf("hi\n");

    int possibleGames[1000];

    bool validGame = true;

    int sum = 0;

    while (fgets(input, sizeof(input), stdin) != NULL)
    {
        input[strcspn(input, "\n")] = 0; // remove newline

        char *ptrInput = &input[0];
        printf("%s\n", ptrInput);
        // int gameNumber;

        char *ptrGameString = strsep(&ptrInput, ":");

        printf("---------\n");
        printf("%s\n", ptrGameString);
        printf("%s\n", ptrInput);
        printf("---------\n");

        char *round;

        long minRed = 0;
        long minBlue = 0;
        long minGreen = 0;

        while ((round = strsep(&ptrInput, ";")) != NULL)
        {
            printf("Round: '%s'\n", round);
            char *pull;
            while ((pull = strsep(&round, ",")) != NULL)
            {
                pull++; // remove leading space
                char *number = strsep(&pull, " ");
                char *ptr;
                long dice = strtol(number, &ptr, 10);

                printf("Color: '%s', Dice count: '%ld'\n", pull, dice);

                if (strcmp(pull, "blue") == 0)
                {
                    // printf("found blue\n");
                    if (minBlue < dice)
                    {
                        minBlue = dice;
                    }
                }
                if (strcmp(pull, "red") == 0)
                {
                    // printf("found red\n");
                    if (minRed < dice)
                    {
                        minRed = dice;
                    }
                }
                if (strcmp(pull, "green") == 0)
                {
                    // printf("found green\n");
                    if (minGreen < dice)
                    {
                        minGreen = dice;
                    }
                }
            }
        }

        printf("Green: %ld, Blue: %ld, Red: %ld\n", minGreen, minBlue, minRed);

        sum += minGreen * minBlue * minRed;
    }

    printf("Sum %i\n", sum);

    return 0;
}
