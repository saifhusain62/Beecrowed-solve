#include <stdio.h>

int main() {
    int N[20]; // Declare an array of 20 integers
    int i;     // Loop counter

    // Read 20 integer values into the array
    for (i = 0; i < 20; i++) {
        scanf("%d", &N[i]);
    }

    // Print the array elements in reverse order
    for (i = 19; i >= 0; i--) {
        printf("N[%d] = %d\n", 19 - i, N[i]);
    }

    return 0;
}
