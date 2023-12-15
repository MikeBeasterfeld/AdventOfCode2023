#include <stdio.h>

void square(int *const num)
{
    *num = *num * *num;
}

int main(void)
{
    int num1 = 2;
    int num2 = 5;
    int num3 = 25;

    square(&num1);
    printf("%i\n", num1);

    square(&num2);
    printf("%i\n", num2);

    square(&num3);
    printf("%i\n", num3);
}