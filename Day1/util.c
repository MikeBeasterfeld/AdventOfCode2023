#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// char *words_to_number(char input[1000])
// {

//     return input;
// }

void replace_number_words(char *input)
{
    char *numberWords[] = {
        "",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"};

    bool matchFound = false;

    do
    {
        char *pFirstMatch = NULL;
        int wordLength = 0;
        int index;

        matchFound = false;

        for (int i = 1; i < 10; i++)
        {
            char *pMatch = strstr(input, numberWords[i]);
            // printf("%i - %s - %p\n", i, pMatch, pMatch);

            if (pMatch && (pFirstMatch == NULL || pFirstMatch > pMatch))
            {
                // printf("foo\n");
                matchFound = true;
                pFirstMatch = pMatch;
                index = i;
            }
        }

        if (matchFound)
        {
            // printf("First occurence of '%s' (%i) in '%s' is '%p'\n", numberWords[index], index, input, pFirstMatch);

            *pFirstMatch = index + '0';

            while (*pFirstMatch)
            {
                pFirstMatch++;
                *pFirstMatch = *(pFirstMatch + (int)strlen(numberWords[index]) - 1);
                // printf("%s\n", input);
            }

            pFirstMatch++;
            pFirstMatch = "/0";

            // while (*pFirstMatch)
            // {
            //     // printf("%c - %p\n", *pFirstMatch, pFirstMatch);
            //     pFirstMatch++;
            // }
        }

        // printf("--------\n");
    } while (0);

    do
    {
        char *pFirstMatch = NULL;
        int wordLength = 0;
        int index;

        matchFound = false;

        for (int i = 1; i < 10; i++)
        {
            char *pMatch = strstr(input, numberWords[i]);
            // printf("%i - %s - %p\n", i, pMatch, pMatch);

            do
            {
                // printf("%s\n", pMatch);
                if (pMatch)
                {

                    if (pFirstMatch == NULL || pFirstMatch < pMatch)
                    {
                        // printf("foo\n");
                        matchFound = true;
                        pFirstMatch = pMatch;
                        index = i;
                    }
                    pMatch++;
                }

            } while (pMatch != NULL && strstr(pMatch, numberWords[i]) != NULL);
        }

        if (matchFound)
        {
            // printf("First occurence of '%s' (%i) in '%s' is '%p'\n", numberWords[index], index, input, pFirstMatch);

            *pFirstMatch = index + '0';

            while (*pFirstMatch)
            {
                pFirstMatch++;
                *pFirstMatch = *(pFirstMatch + (int)strlen(numberWords[index]) - 1);
                // printf("%s\n", input);
            }

            pFirstMatch++;
            pFirstMatch = "/0";

            // while (*pFirstMatch)
            // {
            //     // printf("%c - %p\n", *pFirstMatch, pFirstMatch);
            //     pFirstMatch++;
            // }
        }

        // printf("--------\n");
    } while (0);

    // while (*input)
    // {
    //     // printf("%c - %p\n", *input, input);
    //     input++;
    // }

    // printf("Result %s \n", input);
}