#include <stdio.h>

int main() {
    int A, N;
    int sum = 0;
    int i;

    // Read A and N
    scanf("%d %d", &A, &N);

    // Ensure N is a positive integer
    while (N <= 0) {
        scanf("%d", &N);
    }

    // Calculate the sum of N consecutive integers starting from A
    // The sequence is A, A+1, A+2, ..., A+(N-1)
    for (i = 0; i < N; i++) {
        sum += (A + i);
    }

    // Print the result
    printf("%d\n", sum);

    return 0;
}
