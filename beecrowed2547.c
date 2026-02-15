#include <stdio.h>

int main() {
    int N, AL, AU;

    // Loop to read multiple test cases until EOF (End Of File)
    while (scanf("%d %d %d", &N, &AL, &AU) != EOF) {
        int eligible_students_count = 0;
        int current_height;

        // Loop to read the heights of N students
        for (int i = 0; i < N; i++) {
            scanf("%d", &current_height);

            // Check if the student's height is within the acceptable range
            if (current_height >= AL && current_height <= AU) {
                eligible_students_count++;
            }
        }

        // Print the final count of eligible students
        printf("%d\n", eligible_students_count);
    }

    return 0;
}

