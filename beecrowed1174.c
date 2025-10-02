#include <stdio.h>

int main() {
    double A[100]; // Declare an array of 100 doubles

    // Read 100 floating-point numbers into the array
    for (int i = 0; i < 100; i++) {
        scanf("%lf", &A[i]);
    }

    // Iterate through the array and print elements less than or equal to 10.0
    for (int i = 0; i < 100; i++) {
        if (A[i] <= 10.0) {
            printf("A[%d] = %.1lf\n", i, A[i]);
        }
    }

    return 0;
}
