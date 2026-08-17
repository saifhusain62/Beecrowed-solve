#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print a decimal number in binary format
void print_binary(unsigned int num) {
    char binary[33];
    int index = 0;

    // Build binary string backwards
    if (num == 0) {
        binary[index++] = '0';
    } else {
        while (num > 0) {
            binary[index++] = (num % 2) + '0';
            num /= 2;
        }
    }
    binary[index] = '\0';

    // Print backwards to get correct order
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", binary[i]);
    }
    printf(" bin\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char value[50];
    char base[10];

    for (int i = 1; i <= n; i++) {
        scanf("%s %s", value, base);
        unsigned int decimal_val = 0;

        printf("Case %d:\n", i);

        // Parse input value according to its base indicator
        if (strcmp(base, "dec") == 0) {
            // Convert string to base 10 unsigned integer
            decimal_val = (unsigned int)strtoul(value, NULL, 10);

            // Output Hex and Bin formats
            printf("%x hex\n", decimal_val);
            print_binary(decimal_val);
        }
        else if (strcmp(base, "bin") == 0) {
            // Convert string to base 2 unsigned integer
            decimal_val = (unsigned int)strtoul(value, NULL, 2);

            // Output Dec and Hex formats
            printf("%u dec\n", decimal_val);
            printf("%x hex\n", decimal_val);
        }
        else if (strcmp(base, "hex") == 0) {
            // Convert string to base 16 unsigned integer
            decimal_val = (unsigned int)strtoul(value, NULL, 16);

            // Output Dec and Bin formats
            printf("%u dec\n", decimal_val);
            print_binary(decimal_val);
        }

        // Print a trailing blank line after every case
        printf("\n");
    }

    return 0;
}

