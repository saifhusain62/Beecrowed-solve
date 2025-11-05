#include <stdio.h>

int main() {
    int T, R1, R2; // T for number of test cases, R1 and R2 for radii
    scanf("%d", &T); // Read the number of test cases

    while (T--) { // Loop through each test case
        scanf("%d %d", &R1, &R2); // Read the radii for the current test case
        printf("%d\n", R1 + R2); // Print the sum of the radii
    }

    return 0; // Indicate successful execution
}

