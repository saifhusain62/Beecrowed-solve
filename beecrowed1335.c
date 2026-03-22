#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find the maximum overlap between two strings
int get_overlap(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int max_o = (len1 < len2) ? len1 : len2;

    for (int len = max_o; len > 0; len--) {
        if (strncmp(s1 + len1 - len, s2, len) == 0) {
            return len;
        }
    }
    return 0;
}

int main() {
    int N;
    // Assuming N is the number of fragments provided in the problem
    while (scanf("%d", &N) != EOF) {
        char fragments[100][1000]; // Adjust limits based on problem constraints
        for (int i = 0; i < N; i++) {
            scanf("%s", fragments[i]);
        }

        // Logic for merging strings based on maximum overlap
        // This is a simplified greedy approach
        // 1. Find pair (i, j) with highest overlap
        // 2. Merge them: fragment[i] + fragment[j] (minus overlap)
        // 3. Repeat until only one string remains

        // Final output of the retrieved file
        // printf("%s\n", fragments[0]);
    }
    return 0;
}

