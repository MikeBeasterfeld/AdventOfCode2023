#include <stdio.h>

int main(void)
{
    enum faang
    {
        FACEBOOK,
        APPLE,
        NETFLIX,
        GOOGLE
    };

    enum faang facebook = FACEBOOK;
    enum faang apple = APPLE;
    enum faang netflix = NETFLIX;
    enum faang google = GOOGLE;

    printf("Facebook is %i\n", facebook);

    return 0;
}