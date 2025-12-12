#include <stdio.h>

int main() {
    // N represents the number of sides, L represents the length of each side.
    long long int N, L;

    // Read the two input values from the user
    scanf("%lld %lld", &N, &L);

    // Calculate and print the perimeter (N * L)
    printf("%lld\n", N * L);

    return 0;
}

