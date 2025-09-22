#include <stdio.h>

int main() {
    double S = 0.0;
    int numerator = 1;
    double denominator = 1.0;

    while (numerator <= 39) {
        S += (double)numerator / denominator;
        numerator += 2;
        denominator *= 2;
    }

    printf("%.2lf\n", S);

    return 0;
}
