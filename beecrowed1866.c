#include <stdio.h>

int main() {
    int C, N, i;

    // Read the number of test cases
    scanf("%d", &C);

    // Loop through each test case
    while (C--) {
        // Read the number of terms for the current test case
        scanf("%d", &N);

        // If N is even, the sum is 0 (1 - 1 + 1 - 1 = 0)
        if (N % 2 == 0) {
            printf("0\n");
        }
        // If N is odd, the sum is 1 (1 - 1 + 1 = 1)
        else {
            printf("1\n");
        }
    }

    return 0;
}
