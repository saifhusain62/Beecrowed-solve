#include <stdio.h>

int main() {
    int N, i, value;
    int min_value = 1001; // Constraints state values are between 1 and 1000
    int min_index = -1;

    scanf("%d", &N); // Read the number of values

    for (i = 0; i < N; i++) {
        scanf("%d", &value); // Read each value

        if (value < min_value) {
            min_value = value;
            min_index = i + 1; // Store 1-based index
        }
    }

    printf("%d\n", min_index); // Print the 1-based index of the smallest value

    return 0;
}
