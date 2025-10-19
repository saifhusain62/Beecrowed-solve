#include <stdio.h>

int main() {
    char operation;
    double matrix[12][12];
    double sum = 0.0;
    int count = 0;

    scanf("%c", &operation);

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (j > i) { // Condition for elements above the main diagonal
                sum += matrix[i][j];
                count++;
            }
        }
    }

    if (operation == 'S') {
        printf("%.1lf\n", sum);
    } else if (operation == 'M') {
        printf("%.1lf\n", sum / count);
    }

    return 0;
}
