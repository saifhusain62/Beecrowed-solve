#include <stdio.h>

int main() {
    int c, n;

    // Read the number of test cases
    if (scanf("%d", &c) != 1) return 0;

    while (c > 0) {
        // Read the number of students in the class
        scanf("%d", &n);

        int grades[n];
        double sum = 0.0;

        // Read the grades and calculate the sum
        for (int i = 0; i < n; i++) {
            scanf("%d", &grades[i]);
            sum += grades[i];
        }

        // Calculate the class average
        double average = sum / n;

        // Count how many students scored strictly above the average
        int above_average_count = 0;
        for (int i = 0; i < n; i++) {
            if (grades[i] > average) {
                above_average_count++;
            }
        }

        // Calculate percentage and print with 3 decimal places followed by '%'
        double percentage = ((double)above_average_count / n) * 100.0;
        printf("%.3f%%\n", percentage);

        c--;
    }

    return 0;
}

