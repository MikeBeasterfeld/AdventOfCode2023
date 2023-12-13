#include <stdio.h>
#include <string.h>

int main(void) {
    char input[1000];
    while (fscanf(stdin, "%s", input) != EOF) {        
        printf("%s\n", words_to_numbers(input));
    }
}
