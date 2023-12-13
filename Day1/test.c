#include <stdio.h>
#include "words_to_numbers.c"
#include "test2.c"

int main(void)
{
    char *testresult = returnString();

    printf("%s\n", testresult);

    char testPhrase[] = "tonenine9nine";

    char *result = words_to_numbers(testPhrase);

    printf("%s %s %i\n", testPhrase, result, strcmp(result, "t1nine99"));

    return 1;
}
