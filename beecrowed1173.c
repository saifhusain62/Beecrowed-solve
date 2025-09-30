#include <stdio.h>

int main() {
    int N[10]; // Declare an array of size 10
    int V;     // Declare a variable to store the input value

    // Read the integer value V
    scanf("%d", &V);

    // Fill the array N
    N[0] = V; // The first element is V
    for (int i = 1; i < 10; i++) {
        N[i] = N[i - 1] * 2; // Each subsequent element is twice the previous one
    }

    // Print the array elements
    for (int i = 0; i < 10; i++) {
        printf("N[%d] = %d\n", i, N[i]);
    }

    return 0;
}
