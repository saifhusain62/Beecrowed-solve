#include <stdio.h>

int main() {
    int N_cases, X, Y, i, j, sum;

    scanf("%d", &N_cases); // Read the number of test cases

    for (i = 0; i < N_cases; i++) {
        scanf("%d %d", &X, &Y); // Read X and Y for each test case
        sum = 0;
        int count = 0;

        // If X is even, increment it to start with the first odd number
        if (X % 2 == 0) {
            X++;
        }

        // Loop to find and sum Y consecutive odd numbers
        for (j = 0; count < Y; j++) {
            sum += X;
            X += 2; // Move to the next odd number
            count++;
        }
        printf("%d\n", sum); // Print the sum for the current test case
    }

    return 0;
}

