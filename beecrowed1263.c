#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char line[10000];
    // Read input until EOF
    while (fgets(line, sizeof(line), stdin)) {
        int alliterations = 0;
        char *word;
        char prevChar = '\0', currentChar = '\0';
        int sameCount = 0;
        int inSequence = 0;

        // Tokenize the line by spaces
        word = strtok(line, " \n\r");
        while (word != NULL) {
            currentChar = tolower(word[0]);

            if (currentChar == prevChar) {
                if (!inSequence) {
                    // Start of a new sequence (2nd same char)
                    sameCount = 2;
                    inSequence = 1;
                } else {
                    // Continuation of a sequence
                    sameCount++;
                }
            } else {
                // Character changed
                if (sameCount >= 2) {
                    alliterations++;
                }
                sameCount = 0;
                inSequence = 0;
            }
            prevChar = currentChar;
            word = strtok(NULL, " \n\r");
        }
        // Check for an alliteration at the end of the line
        if (sameCount >= 2) {
            alliterations++;
        }
        printf("%d\n", alliterations);
    }
    return 0;
}

