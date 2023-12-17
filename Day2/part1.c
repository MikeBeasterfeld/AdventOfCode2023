#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    int redCubes = 12;
    int greenCubes = 13;
    int blueClubes = 14;

    char input[1000] = "";

    // printf("hi\n");

    int possibleGames[1000];

    bool validGame = true;

    int sum = 0;

    while (fgets(input, sizeof(input), stdin) != NULL)
    {
        input[strcspn(input, "\n")] = 0; // remove newline
        printf("%s\n", input);
        int gameNumber;
        char *ptrGameString = strtok(input, ":");
        // printf("%s\n", ptrGameString);

        char *round;
        char rounds[200][100];
        int roundsCount = 0;

        round = strtok(NULL, ";");
        while (round != NULL)
        {
            strcpy(rounds[roundsCount], round);
            // printf("Round %s\n", round);
            roundsCount++;
            round = strtok(NULL, ";");
        }

        validGame = true;

        for (int i = 0; i < roundsCount; i++)
        {
            char pulls[100][100];
            int pullCount = 0;
            char *pull;

            pull = strtok(rounds[i], ",");

            while (pull != NULL)
            {
                // printf("pull %s\n", pull);
                strcpy(pulls[pullCount], pull);
                pullCount++;

                pull = strtok(NULL, ",");
            }

            // printf("foo\n");

            for (int j = 0; j < pullCount; j++)
            {
                int cubeCount = atoi(strtok(pulls[j], " "));
                char *color = strtok(NULL, " ");

                // printf("color '%s' count '%i'\n", color, cubeCount);

                char *blue = "blue";

                if (strcmp(color, blue) == 0)
                {
                    if (cubeCount > blueClubes)
                    {
                        validGame = false;
                    }
                }

                char *red = "red";

                if (strcmp(color, red) == 0)
                {
                    if (cubeCount > redCubes)
                    {
                        validGame = false;
                    }
                }

                char *green = "green";

                if (strcmp(color, green) == 0)
                {
                    if (cubeCount > greenCubes)
                    {
                        validGame = false;
                    }
                }
            }
        }

        strtok(ptrGameString, " ");
        char *gameNumberString = strtok(NULL, " ");

        // printf("Game number %i\n", *gameNumberString - '0');

        if (validGame)
        {
            printf("Valid Game\n");
            sum += atoi(gameNumberString);
        }
        else
        {
            printf("Invalid Game\n");
        }
    }

    printf("Sum %i\n", sum);

    return 0;
}
