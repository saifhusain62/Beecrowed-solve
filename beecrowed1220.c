#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Comparison function for qsort to sort expenses in ascending order
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;

    // Read until the number of students is 0
    while (scanf("%d", &n) == 1 && n != 0) {
        int *expenses = (int*)malloc(n * sizeof(int));
        long long total = 0;

        for (int i = 0; i < n; i++) {
            double val;
            scanf("%lf", &val);
            // Convert to cents and round properly to avoid float precision issues
            expenses[i] = (int)(val * 100.0 + 0.5);
            total += expenses[i];
        }

        // Sort the expenses
        qsort(expenses, n, sizeof(int), compare);

        int avg = total / n;
        int rem = total % n;
        long long total_diff = 0;

        // Calculate the minimum money to change hands
        for (int i = 0; i < n; i++) {
            int target = (i < n - rem) ? avg : (avg + 1);
            total_diff += abs(expenses[i] - target);
        }

        long long final_cents = total_diff / 2;

        // Print formatted output strictly using integer arithmetic to avoid float issues
        printf("$%lld.%02lld\n", final_cents / 100, final_cents % 100);

        free(expenses);
    }

    return 0;
}

