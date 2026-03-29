#include <stdio.h>

// Function to calculate GCD using Euclidean Algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n, f1, f2;

    // Read the number of test cases
    if (scanf("%d", &n) != 1) return 0;

    // Iterate through each test case
    for (int i = 0; i < n; i++) {
        // Read the number of cards owned by Ricardo and Vicente
        if (scanf("%d %d", &f1, &f2) == 2) {
            // Output the GCD
            printf("%d\n", gcd(f1, f2));
        }
    }

    return 0;
}

