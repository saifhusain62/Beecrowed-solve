#include <stdio.h>

// Function to calculate the Josephus survivor (0-indexed)
int getSurvivor(int n, int k) {
    if (n == 1) return 0;
    return (getSurvivor(n - 1, k) + k) % n;
}

int main() {
    int NC, n, k;
    if (scanf("%d", &NC) != 1) return 0;

    for (int i = 1; i <= NC; ++i) {
        scanf("%d %d", &n, &k);
        // Add 1 to convert from 0-indexed to 1-indexed
        printf("Case %d: %d\n", i, getSurvivor(n, k) + 1);
    }

    return 0;
}

