#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, max_len, first = 1;
    char words[50][51];

    while (scanf("%d", &n) && n != 0) {
        // Print a blank line between test cases
        if (!first) {
            printf("\n");
        }
        first = 0;

        max_len = 0;
        for (i = 0; i < n; i++) {
            scanf("%s", words[i]);
            int len = strlen(words[i]);
            if (len > max_len) {
                max_len = len;
            }
        }

        for (i = 0; i < n; i++) {
            int len = strlen(words[i]);
            // Calculate and print required leading spaces
            for (j = 0; j < (max_len - len); j++) {
                printf(" ");
            }
            printf("%s\n", words[i]);
        }
    }

    return 0;
}

