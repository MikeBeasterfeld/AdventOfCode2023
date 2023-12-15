#include <stdio.h>

int main(void)
{

    char str[] = "This is my string";
    char *pStr = str;

    while (*pStr)
    {
        printf("%p\n", pStr);
        printf("%c\n", *pStr);
        *pStr++;
    }

    printf("\n");

    return 0;
}