#include <stdio.h>

int main() {
    double A, B, average;

    // Read the two grades
    scanf("%lf", &A);
    scanf("%lf", &B);

    // Calculate the weighted average
    average = (A * 3.5 + B * 7.5) / (3.5 + 7.5);

    // Print the result with 5 decimal places
    printf("MEDIA = %.5lf\n", average);

    return 0;
}
