#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n); // Read the input number N (1 <= N < 1000)

    // Define Roman numeral symbols and their values in descending order
    int values[] = {900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char* symbols[] = {"CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i;

    // Iterate through the values and symbols to build the Roman numeral string
    for (i = 0; i < 12; i++) {
        while (n >= values[i]) {
            printf("%s", symbols[i]);
            n -= values[i];
        }
    }

    printf("\n"); // Print a newline character at the end
    return 0;
}

