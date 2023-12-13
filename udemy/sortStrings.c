#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    int stringCount = 0;

    char strings[10][50] = {};

    printf("How many strings?\n");
    scanf("%d", &stringCount);

    for (int i = 0; i < stringCount; i++)
    {
        printf("Enter string:\n");
        scanf("%s", strings[i]);
    }

    bool done = true;

    do
    {
        done = true;

        for (int i = 0; i + 1 < stringCount; i++)
        {
            printf("%i\n", i);
            char temp[50];

            int cmpResult = strcmp(strings[i], strings[i + 1]);
            printf("%s - %s - %i\n", strings[i], strings[i + 1], cmpResult);

            if (cmpResult > 0)
            {
                printf("Switch %s and %s\n", strings[i], strings[i + 1]);
                strncpy(temp, strings[i], 50);
                strncpy(strings[i], strings[i + 1], 50);
                strncpy(strings[i + 1], temp, 50);

                printf("i %i - stringCount %i\n", i, stringCount);

                if (i + 1 == stringCount - 1)
                {
                    stringCount--;
                    printf("Reducing stringCount\n");
                }

                done = false;
            }
        }
    } while (!done);

    printf("Strings reordered:\n");

    for (int i = 0; i < stringCount; i++)
    {
        printf("%s\n", strings[i]);
    }

    return 0;
}