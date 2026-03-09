#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

int main() {
    int n, i;
    // Read the number of test cases
    scanf("%d", &n);
    // Consume the newline character left in the buffer by scanf
    getchar();

    while (n--) {
        char str[201]; // Buffer for the input string (max length 200 + newline + null terminator)
        int max_freq = INT_MIN;
        int counts[26] = {0}; // Array to store counts of each letter 'a' through 'z'

        // Read the entire line of text
        fgets(str, 201, stdin);
        int len = strlen(str);

        for (i = 0; i < len; i++) {
            // Convert character to lowercase
            char c = tolower(str[i]);
            // Check if the character is a lowercase letter
            if (c >= 'a' && c <= 'z') {
                // Increment the count for the corresponding letter
                counts[c - 'a']++;
                // Update the maximum frequency found so far
                if (counts[c - 'a'] > max_freq) {
                    max_freq = counts[c - 'a'];
                }
            }
        }

        // Print all letters that have the maximum frequency
        for (i = 0; i < 26; i++) {
            if (counts[i] == max_freq) {
                printf("%c", i + 'a');
            }
        }
        // Print a newline at the end of each test case output
        printf("\n");
    }

    return 0;
}

