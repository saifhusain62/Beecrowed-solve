#include <stdio.h>
#include <math.h>

int is_prime(long long num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0; // Exclude even numbers early

    long long root = sqrt(num);
    for (long long i = 3; i <= root; i += 2) {
        if (num % i == 0) {
            return 0; // Found a divisor, not prime
        }
    }
    return 1; // Prime
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        long long num;
        scanf("%lld", &num);

        if (is_prime(num)) {
            printf("Prime\n");
        } else {
            printf("Not Prime\n");
        }
    }

    return 0;
}

