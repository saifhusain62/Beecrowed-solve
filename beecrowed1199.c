#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[50];

    // Read input until End-Of-File (EOF)
    while (scanf("%s", input) != EOF) {
        // A negative number terminates the execution
        if (input[0] == '-') {
            break;
        }

        // Check if the input is a Hexadecimal number (starts with '0x')
        if (strlen(input) > 1 && input[1] == 'x') {
            // Convert Hexadecimal string to Decimal (base 16)
            long long int hexValue = strtoll(input, NULL, 16);
            printf("%lld\n", hexValue);
        } else {
            // Convert Decimal string to Hexadecimal (base 10)
            long long int decValue = strtoll(input, NULL, 10);
            // Print with '0x' prefix and uppercase letters (%X)
            printf("0x%llX\n", decValue);
        }
    }

    return 0;
}

