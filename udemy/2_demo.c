#include <stdio.h>

int main(void)
{
    //                      11111111
    //            012345678901234567
    char str[] = "This is my string!";

    printf("%c\n", str[0]);
    printf("%c\n", str[1]);
    printf("%c\n", str[17]);

    printf("%p\n", &str[0]);
    printf("%p\n", &str[1]);
    printf("%p\n", &str[2]);

    printf("Content of str = '%s'\n", str);
    printf("Size of str = %lu\n", sizeof(str));

    return 0;
}