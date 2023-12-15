#include <stdio.h>

int main(void)
{

    char str[] = "This is my string!";
    char *ptrStr = str;

    printf("%c\n", *ptrStr);

    printf("%p\n", str);
    printf("%p\n", ptrStr);

    printf("%p\n", ++ptrStr);
    printf("%c\n", *ptrStr);

    ptrStr = str;

    while (*ptrStr)
    {
        printf("%c", *ptrStr);
        ptrStr++;
    }

    printf("\n");

    return 0;
}