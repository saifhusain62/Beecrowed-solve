#include <stdio.h>

typedef long long ll;

// Function to count occurrences of digit 'd' in all numbers from 1 to 'n'
ll count_digit(int n, int d) {
    if (n <= 0) return 0;

    ll count = 0;
    ll factor = 1;
    ll lower = 0;
    ll current = 0;
    ll higher = 0;

    while (n / factor > 0) {
        lower = n - (n / factor) * factor;
        current = (n / factor) % 10;
        higher = n / (factor * 10);

        if (current < d) {
            count += higher * factor;
        } else if (current == d) {
            count += higher * factor + lower + 1;
        } else {
            count += (higher + 1) * factor;
        }

        // Special case for digit 0 to exclude leading zeros
        if (d == 0) {
            count -= factor;
        }

        factor *= 10;
    }
    return count;
}

int main() {
    int a, b;
    // Input ends when a and b are both 0
    while (scanf("%d %d", &a, &b) && (a != 0 || b != 0)) {
        // Range is [a, b], so we subtract count(a-1) from count(b)
        for (int i = 0; i <= 9; i++) {
            ll total = count_digit(b, i) - count_digit(a - 1, i);
            printf("%lld%c", total, (i == 9 ? '\n' : ' '));
        }
    }
    return 0;
}

