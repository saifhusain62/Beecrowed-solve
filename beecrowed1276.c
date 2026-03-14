#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void solve() {
    char line[200];
    // Read input lines until EOF
    while (fgets(line, sizeof(line), stdin)) {
        bool present[26] = {false};
        bool has_letters = false;

        // Mark present letters
        for (int i = 0; line[i] != '\0' && line[i] != '\n' && line[i] != '\r'; i++) {
            if (line[i] >= 'a' && line[i] <= 'z') {
                present[line[i] - 'a'] = true;
                has_letters = true;
            }
        }

        if (!has_letters) {
            printf("\n");
            continue;
        }

        bool first_range = true;
        int start = -1;

        // Find and print ranges
        for (int i = 0; i < 26; i++) {
            if (present[i]) {
                if (start == -1) start = i;
            } else {
                if (start != -1) {
                    if (!first_range) printf(", ");
                    if (start == i - 1) printf("%c:%c", 'a' + start, 'a' + i - 1);
                    else printf("%c:%c", 'a' + start, 'a' + i - 1);
                    first_range = false;
                    start = -1;
                }
            }
        }
        // Print the last range if exists
        if (start != -1) {
            if (!first_range) printf(", ");
            printf("%c:%c", 'a' + start, 'a' + 25);
        }
        printf("\n");
    }
}

int main() {
    solve();
    return 0;
}

