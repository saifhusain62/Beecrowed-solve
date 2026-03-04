#include <stdio.h>
#include <string.h>

int main() {
    int n; // Number of test cases
    scanf("%d", &n);

    while (n--) {
        char a[1001], b[1001]; // Strings to store the input
        scanf("%s %s", a, b);

        int len_a = strlen(a); // Length of the first string
        int len_b = strlen(b); // Length of the second string

        if (len_b > len_a) {
            printf("nao encaixa\n");
        } else {
            // Check if 'b' is a suffix of 'a'
            int i, j, fits = 1;
            for (i = len_a - len_b, j = 0; j < len_b; i++, j++) {
                if (a[i] != b[j]) {
                    fits = 0; // Does not fit
                    break;
                }
            }
            if (fits) {
                printf("encaixa\n");
            } else {
                printf("nao encaixa\n");
            }
        }
    }
    return 0;
}

