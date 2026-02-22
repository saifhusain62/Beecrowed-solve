#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to compare strings for qsort (shorter first)
int compare(const void *a, const void *b) {
    return strlen((char *)a) - strlen((char *)b);
}

// Function to check if 'sub' is a substring of 'mainStr'
int isSubstring(char *sub, char *mainStr) {
    return strstr(mainStr, sub) != NULL;
}

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        char strings[n][1005];
        int dp[n];
        int maxChain = 0;

        for (int i = 0; i < n; i++) {
            scanf("%s", strings[i]);
            dp[i] = 1; // Minimum chain length is 1
        }

        // 1. Sort strings by length
        qsort(strings, n, sizeof(strings[0]), compare);

        // 2. Dynamic Programming
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (strstr(strings[i], strings[j]) != NULL) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            if (dp[i] > maxChain) {
                maxChain = dp[i];
            }
        }
        printf("%d\n", maxChain);
    }
    return 0;
}

