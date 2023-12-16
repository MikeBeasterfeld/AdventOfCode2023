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
    char word[1000] = "tonenine9nine";

    replace_number_words(word);
    stringCompareExpect("t1nine99", word);

    strcpy(word, "two1nine");
    replace_number_words(word);
    stringCompareExpect("219", word);

    strcpy(word, "abcone2threexyz");
    replace_number_words(word);
    stringCompareExpect("abc123xyz", word);

    strcpy(word, "xtwone3four");
    replace_number_words(word);
    stringCompareExpect("x2ne34", word);

    strcpy(word, "4nineeightseven2");
    replace_number_words(word);
    stringCompareExpect("49eight72", word);

    strcpy(word, "zoneight234");
    replace_number_words(word);
    stringCompareExpect("z1ight234", word);

    strcpy(word, "7pqrstsixteen");
    replace_number_words(word);
    stringCompareExpect("7pqrst6teen", word);

    strcpy(word, "7pqrstsixteen");
    replace_number_words(word);
    stringCompareExpect("7pqrst6teen", word);

    strcpy(word, "tonenine9oneight");
    replace_number_words(word);
    stringCompareExpect("t1nine9on8", word);

    return 1;
}
