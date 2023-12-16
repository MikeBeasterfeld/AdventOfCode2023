#include <stdio.h>
#include <string.h>

int main(void)
{
    int myInt = 5;
    char myChar = 'X';
    long myLong = 1;
    long long myLongLong = 1;
    double myDouble = 1;
    long double myLongDouble = 1;

    printf("int %i\n", (int)sizeof(myInt));
    printf("char %i\n", (int)sizeof(myChar));
    printf("long %i\n", (int)sizeof(myLong));
    printf("long long %i\n", (int)sizeof(myLongLong));
    printf("double %i\n", (int)sizeof(myDouble));
    printf("long double %i\n", (int)sizeof(myLongDouble));

    return 0;
}
