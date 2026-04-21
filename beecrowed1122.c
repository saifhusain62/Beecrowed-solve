#include <stdio.h>
#include <string.h>

#define OFFSET 40000
#define MAX_N 41
#define MAX_SUM 80001

int n, t;
int v[MAX_N];
int dp[MAX_N][MAX_SUM];
int can_plus[MAX_N], can_minus[MAX_N];

// Recursive function with memoization
int solve(int idx, int current_sum) {
    if (idx == n) {
        return current_sum == t;
    }

    // Check memoization table (using OFFSET to handle negative sums)
    if (dp[idx][current_sum + OFFSET] != -1) {
        return dp[idx][current_sum + OFFSET];
    }

    int res = 0;
    // Try adding the value (Income)
    if (solve(idx + 1, current_sum + v[idx])) {
        can_plus[idx] = 1;
        res = 1;
    }
    // Try subtracting the value (Expense)
    if (solve(idx + 1, current_sum - v[idx])) {
        can_minus[idx] = 1;
        res = 1;
    }

    return dp[idx][current_sum + OFFSET] = res;
}

int main() {
    while (scanf("%d %d", &n, &t) && (n || t)) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
            can_plus[i] = 0;
            can_minus[i] = 0;
        }

        // Initialize DP table with -1 (not visited)
        memset(dp, -1, sizeof(dp));

        if (!solve(0, 0)) {
            printf("*\n");
        } else {
            for (int i = 0; i < n; i++) {
                if (can_plus[i] && can_minus[i]) printf("?");
                else if (can_plus[i]) printf("+");
                else printf("-");
            }
            printf("\n");
        }
    }
    return 0;
}

