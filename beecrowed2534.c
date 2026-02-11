#include <stdio.h>
#include <stdlib.h>

// Function to compare integers for qsort (descending order)
int compareDesc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n, q;

    // Read N (citizens) and Q (queries) until EOF
    while (scanf("%d %d", &n, &q) != EOF) {
        int grades[n];

        // Read grades
        for (int i = 0; i < n; i++) {
            scanf("%d", &grades[i]);
        }

        // Sort grades descending
        qsort(grades, n, sizeof(int), compareDesc);

        // Process queries
        for (int i = 0; i < q; i++) {
            int pos;
            scanf("%d", &pos);
            // Output grade at position (1-indexed)
            printf("%d\n", grades[pos - 1]);
        }
    }

    return 0;
}

