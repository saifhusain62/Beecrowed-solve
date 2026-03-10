#include <stdio.h>
#include <string.h>

int main() {
    int n, l, i, j, k;
    char s[55];
    long long total_hash;

    // Read number of test cases
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        // Read number of lines in current test case
        if (scanf("%d", &l) != 1) break;

        total_hash = 0;

        for (i = 0; i < l; i++) {
            scanf("%s", s);
            for (j = 0; j < strlen(s); j++) {
                // formula: alphabetical position (0-25) + string index + position in string
                total_hash += (s[j] - 'A') + i + j;
            }
        }
        printf("%lld\n", total_hash);
    }

    return 0;
}

