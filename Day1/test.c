#include <stdio.h>
#include "util.c"
#include <string.h>

void stringCompareExpect(char expected[], char got[])
{
    int compare = strcmp(expected, got);

    printf("Expected: '%s' Got: '%s' - Result: %s\n", expected, got, compare == 0 ? "OK" : "Failed");
}

int main(void)
{
    stringCompareExpect("t1999", replace_number_words("tonenine9nine"));

    stringCompareExpect("t1nine99", words_to_number("tonenine9nine"));

    return 1;
}
