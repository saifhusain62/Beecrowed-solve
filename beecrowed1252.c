#include <stdio.h>
#include <stdlib.h>

// Global variable for the modulo value, accessible by the comparator
int M;

// Comparator function for qsort
int compare(const void *a, const void *b) {
    int num1 = *(const int *)a;
    int num2 = *(const int *)b;

    // Rule 1: Sort by remainder in ascending order
    int rem1 = num1 % M;
    int rem2 = num2 % M;

    if (rem1 != rem2) {
        return (rem1 < rem2) ? -1 : 1;
    }

    // Determine odd/even status (using bitwise or %2 logic)
    // A number is odd if its remainder with 2 is not 0
    int is_odd1 = (num1 % 2 != 0);
    int is_odd2 = (num2 % 2 != 0);

    // Rule 2: If one is odd and the other is even, the odd one comes first
    if (is_odd1 != is_odd2) {
        return is_odd1 ? -1 : 1;
    }

    // Rule 3: If both are odd, sort in descending order
    if (is_odd1 && is_odd2) {
        if (num1 > num2) return -1;
        if (num1 < num2) return 1;
        return 0;
    }

    // Rule 4: If both are even, sort in ascending order
    if (!is_odd1 && !is_odd2) {
        if (num1 < num2) return -1;
        if (num1 > num2) return 1;
        return 0;
    }

    return 0;
}

int main() {
    int N;
    int arr[10005];

    // Read until N = 0 and M = 0
    while (scanf("%d %d", &N, &M) == 2 && (N != 0 || M != 0)) {
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        // Sort the array using the custom comparator
        qsort(arr, N, sizeof(int), compare);

        // Print header for the testcase
        printf("%d %d\n", N, M);

        // Print sorted elements
        for (int i = 0; i < N; i++) {
            printf("%d\n", arr[i]);
        }
    }

    // Print the final stopping condition wrapper
    printf("0 0\n");

    return 0;
}

