#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char filename[] = "Day1Part1/input3.txt";
    FILE *fptr;
    fptr = fopen(filename, "r");

    char character;

    if (fptr == NULL)
    {
        printf("Could not open '%s'", filename);
    }

    int total = 0;

    int array_pos = 1;
    int numbers[2];

    while ((character = fgetc(fptr)) != EOF)
    {
        if (isdigit(character))
        {
            int i = character - '0';

            if (array_pos == 1)
            {
                numbers[0] = i;
                numbers[1] = i;
                array_pos = 2;
            }
            else
            {
                numbers[1] = i;
            }
        }

        if (character == '\n')
        {
            printf("numbers %i %i\n", numbers[0], numbers[1]);
            total += numbers[0] * 10 + numbers[1];
            numbers[0] = 0;
            numbers[1] = 0;
            array_pos = 1;
        }
    }

    if (array_pos == 2)
    {
        printf("numbers %i %i\n", numbers[0], numbers[1]);
        total += numbers[0] * 10 + numbers[1];
    }

    printf("total %i\n", total);

    return 1;
}
