#include <stdio.h>
#include <string.h>

// Function to find the length of the longest common substring
int longestCommonSubstring(char *str1, char *str2, int sizeOfstr1, int sizeOfstr2) {
    int maxSize = 0;
    // Brute-force: compare all possible substrings
    for (int i = 0; i < sizeOfstr1; i++) {
        for (int j = 0; j < sizeOfstr2; j++) {
            int currentSize = 0;
            for (int x = i, y = j; x < sizeOfstr1 && y < sizeOfstr2 && str1[x] == str2[y]; x++, y++) {
                currentSize++;
            }
            if (currentSize > maxSize) maxSize = currentSize;
        }
    }
    return maxSize;
}

int main() {
    char str1[51], str2[51];
    // Reads input lines with spaces until EOF
    while (scanf(" %50[^\n] %50[^\n]", str1, str2) != EOF) {
        printf("%d\n", longestCommonSubstring(str1, str2, strlen(str1), strlen(str2)));
    }
    return 0;
}

