#include <stdio.h>
#include <string.h>

// Function to map characters to their corresponding integer values
int char_to_val(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 36;
    return -1; // For signs like '-' or '+'
}

int main() {
    char s[4096]; // Buffer large enough to hold the input string

    while (scanf("%s", s) != EOF) {
        int max_digit = 0;
        int len = strlen(s);
        int sum = 0;

        for (int i = 0; i < len; i++) {
            int val = char_to_val(s[i]);
            if (val < 0) continue; // Skip signs like '-' or '+'
            
            if (val > max_digit) {
                max_digit = val;
            }
            sum += val;
        }

        // Base must be at least 2, and strictly greater than the largest digit found
        int start_base = max_digit + 1;
        if (start_base < 2) start_base = 2;

        int found = 0;
        for (int b = start_base; b <= 62; b++) {
            if (sum % (b - 1) == 0) {
                printf("%d\n", b);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("such number is impossible!\n");
        }
    }
    return 0;
}
