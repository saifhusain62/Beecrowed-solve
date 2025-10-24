#include <stdio.h>

int main() {
    char O; // Operation character: 'S' for Sum, 'M' for Average
    scanf("%c", &O);

    double M[12][12]; // The 12x12 matrix
    int i, j;
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }

    double sum = 0.0;
    int count = 0;

    // Iterate through the right area of the matrix
    // This area is defined by elements where j > i and j > 11 - i
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            if (j > i && j > (11 - i)) {
                sum += M[i][j];
                count++;
            }
        }
    }

    if (O == 'S') {
        printf("%.1lf\n", sum);
    } else if (O == 'M') {
        printf("%.1lf\n", sum / count);
    }

    return 0;
}
