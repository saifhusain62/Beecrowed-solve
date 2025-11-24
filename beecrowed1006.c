#include <stdio.h>

int main() {
    double A, B, C;
    double MEDIA;

    // Read the three grades
    scanf("%lf %lf %lf", &A, &B, &C);

    // Calculate the weighted average
    MEDIA = (A * 2 + B * 3 + C * 5) / 10;

    // Print the result with one decimal place
    printf("MEDIA = %.1lf\n", MEDIA);

    return 0;
}
