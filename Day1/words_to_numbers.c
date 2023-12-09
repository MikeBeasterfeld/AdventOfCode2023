#include <stdio.h>
#include <string.h>

int main(void) {
    char input[1000];

    char numbers[9][6] = {
        {"one"},
        {"two"},
        {"three"},
        {"four"},
        {"five"},
        {"six"},
        {"seven"},
        {"eight"},
        {"nine"},
    };

    int count = 0;

    while (fscanf(stdin, "%s", input) != EOF && count < 10) {
        // printf("Start input - %s\n", input);
        for(int i = 8; i >= 0; i--) {
            // printf("start %s - %s - %i\n", numbers[i], input, i);
            // printf("i %i\n", i);
            char* substring[1000];
            if ((substring[0] = strstr(input, numbers[i])) != NULL) {
                char newInput[1000] = "";

                int beforeCharacters = (int) strlen(input) - (int) strlen(*substring);
                int afterCharacters = (int) strlen(input) - (int) strlen(numbers[i]) - beforeCharacters;

                // printf("before characters %i - after characters %i\n", beforeCharacters, afterCharacters);
                // printf("substring %s\n", *substring);

                for(int j = 0; j < beforeCharacters; j++) {
                    // printf("b j %i\n", j);
                    // printf("%s\n", newInput);
                    newInput[j] = input[j];
                    // printf("%s\n", newInput);
                }

                newInput[beforeCharacters] = i + 1 + '0';

                // printf("replace %s\n", newInput);

                int inputOffset = beforeCharacters + (int) strlen(numbers[i]);
                // printf("offset %i\n", inputOffset);

                for(int j = inputOffset; j < inputOffset + afterCharacters; j++) {
                    int newInputIndex = j - (int) strlen(numbers[i] + 1);
                    // printf("newInputIndex %i\n", newInputIndex);
                    // printf("%s\n", newInput);
                    // printf("j - %i\n", j);
                    newInput[newInputIndex] = input[j];
                    // printf("%s\n", newInput);
                }

                // printf("before copy %s\n", newInput);
                strcpy(input, newInput);
            }
        }
        // count++;
        printf("%s\n", input);
        count++;
    }
}

// one
// two
// three
// four
// five
// six
// seven
// eight
// nine





