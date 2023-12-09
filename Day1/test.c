#include "words_to_numbers.c"


int main(void) {
    const char* result = words_to_numbers("tonenine9nine");

    printf("tonenine9nine %s %i\n", result, strcmp(result, "t1nine99"));

    return 1;
}
