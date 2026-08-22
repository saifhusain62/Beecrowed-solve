#include <stdio.h>
#include <stdlib.h>

// Comparison function for ascending order (Even numbers)
int compare_even(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Comparison function for descending order (Odd numbers)
int compare_odd(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *evens = (int*)malloc(n * sizeof(int));
    int *odds = (int*)malloc(n * sizeof(int));

    int even_count = 0;
    int odd_count = 0;
    int num;

    // Separate numbers into even and odd arrays
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &num) == 1) {
            if (num % 2 == 0) {
                evens[even_count++] = num;
            } else {
                odds[odd_count++] = num;
            }
        }
    }

    // Sort even numbers in ascending order
    qsort(evens, even_count, sizeof(int), compare_even);

    // Sort odd numbers in descending order
    qsort(odds, odd_count, sizeof(int), compare_odd);

    // Print sorted even numbers
    for (int i = 0; i < even_count; i++) {
        printf("%d\n", evens[i]);
    }

    // Print sorted odd numbers
    for (int i = 0; i < odd_count; i++) {
        printf("%d\n", odds[i]);
    }

    // Free allocated memory
    free(evens);
    free(free_odds);

    return 0;
}

