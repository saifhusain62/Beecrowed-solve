#include <stdio.h>

int main() {
    unsigned short cartaA, cartaB; // Declare two unsigned short integers to store the card values

    // Read the two card values from standard input
    scanf("%hu %hu", &cartaA, &cartaB);

    // Compare the two values and print the larger one
    if (cartaA >= cartaB) {
        printf("%hu\n", cartaA);
    } else {
        printf("%hu\n", cartaB);
    }

    return 0; // Indicate successful execution
}
