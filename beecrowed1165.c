
#include <stdio.h>
#include <math.h>

int main() {
    int N, X, i, is_prime;

    scanf("%d", &N); // Read the number of test cases

    while (N--) {
        scanf("%d", &X); // Read the integer for each test case

        if (X <= 1) { // Numbers less than or equal to 1 are not prime
            is_prime = 0;
        } else if (X == 2) { // 2 is the only even prime number
            is_prime = 1;
        } else if (X % 2 == 0) { // Even numbers greater than 2 are not prime
            is_prime = 0;
        } else {
            is_prime = 1; // Assume prime initially for odd numbers
            for (i = 3; i <= sqrt(X); i += 2) { // Check divisibility by odd numbers up to sqrt(X)
                if (X % i == 0) {
                    is_prime = 0; // Not prime if divisible
                    break;
                }
            }
        }

        if (is_prime) {
            printf("%d eh primo\n", X);
        } else {
            printf("%d nao eh primo\n", X);
        }
    }

    return 0;
}
