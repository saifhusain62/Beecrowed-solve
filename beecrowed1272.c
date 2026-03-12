#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n;
    char line[1000];

    // Read the number of test cases
    if (scanf("%d", &n) != 1) return 0;

    // Consume the newline character left in the buffer by scanf
    getchar();

    while (n--) {
        // Read the entire line (including spaces)
        if (fgets(line, sizeof(line), stdin)) {
            int len = strlen(line);
            int new_word = 1;

            // Iterate through the characters
            for (int i = 0; i < len; i++) {
                // If character is a letter and it's the start of a word
                if (isalpha(line[i])) {
                    if (new_word) {
                        printf("%c", line[i]);
                        new_word = 0;
                    }
                } else if (line[i] == ' ' || line[i] == '\n' || line[i] == '\r') {
                    // Space or newline indicates a new word is coming
                    new_word = 1;
                }
            }
            printf("\n");
        }
    }

    return 0;
}

