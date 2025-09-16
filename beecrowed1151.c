#include <stdio.h>

int main() {
    int N, a = 0, b = 1, next_term, i;

    // Read the input N
    scanf("%d", &N);

    // Handle the first two terms separately
    if (N >= 1) {
        printf("%d", a);
    }
    if (N >= 2) {
        printf(" %d", b);
    }

    // Generate and print the remaining terms
    for (i = 2; i < N; i++) {
        next_term = a + b;
        printf(" %d", next_term);
        a = b;
        b = next_term;
    }

    printf("\n"); // Newline at the end
    return 0;
}
