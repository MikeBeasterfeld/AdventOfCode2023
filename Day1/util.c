#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *words_to_number(char input[1000])
{

    return input;
}

void replace_number_words(char input[1000])
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

    do
    {
        char *pEarliestMatch = NULL;
        char *pEarliestWord = NULL;

        for (int i = 0; i < 9; i++)
        {
            char *pMatch = strstr(input, numberWords[i + 1]);
            printf("%i %s\n", i, pMatch);

            if (pMatch == NULL || pEarliestMatch < pMatch)
            {
                pEarliestMatch = pMatch;
                pEarliestWord = numberWords[i + 1];
            }
        }

        printf("First occurence of '%s' in '%s' is '%p'\n", pEarliestWord, input, pEarliestMatch);

    } while (0);

    printf("Result %s \n", input);
}