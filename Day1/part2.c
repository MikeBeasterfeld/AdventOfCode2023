#include <stdio.h>
#include <string.h>
#include "util.c"

int main(void)
{
    char input[1000];
    while (fscanf(stdin, "%s", input) != EOF)
    {
        replace_number_words(&input);
        printf("%s\n", input);
    }
}
