#include <stdio.h>

int main() {
    int T; // The input value to determine the sequence length
    int N[1000]; // The array to be filled
    int i; // Loop counter for array index
    int current_value = 0; // The current value to be inserted into the array

    // Read the input value T
    scanf("%d", &T);

    // Loop through the array from index 0 to 999
    for (i = 0; i < 1000; i++) {
        // Assign the current_value to the current array element
        N[i] = current_value;

        // Print the output in the required format
        printf("N[%d] = %d\n", i, N[i]);

        // Increment current_value
        current_value++;

        // If current_value reaches T, reset it to 0 to repeat the sequence
        if (current_value == T) {
            current_value = 0;
        }
    }

    return 0;
}
