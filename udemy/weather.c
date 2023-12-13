#include <stdio.h>

int main(void)
{
    float weather[5][12] = {
        {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
        {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
        {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
        {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2},
    };

    float months[12] = {0};

    float yearlyTotal = 0;

    printf("Year   Rainfall (inches)\n");

    for (int y = 0; y < 5; y++)
    {
        float yearTotal = 0;
        for (int m = 0; m < 12; m++)
        {
            yearTotal += weather[y][m];
            months[m] += weather[y][m];
        }
        printf("201%i   %.2f\n", y, yearTotal);
        yearlyTotal += yearTotal;
    }

    printf("\nThe yearly average is %.2f\n\n", yearlyTotal / 5);

    printf("JAN  FEB  MAR  APR  MAY  JUN  JUL  AUG  SEP  OCT  NOV  DEC\n");
    for (int m = 0; m < 12; m++)
    {
        printf("%.1f  ", months[m] / 5);
    }

    printf("\n");

    return 0;
}