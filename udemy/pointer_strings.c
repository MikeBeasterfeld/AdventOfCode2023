#include <stdio.h>

void copyString(char to[], char from[]) {\
    int i;
    
    for(i = 0; from[i] != '\0'; ++i) {
        to[i] = from[i];

    }

    to[i] = '\0';
}


void copyStringPointers(char *to, char *from) {
    for( ; *from != '\0'; ++from, ++to) {
        *to = *from;
    }

    *to = '\0';
}


void copyStringPointersRefactored(char *to, char *from) {
    while( *from ) {
        *to++ = *from++;
    }

    *to = '\0';
}

int main(void) {
    char string1[] = "A string to be copied.";
    char string2[50];
    copyStringPointersRefactored(string2, string1);
    printf("%s\n", string2);
}
