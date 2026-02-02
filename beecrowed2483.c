#include <stdio.h>

int main() {
    int I, i;

    // Read the input integer I
    if (scanf("%d", &I) != 1) return 1;

    // Print the first part of the phrase
    printf("Feliz nat");

    // Print 'a' exactly I times
    for (i = 0; i < I; i++) {
        printf("a");
    }

    // Print the last part of the phrase and a newline
    printf("l!\n");

    return 0;
}

