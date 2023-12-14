#include <stdio.h>

void test(const int *pnum)
{
    int foo = 999;
    // *pnum = &foo;
    printf("%i\n", *pnum);
}

int main(void)
{
    int num = 1000;
    const int *PINT = &num;
    int *pInt = &num;

    num = 1001;

    test(&num);
    test(PINT);
    test(pInt);

    return 0;
}