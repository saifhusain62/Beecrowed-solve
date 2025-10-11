#include <stdio.h>

int main() {
    int L; // Line number
    char T; // Operation type ('S' for Sum, 'M' for Average)
    double M[12][12]; // The 12x12 matrix
    double sum = 0.0; // Variable to store the sum of elements

    // Read the line number and operation type
    scanf("%d", &L);
    scanf(" %c", &T); // Note the space before %c to consume the newline character

    // Read the elements of the 12x12 matrix
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }

    // Calculate the sum of elements in the specified line
    for (int j = 0; j < 12; j++) {
        sum += M[L][j];
    }

    // Perform the operation based on 'T'
    if (T == 'S') {
        printf("%.1lf\n", sum);
    } else if (T == 'M') {
        printf("%.1lf\n", sum / 12.0);
    }

    return 0;
}
