#include <stdio.h>
#include <string.h>

// Note: This is a conceptual structure based on backtracking/memoization approach
// A full implementation requires handling input/output and recursion limit

int main() {
    int m, s;
    while (scanf("%d %d", &m, &s) == 2 && (m != 0 || s != 0)) {
        char emoticons[m][105];
        char message[10005];

        for (int i = 0; i < m; i++) {
            scanf("%s", emoticons[i]);
        }

        // Handle multi-line message input (potentially using fgets)
        // ... (implementation of backtracking to find min changes) ...

        printf("%d\n", 0); // Placeholder for result
    }
    return 0;
}

