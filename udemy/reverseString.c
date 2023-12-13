#include <stdio.h>
#include <string.h>

void reverse(char input[], char result[])
{
    int inputIndex = strlen(input);
    int resultIndex = 0;

    for (int i = inputIndex - 1; i > -1; i--)
    {
        printf("i %i resultIndex %i\n", i, resultIndex);
        result[resultIndex] = input[i];
        resultIndex++;
    }
    result[resultIndex] = '\0';

    printf("result %s\n", result);
}

int main(void)
{
    char myString[100];
    char result[100];

    printf("Enter string to be reversed:\n");
    scanf("%s", myString);

    reverse(myString, result);

    printf("The reverse of '%s' is '%s'\n", myString, result);

    return 0;
}