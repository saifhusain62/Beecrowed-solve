#include <stdio.h>

int main() {
    int i, j;
    char operation_type;
    float matrix[12][12];
    double sum = 0.0;
    int count = 0;

    // Read the operation type ('S' or 'M')
    scanf("%c", &operation_type);

    // Read the 12x12 matrix
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Iterate through the matrix to find elements below the secondary diagonal
    // The secondary diagonal consists of elements where i + j = 11.
    // Elements below the secondary diagonal satisfy j > (11 - i).
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            if (j > (11 - i)) {
                sum += matrix[i][j];
                count++;
            }
        }
    }

    // Perform the requested operation and print the result
    if (operation_type == 'S') {
        printf("%.1lf\n", sum);
    } else if (operation_type == 'M') {
        if (count > 0) { // Avoid division by zero
            printf("%.1lf\n", sum / count);
        } else {
            printf("0.0\n"); // Or handle as per problem specification if no elements are found
        }
    }

    return 0;
}
