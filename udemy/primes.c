#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int primes[100] = {2, 3};
    int nextIndex = 2;

    for (int i = 5; i < 101; i = i + 2)
    {
        bool isPrime = true;
        for (int j = 0; j < nextIndex; j++)
        {
            if (i % primes[j] == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            primes[nextIndex] = i;
            nextIndex++;
        }
    }

    for (int i = 0; i < nextIndex; i++)
    {
        printf("%i\n", primes[i]);
    }

    return 0;
}