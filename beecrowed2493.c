#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store expressions
typedef struct {
    int x, y, z;
} Expression;

// Function to check if the operator is correct
char getCorrectOp(int x, int y, int z) {
    if (x + y == z) return '+';
    if (x - y == z) return '-';
    if (x * y == z) return '*';
    return 'I'; // Invalid/None
}

// Comparator for sorting names alphabetically
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        Expression exprs[n];
        for (int i = 0; i < n; i++) {
            scanf("%d %d=%d", &exprs[i].x, &exprs[i].y, &exprs[i].z);
        }

        char failedNames[n][51];
        int failCount = 0;
        char name[51];
        int exprIdx;
        char op;

        for (int i = 0; i < n; i++) {
            scanf("%s %d %c", name, &exprIdx, &op);
            char correct = getCorrectOp(exprs[exprIdx - 1].x, exprs[exprIdx - 1].y, exprs[exprIdx - 1].z);
            if (correct != op) {
                strcpy(failedNames[failCount], name);
                failCount++;
            }
        }

        if (failCount == 0) {
            printf("You Shall All Pass!\n");
        } else {
            // Sort failed players
            qsort(failedNames, failCount, sizeof(failedNames[0]), compare);
            for (int i = 0; i < failCount; i++) {
                printf("%s%s", failedNames[i], (i == failCount - 1) ? "" : " ");
            }
            printf("\n");
        }
    }
    return 0;
}

