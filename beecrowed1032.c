#include <stdio.h>
#include <stdbool.h>

#define MAX_PRIMES 3502
#define MAX_LIMIT 33000

int primes[MAX_PRIMES];

// 1. Generate the list of prime numbers
void generate_primes() {
    bool is_prime[MAX_LIMIT];
    for (int i = 0; i < MAX_LIMIT; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;

    int count = 0;
    for (int p = 2; count < MAX_PRIMES; p++) {
        if (is_prime[p]) {
            primes[count++] = p;
            for (int i = p * 2; i < MAX_LIMIT; i += p)
                is_prime[i] = false;
        }
    }
}

// 2. Josephus recursive variation (Iterative implementation)
int solve_josephus(int n) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        // Use the prime corresponding to the current number of people
        // working backwards from 1 to n
        res = (res + primes[n - i]) % i;
    }
    return res + 1; // Return 1-based position
}

int main() {
    generate_primes();
    int n;

    // 3. Process inputs until n = 0
    while (scanf("%d", &n) == 1 && n != 0) {
        printf("%d\n", solve_josephus(n));
    }

    return 0;
}

