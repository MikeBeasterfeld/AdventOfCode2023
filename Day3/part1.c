#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    char input[1000];

    int *matrix[100][100];

    int empty = -1;
    int *ptrEmpty = &empty;

    int token = 0;
    int *ptrToken = &token;

    int row = 0;
    int maxColumn = 0;

    while (fgets(input, sizeof(input), stdin) != NULL)
    {
        bool addingNumbers = false;

        int column = 0;
        while (input[column] != '\n' && input[column] != '\0')
        {
            printf("Row %i column %i value %c\n", row, column, input[column]);

            if (isdigit(input[column]))
            {
                if (addingNumbers)
                {
                    printf("Prev pointer %p - current pointer %p\n", matrix[row][column - 1], matrix[row][column]);
                    matrix[row][column] = matrix[row][column - 1];
                    *matrix[row][column] = *matrix[row][column] * 10 + (input[column] - '0');
                    printf("Prev pointer %p - current pointer %p\n", matrix[row][column - 1], matrix[row][column]);
                }
                else
                {
                    matrix[row][column] = (int *)malloc(sizeof(int));
                    *matrix[row][column] = input[column] - '0';
                    addingNumbers = true;
                }
            }
            else
            {
                addingNumbers = false;
                if (input[column] != '.')
                {
                    matrix[row][column] = ptrToken;
                }
                else
                {
                    matrix[row][column] = ptrEmpty;
                }
            }

            printf("row: %i - column: %i - input: %c - result: %i - pointer %p - adding %i\n", row, column, input[column], *matrix[row][column], matrix[row][column], addingNumbers);

            if (column > maxColumn)
            {
                maxColumn = column;
            }

            column++;
        }

        row++;
    }

    // return 0;

    // int *parts[1000];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < maxColumn; j++)
        {
            printf("%i, %i, %i, %p\n", i, j, *matrix[i][j], matrix[i][j]);

            // if (*matrix[i][j] == token)
            // {
            //     printf("Token at %i, %i, %i\n", i, j, *matrix[i][j]);
            // }
        }
    }

    return 0;
}