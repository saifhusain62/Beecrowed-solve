#include <stdio.h>

int main() {
    int n, days;
    float food;

    // Read the number of test cases
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        // Read the initial amount of food for the current case
        scanf("%f", &food);
        days = 0;

        // Keep eating half until 1kg or less remains
        while (food > 1.0) {
            food /= 2.0;
            days++;
        }

        // Print the result in the format: X dias
        printf("%d dias\n", days);
    }

    return 0;
}

