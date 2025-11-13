#include <stdio.h>

int main() {
    char operation;
    scanf("%c", &operation);

    double matrix[12][12];
    double sum = 0.0;
    int count = 0;

    // Read matrix elements
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Calculate sum of elements below the main diagonal
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (i > j) { // Condition for elements below the main diagonal
                sum += matrix[i][j];
                count++;
            }
        }
    }

    // Print result based on operation
    if (operation == 'S') {
        printf("%.1lf\n", sum);
    } else if (operation == 'M') {
        printf("%.1lf\n", sum / count);
    }

    return 0;
}
