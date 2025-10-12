#include <stdio.h>

int main() {
    int C;
    char T;
    double M[12][12];
    double sum = 0.0;

    // Read the column index C
    scanf("%d", &C);

    // Read the operation type T
    scanf(" %c", &T); // Note the space before %c to consume any leftover newline character

    // Read the 12x12 matrix
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }

    // Calculate the sum of elements in the specified column C
    for (int i = 0; i < 12; i++) {
        sum += M[i][C];
    }

    // Perform the operation based on T
    if (T == 'S') {
        printf("%.1lf\n", sum);
    } else if (T == 'M') {
        printf("%.1lf\n", sum / 12.0);
    }

    return 0;
}
