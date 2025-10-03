#include <stdio.h>

int main() {
    int N[20]; // Declare an array of 20 integers
    int i;

    // Read 20 integer values into the array
    for (i = 0; i < 20; i++) {
        scanf("%d", &N[i]);
    }

    // Print the array in reverse order
    for (i = 0; i < 20; i++) {
        printf("N[%d] = %d\n", i, N[19 - i]);
    }

    return 0;
}
