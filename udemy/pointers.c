#include <stdio.h>

int main(void)
{

    int myNumber = 10;
    int *pMyNumber = NULL;

    int *pMyNumber2 = &myNumber;

    pMyNumber = &myNumber;

    printf("Address of the pointer: %p\n", &pMyNumber);
    printf("Value of the pointer %p\n", pMyNumber);
    printf("Value of what the pointer is pointing to: %i\n", *pMyNumber);

    printf("Address of the pointer: %p\n", &pMyNumber2);
    printf("Value of the pointer %p\n", pMyNumber2);
    printf("Value of what the pointer is pointing to: %i\n", *pMyNumber2);

    return 0;
}