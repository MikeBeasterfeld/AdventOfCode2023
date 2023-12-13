#include <stdio.h>
#include <string.h>

char *words_to_numbers(char input[1000])
{
    char numbers[9][6] = {
        {"one"},
        {"two"},
        {"three"},
        {"four"},
        {"five"},
        {"six"},
        {"seven"},
        {"eight"},
        {"nine"},
    };

    int count = 0;

    // printf("%s\n", input);
    // printf("%i\n", (int) strlen(input));
    int firstIndex = (int)strlen(input);
    int firstIndexMatch = -1;

    int lastIndex = 0;
    int lastIndexMatch = -1;

    char *substring[1000];
    char *newString[1000];

    for (int i = 0; i < 9; i++)
    {
        if ((substring[0] = strstr(input, numbers[i])) != NULL)
        {
            // printf("%i %s\n", i, *substring);
            int startIndex = (int)strlen(input) - (int)strlen(*substring);

            if (startIndex < firstIndex)
            {
                firstIndex = startIndex;
                firstIndexMatch = i;
            }
        }
    }

    char trimmedInput[1000];

    int startCopy = firstIndex + (int)strlen(numbers[firstIndexMatch]);
    int copyLength = (int)strlen(input) - (int)strlen(numbers[firstIndexMatch]);
    memcpy(trimmedInput, &input[startCopy], copyLength);
    trimmedInput[copyLength] = '\0';

    // printf("trimmed %s\n", trimmedInput);
    // printf("%i\n", (int) strlen(trimmedInput));

    //           11111
    // 012345678901234
    // abcone2threexyz
    //        threexyz

    for (int i = 0; i < 9; i++)
    {
        if ((substring[0] = strstr(trimmedInput, numbers[i])) != NULL)
        {

            //                             15                 7
            int startIndex = (int)strlen(input) - (int)strlen(*substring);

            // printf("%i %s\n", i, *substring);
            // printf("%i %i %i %i\n", (int) strlen(input), (int) strlen(numbers[firstIndex]), (int) strlen(*substring), (int) strlen(numbers[firstIndexMatch]));
            // int startIndex = (int) strlen(input) - (int) strlen(numbers[firstIndex]) - (int) strlen(*substring) - (int) strlen(numbers[firstIndexMatch]);

            if (startIndex > lastIndex)
            {
                lastIndex = startIndex;
                lastIndexMatch = i;
            }
        }
    }

    // printf("input %s - first %i %i %s - last %i %i %s\n", input, firstIndex, firstIndexMatch, numbers[firstIndexMatch], lastIndex, lastIndexMatch, numbers[lastIndexMatch]);

    int firstReplacedLength = (int)strlen(numbers[firstIndexMatch]);
    int lastReplacedLength = (int)strlen(numbers[lastIndexMatch]);

    int i = 0; // current index of input
    int j = 0; // current index of newString

    for (; i < firstIndex;)
    {
        newString[i] = &input[i];
        i++;
        j++;
    }

    // printf("String start %s\n", newString);

    if (firstIndexMatch > -1)
    {
        newString[firstIndex] = firstIndexMatch + 1 + '0';
        i = i + firstReplacedLength;
        j++;
    }

    // printf("First string replacement %s\n", newString);

    for (; i < lastIndex;)
    {
        // printf("%c\n", input[i]);
        // printf("mid %i\n", i);
        // printf("firstReplacedLength %i\n", firstReplacedLength);
        newString[j] = input[i];
        i++;
        j++;
    }

    // printf("up to lastindex %s\n", newString);

    // printf("%i\n", firstIndex + firstReplacedLength);

    if (firstIndex != lastIndex && firstIndex + firstReplacedLength - 1 < lastIndex && lastIndexMatch > -1)
    {
        newString[j] = lastIndexMatch + 1 + '0';
        i = i + lastReplacedLength;
        j++;

        // printf("Last string replacement %s\n", newString);
    }

    for (; i < (int)strlen(input);)
    {
        // printf("%c\n", input[i]);
        newString[j] = input[i];
        i++;
        j++;
    }

    return newString;
}
