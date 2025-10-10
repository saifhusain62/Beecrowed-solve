#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N); // Read the size of the array

    int X[N]; // Declare an array of size N
    int min_value;
    int min_position;

    // Read array elements and initialize min_value and min_position with the first element
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
        if (i == 0) {
            min_value = X[i];
            min_position = i;
        }
    }

    // Iterate through the array to find the lowest number and its position
    for (int i = 1; i < N; i++) { // Start from the second element as the first is already handled
        if (X[i] < min_value) {
            min_value = X[i];
            min_position = i;
        }
    }

    // Print the results
    printf("Menor valor: %d\n", min_value);
    printf("Posicao: %d\n", min_position);

    return 0;
}
