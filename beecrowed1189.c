#include <stdio.h>

int main() {
    int i, j, count = 0;
    char operation;
    float matrix[12][12], sum = 0.0;

    // Read the operation character ('S' for sum, 'M' for average)
    scanf("%c", &operation);

    // Read the 12x12 matrix elements
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Calculate sum of elements in the "left area"
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            // Condition for the "left area"
            // For the upper half (rows 0-5), elements where j < i
            // For the lower half (rows 6-11), elements where j < (11 - i)
            if ((i < 6 && j < i) || (i >= 6 && j < (11 - i))) {
                sum += matrix[i][j];
                count++;
            }
        }
    }

    // Print the result based on the operation
    if (operation == 'S') {
        printf("%.1f\n", sum);
    } else if (operation == 'M') {
        printf("%.1f\n", sum / count);
    }

    return 0;
}
