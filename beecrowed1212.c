#include <stdio.h>

int main() {
    unsigned long a, b;

    // Read pairs of numbers until both are 0
    while (scanf("%lu %lu", &a, &b) == 2) {
        if (a == 0 && b == 0) {
            break;
        }

        int carry = 0;
        int carry_count = 0;

        // Process digits as long as numbers remain or a carry is left over
        while (a > 0 || b > 0) {
            int digit_a = a % 10;
            int digit_b = b % 10;

            int sum = digit_a + digit_b + carry;

            if (sum >= 10) {
                carry = 1;
                carry_count++;
            } else {
                carry = 0;
            }

            a /= 10;
            b /= 10;
        }

        // Print the result matching the formatting guidelines
        if (carry_count == 0) {
            printf("No carry operation.\n");
        } else if (carry_count == 1) {
            printf("1 carry operation.\n");
        } else {
            printf("%d carry operations.\n", carry_count);
        }
    }

    return 0;
}

