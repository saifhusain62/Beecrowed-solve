#include <stdio.h>

int main() {
    int N; // Declare an integer variable to store the input number

    // Read the integer from standard input
    scanf("%d", &N);

    // Print the hexadecimal representation of N using %X
    // %X prints uppercase hexadecimal digits (A-F)
    printf("%X\n", N);

    return 0; // Indicate successful execution
}
