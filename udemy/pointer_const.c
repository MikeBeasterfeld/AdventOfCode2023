#include <stdio.h>

void test(const int *pnum)
{
    int foo = 999;
    // *pnum = &foo;
    printf("%i\n", *pnum);
}

void test2(const int *pnum)
{
    int foo = 999;
    pnum = &foo;
    printf("%i\n", *pnum);
}

int main(void)
{
    int num = 1000;
    const int *PINT = &num;
    int *pInt = NULL;
    pInt = &num;

    num = 1001;

    test(&num);
    test(PINT);
    test(pInt);

    test2(&num);
    // test2(PINT); passing 'const int *' to parameter of type 'int *' discards qualifiers
    test2(pInt);

    return 0;
}