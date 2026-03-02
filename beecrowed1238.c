#include <stdio.h>
#include <string.h>

int main() {
    int N;
    char str1[51], str2[51];

    // Read number of test cases
    if (scanf("%d", &N) != 1) return 0;

    while (N--) {
        scanf("%s %s", str1, str2);

        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int i = 0;

        // Iterate until the end of the shorter string
        while (i < len1 && i < len2) {
            printf("%c%c", str1[i], str2[i]);
            i++;
        }

        // Print remaining characters if str1 is longer
        if (i < len1) {
            printf("%s", &str1[i]);
        }
        // Print remaining characters if str2 is longer
        else if (i < len2) {
            printf("%s", &str2[i]);
        }

        printf("\n");
    }

    return 0;
}

