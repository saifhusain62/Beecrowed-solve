#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1001]; // Buffer to hold the input string (max 1000 chars + null terminator)

    // Read input line by line until end-of-file
    while (fgets(s, sizeof(s), stdin) != NULL) {
        int c = 0; // Counter to track the case (0 for uppercase, 1 for lowercase)
        // Remove newline character if it exists
        s[strcspn(s, "\n")] = 0;
        int tam = strlen(s);

        for (int i = 0; i < tam; i++) {
            if (isalpha(s[i])) {
                if (c % 2 == 0) {
                    s[i] = toupper(s[i]);
                } else {
                    s[i] = tolower(s[i]);
                }
                c++; // Increment counter only for alphabetic characters
            }
        }
        printf("%s\n", s);
    }
    return 0;
}

