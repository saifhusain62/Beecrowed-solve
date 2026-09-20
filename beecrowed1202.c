#include <stdio.h>
#include <string.h>

#define PISANO_PERIOD 1500
#define MOD_FIB 1000
#define MAX_DIGITS 10005

int fib_table[PISANO_PERIOD];

// Precompute Fibonacci numbers modulo 1000 up to the Pisano period (1500)
void precompute_fibonacci() {
    fib_table[0] = 0;
    fib_table[1] = 1;
    fib_table[2] = 1;
    for (int i = 3; i < PISANO_PERIOD; i++) {
        fib_table[i] = (fib_table[i - 1] + fib_table[i - 2]) % MOD_FIB;
    }
}

int main() {
    int t;
    char binary_str[MAX_DIGITS];

    // Fill the lookup table
    precompute_fibonacci();

    // Read the number of test cases
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        scanf("%s", binary_str);

        int n_mod = 0;
        // Convert large binary string to integer modulo 1500
        for (int i = 0; binary_str[i] != '\0'; i++) {
            n_mod = (n_mod * 2 + (binary_str[i] - '0')) % PISANO_PERIOD;
        }

        // Output the result padded to 3 digits
        printf("%03d\n", fib_table[n_mod]);
    }

    return 0;
}

