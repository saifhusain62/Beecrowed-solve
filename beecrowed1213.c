#include <stdio.h>

int main() {
    long long int n;

    // Read input until End-Of-File (EOF)
    while (scanf("%lld", &n) == 1) {
        long long int remainder = 1;
        long long int digit_count = 1;

        // Loop until the number is completely divisible by n
        while (remainder % n != 0) {
            remainder = (remainder * 10 + 1) % n;
            digit_count++;
        }

        // Print the total number of digits
        printf("%lld\n", digit_count);
    }

    return 0;
}

