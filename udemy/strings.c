#include <stdio.h>
#include <stdbool.h>

int stringLength(const char myString[])
{
    int count = 0;

    while (myString[count] != '\0')
        count++;

    return count;
};

void concatString(const char part1[], const char part2[], char result[])
{
    int count = 0;
    while (part1[count] != '\0')
    {
        result[count] = part1[count];
        count++;
    }

    int count2 = 0;
    while (part2[count2] != '\0')
    {
        result[count2 + count] = part2[count2];
        count2++;
    }

    result[count2 + count] = '\0';
}

bool compare(const char firstString[], const char secondString[])
{
    int count = 0;

    do
    {
        if (firstString[count] != secondString[count])
        {
            return false;
        }
        count++;
    } while (
        firstString[count] != '\0' && secondString[count] != '\0');

    if (firstString[count] != secondString[count])
    {
        return false;
    }

    return true;
}

int main(void)
{

    printf("The string 'grinch' is %i characters long\n", stringLength("grinch"));

    char result[50];
    concatString("con", "cat", result);

    printf("The strings 'con' and 'cat' put together is '%s'\n", result);

    printf("The strings 'foo' and 'bar' are the same: %s\n", compare("foo", "bar") ? "true" : "false");
    printf("The strings 'car' and 'car' are the same: %s\n", compare("car", "car") ? "true" : "false");
    printf("The strings 'cart' and 'car' are the same: %s\n", compare("cart", "car") ? "true" : "false");

    return 1;
}
