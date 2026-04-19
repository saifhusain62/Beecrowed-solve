#include <stdio.h>
#include <string.h>
#include <regex.h>

int main() {
    char pattern[1001];
    char text[1001];
    regex_t regex;
    int n, reti;

    // Read the regular expression pattern
    while (scanf("%s", pattern) != EOF) {
        // Compile the regex
        reti = regcomp(&regex, pattern, REG_EXTENDED);
        if (reti) {
            continue; // Handle compilation error if necessary
        }

        // Read number of test cases/strings for this pattern
        if (scanf("%d", &n) == EOF) break;
        getchar(); // Consume newline

        for (int i = 0; i < n; i++) {
            if (fgets(text, 1001, stdin) == NULL) break;

            // Remove newline character from fgets
            text[strcspn(text, "\r\n")] = 0;

            // Execute regex search
            reti = regexec(&regex, text, 0, NULL, 0);
            if (!reti) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }

        // Free compiled regex memory for the next pattern
        regfree(&regex);
    }

    return 0;
}

