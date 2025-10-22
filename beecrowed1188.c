#include <stdio.h>

int main() {
    char O; // Operation: 'S' for Sum, 'M' for Mean
    scanf("%c", &O);

    double M[12][12];
    double sum = 0.0;
    int count = 0;

    // Read the matrix
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }

    // Calculate sum of elements in the inferior area
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            // Check if the element is in the inferior area
            // Below main diagonal: i > j
            // Above secondary diagonal: i + j > 11
            if (i > j && i + j > 11) {
                sum += M[i][j];
                count++;
            }
        }
    }

    // Print the result based on the operation
    if (O == 'S') {
        printf("%.1lf\n", sum);
    } else if (O == 'M') {
        printf("%.1lf\n", sum / count);
    }

    return 0;
}
