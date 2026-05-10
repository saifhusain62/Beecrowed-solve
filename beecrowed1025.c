#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort to sort marbles in ascending order
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Binary search to find the FIRST occurrence of a marble
int findFirst(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid + 1; // Store index (1-based)
            right = mid - 1;  // Keep looking left for the first occurrence
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int N, Q, caseNum = 1;
    while (scanf("%d %d", &N, &Q) && (N != 0 || Q != 0)) {
        int marbles[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &marbles[i]);
        }

        // 1. Sort the marbles
        qsort(marbles, N, sizeof(int), compare);

        printf("CASE# %d:\n", caseNum++);

        // 2. Process each query
        for (int i = 0; i < Q; i++) {
            int query;
            scanf("%d", &query);
            int pos = findFirst(marbles, N, query);
            if (pos != -1) {
                printf("%d found at %d\n", query, pos);
            } else {
                printf("%d not found\n", query);
            }
        }
    }
    return 0;
}

