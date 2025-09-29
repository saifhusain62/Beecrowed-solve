#include <stdio.h>

int main() {
    int X[10]; // Declare an array of 10 integers
    int i;     // Loop counter

    // Read 10 integer values into the array
    for (i = 0; i < 10; i++) {
        scanf("%d", &X[i]);
    }

    // Iterate through the array and replace values <= 0 with 1
    for (i = 0; i < 10; i++) {
        if (X[i] <= 0) {
            X[i] = 1;
        }
    }

    // Print the modified array in the specified format
    for (i = 0; i < 10; i++) {
        printf("X[%d] = %d\n", i, X[i]);
    }

    return 0;
}
