#include <stdio.h>

int main() {
    int i, j, k = 0;
    char operation_type;
    float matrix[12][12], sum = 0.0, average = 0.0;

    // Read the operation type ('S' or 'M')
    scanf(" %c", &operation_type); // Note the space before %c to consume any leftover newline

    // Read the 12x12 matrix
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Calculate sum of elements above the secondary diagonal
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            // The secondary diagonal elements satisfy i + j = 11.
            // Elements above the secondary diagonal satisfy i + j < 11,
            // or equivalently, j < (11 - i).
            if (j < (11 - i)) {
                sum += matrix[i][j];
                k++; // Count of elements added
            }
        }
    }

    // Print the result based on the operation type
    if (operation_type == 'S') {
        printf("%.1f\n", sum);
    } else if (operation_type == 'M') {
        if (k > 0) { // Avoid division by zero if no elements are found (though not expected for this problem)
            average = sum / k;
        }
        printf("%.1f\n", average);
    }

    return 0;
}
