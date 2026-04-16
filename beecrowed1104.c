#include <stdio.h>
#include <string.h>

int main() {
    int A, B, i, card;
    while (scanf("%d %d", &A, &B) && (A != 0 || B != 0)) {
        int hasA[100001] = {0};
        int hasB[100001] = {0};
        int uniqueA = 0, uniqueB = 0;
        int onlyA = 0, onlyB = 0;

        for (i = 0; i < A; i++) {
            scanf("%d", &card);
            if (!hasA[card]) {
                hasA[card] = 1;
                uniqueA++;
            }
        }
        for (i = 0; i < B; i++) {
            scanf("%d", &card);
            if (!hasB[card]) {
                hasB[card] = 1;
                uniqueB++;
            }
        }

        // Count unique cards in A not in B
        for (i = 1; i <= 100000; i++) {
            if (hasA[i] && !hasB[i]) onlyA++;
            if (hasB[i] && !hasA[i]) onlyB++;
        }

        if (onlyA < onlyB) printf("%d\n", onlyA);
        else printf("%d\n", onlyB);
    }
    return 0;
}

