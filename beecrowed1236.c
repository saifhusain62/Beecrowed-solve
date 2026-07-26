#include <stdio.h>
#include <string.h>

#define MAX_LIMIT 2005

// Helper function to process and print compressed or literal blocks
void print_block(char ch, int count) {
    while (count > 0) {
        // If it qualifies for compression (> 2 remaining)
        if ((ch == '0' || ch == ' ') && count > 2) {
            int chunk = (count > 255) ? 255 : count;
            if (ch == '0') {
                printf("~%c", (char)chunk);
            } else {
                printf("$%c", (char)chunk);
            }
            count -= chunk;
        } else {
            // Print remaining uncompressed characters as literals
            for (int i = 0; i < count; i++) {
                putchar(ch);
            }
            break;
        }
    }
}

int main() {
    int t;
    char line[MAX_LIMIT];

    // Read the total number of test cases
    if (scanf("%d", &t) != 1) return 0;

    // Consume the trailing newline left in the buffer by scanf
    getchar();

    while (t--) {
        // Read the entire line including spaces
        if (fgets(line, sizeof(line), stdin) == NULL) break;

        // Strip the trailing newline character added by fgets
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }

        if (len == 0) {
            printf("\n");
            continue;
        }

        char current_char = line[0];
        int current_count = 1;

        // Traverse the string to look for contiguous identical segments
        for (int i = 1; i < len; i++) {
            if (line[i] == current_char) {
                current_count++;
            } else {
                print_block(current_char, current_count);
                current_char = line[i];
                current_count = 1;
            }
        }
        // Flush out the last tracked block
        print_block(current_char, current_count);
        printf("\n");
    }

    return 0;
}

