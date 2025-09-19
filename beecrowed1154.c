#include <stdio.h>

int main() {
    int age;
    int sum = 0;
    int count = 0;
    double average;

    while (1) { // Loop indefinitely until a negative age is entered
        scanf("%d", &age);

        if (age < 0) {
            break; // Exit the loop if a negative age is read
        }

        sum += age;
        count++;
    }

    if (count > 0) { // Avoid division by zero if no positive ages were entered
        average = (double)sum / count;
        printf("%.2lf\n", average);
    }

    return 0;
}
