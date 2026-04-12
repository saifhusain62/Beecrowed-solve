#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 105

int dp[MAX][MAX];
char s[MAX];

// Helper to count digits in a number
int count_digits(int n) {
    if (n < 10) return 1;
    if (n < 100) return 2;
    return 3;
}

// Check if S[i..j] is a repetition of S[i..k]
int is_repeat(int i, int j, int k) {
    int len = j - i + 1;
    int sublen = k - i + 1;
    if (len % sublen != 0) return 0;
    for (int p = i + sublen; p <= j; p++) {
        if (s[p] != s[i + (p - i) % sublen]) return 0;
    }
    return 1;
}

int solve(int i, int j) {
    if (i == j) return 1;
    if (dp[i][j] != -1) return dp[i][j];

    int res = j - i + 1; // Default: uncompressed length

    // Case 1: Split the string at every possible point
    for (int k = i; k < j; k++) {
        int temp = solve(i, k) + solve(k + 1, j);
        if (temp < res) res = temp;
    }

    // Case 2: Check for repeating patterns
    for (int k = i; k < j; k++) {
        int sublen = k - i + 1;
        if (is_repeat(i, j, k)) {
            int repeats = (j - i + 1) / sublen;
            int temp = 2 + count_digits(repeats) + solve(i, k);
            if (temp < res) res = temp;
        }
    }

    return dp[i][j] = res;
}

int main() {
    while (scanf("%s", s) != EOF) {
        int n = strlen(s);
        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(0, n - 1));
    }
    return 0;
}

