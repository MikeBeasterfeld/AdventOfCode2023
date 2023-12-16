#include <stdio.h>
#include <string.h>

int main(void)
{

    char str[] = "This is my string";
    char *ptrStart = str, *ptrEnd = str;

    while (*ptrEnd)
    {
        printf("%p\n", ptrEnd);
        printf("%c\n", *ptrEnd);
        *ptrEnd++;
    }

    printf("\n");

    printf("String length %lu\n", ptrEnd - ptrStart);
    printf("strlen string length %lu\n", strlen(str));

    return 0;
}