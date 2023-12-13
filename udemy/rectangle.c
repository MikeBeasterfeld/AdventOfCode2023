#include <stdio.h>

int main(void)
{
    double width = 5.4;
    double height = 12;
    double perimeter = width * 2 + height * 2;
    double area = width * height;

    int areaInt = width * height;

    printf("A rectangle with a width of %.2f and a height of %.2f has a perimeter of %.2f and an area of %.2f\n", width, height, perimeter, area);

    return 0;
}
