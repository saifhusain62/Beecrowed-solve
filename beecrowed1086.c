#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a); // Sort descending
}

int solve(int target_len, int rows_needed, int planks[], int K) {
    int i = 0, j = K - 1, count = 0, rows_filled = 0;

    while (i <= j && rows_filled < rows_needed) {
        if (planks[i] == target_len) {
            count++;
            rows_filled++;
            i++;
        } else if (i < j && planks[i] + planks[j] == target_len) {
            count += 2;
            rows_filled++;
            i++;
            j--;
        } else if (i < j && planks[i] + planks[j] < target_len) {
            j--; // Try a larger plank for the second half
        } else {
            i++; // Current plank too long to pair with anything
        }
    }
    return (rows_filled == rows_needed) ? count : 2e9;
}

int main() {
    int N, M, L, K;
    while (scanf("%d %d", &N, &M) && (N || M)) {
        scanf("%d %d", &L, &K);
        int planks[K];
        for (int i = 0; i < K; i++) scanf("%d", &planks[i]);
        qsort(planks, K, sizeof(int), compare);

        int res1 = 2e9, res2 = 2e9;

        // Try covering along side N (planks length M)
        if ((N * 100) % L == 0)
            res1 = solve(M, (N * 100) / L, planks, K);

        // Try covering along side M (planks length N)
        if ((M * 100) % L == 0)
            res2 = solve(N, (M * 100) / L, planks, K);

        int final_res = (res1 < res2) ? res1 : res2;
        if (final_res >= 2e9) printf("impossivel\n");
        else printf("%d\n", final_res);
    }
    return 0;
}

