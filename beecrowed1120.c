#include <stdio.h>
#include <string.h>

int main() {
    char d, n[105];
    while (scanf(" %c %s", &d, n) == 2) {
        if (d == '0' && n[0] == '0') break;

        char result[105];
        int j = 0;
        int len = strlen(n);

        // Remove digit 'd'
        for (int i = 0; i < len; i++) {
            if (n[i] != d) {
                result[j++] = n[i];
            }
        }
        result[j] = '\0'; // Null terminate the result string

        // Handle empty result or all zeros
        int start = 0;
        while (result[start] == '0' && result[start] != '\0') {
            start++;
        }

        if (result[start] == '\0') {
            printf("0\n"); // If empty or all zeros, print 0
        } else {
            printf("%s\n", &result[start]); // Print result skipping leading zeros
        }
    }
    return 0;
}

