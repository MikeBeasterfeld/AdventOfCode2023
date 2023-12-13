#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *words_to_number(char input[1000])
{

    return input;
}

char *replace_number_words(char input[1000])
{
    char *numberWords[] = {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"};

    char result[1000];
    char match[1000];
    char *earliestPosition;
    int earliestIndex = 1000;
    int earliestNumber = 0;
    int earliestNumberSize = 0;
    char earliestMatch[6];
    bool updated = false;

    do
    {
        for (int i = 0; i < 9; i++)
        {
            char *match = strstr(input, numberWords[i + 1]);
            printf("%i %s\n", i, match);

            if (match != NULL)
            {
                int foundIndex = (int)strlen(input) - (int)strlen(match) + 1;
                printf("Index %i\n", foundIndex);

                if (foundIndex < earliestIndex)
                {
                    printf("bar\n");
                    earliestPosition = match;
                    strcpy(earliestMatch, numberWords[i]);
                    earliestIndex = foundIndex;
                    // earliestNumber = i + 1;
                    // earliestNumberSize = (int)strlen(numberWords[i + 1]);
                }
            }
        }

        if (earliestIndex != 1000)
        {
            strcpy(result, input);
            char temp[1000];
            printf("foo\n");

            strcpy(temp, earliestPosition + strlen(earliestMatch));
            printf("temp %s", temp);

            strcpy(earliestPosition, earliestMatch);

            strcat(result, temp);
        }
    } while (updated == true);

    printf("Result %s \n", result);

    return result;
}