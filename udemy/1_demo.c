#include <stdio.h>

int main(void)
{
    int num = 42;

    printf("num value = %i\n", num);

    int *ptrNum = &num;

    printf("pointer location = %p\n", ptrNum);

    return 0;
}