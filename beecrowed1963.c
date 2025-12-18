#include <stdio.h>

int main() {
    double A, B, percentage_increase;

    // Read the old price (A) and the new price (B)
    scanf("%lf %lf", &A, &B);

    // Calculate the percentage increase
    // The formula is ((B - A) / A) * 100
    percentage_increase = ((B - A) / A) * 100.0;

    // Print the result formatted to two decimal places followed by a '%' sign
    printf("%.2f%%\n", percentage_increase);

    return 0;
}

