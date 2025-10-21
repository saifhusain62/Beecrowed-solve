#include <stdio.h>

int main() {
    char operation;
    double M[12][12];
    double sum = 0.0;
    int count = 0;

    // Read the operation character ('S' for sum, 'M' for average)
    scanf("%c", &operation);

    // Read the 12x12 matrix elements
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }

    // Calculate sum of elements in the top area
    for (int i = 0; i < 5; i++) { // Iterate through the first 5 rows (0 to 4)
        for (int j = i + 1; j < 11 - i; j++) { // Elements above main and secondary diagonals
            sum += M[i][j];
            count++;
        }
    }

    // Print the result based on the operation
    if (operation == 'S') {
        printf("%.1lf\n", sum);
    } else if (operation == 'M') {
        printf("%.1lf\n", sum / count);
    }

    return 0;
}
