#include <stdio.h>

int main() {
    int n, i, j;
    int marks[5];
    char answers[] = {'A', 'B', 'C', 'D', 'E'};

    // Continue reading until N is 0
    while (scanf("%d", &n) && n != 0) {
        for (i = 0; i < n; i++) {
            int black_count = 0;
            int last_black_index = -1;

            for (j = 0; j < 5; j++) {
                scanf("%d", &marks[j]);
                // A circle is considered black if the value is 127 or less
                if (marks[j] <= 127) {
                    black_count++;
                    last_black_index = j;
                }
            }

            // Valid if exactly one circle is black
            if (black_count == 1) {
                printf("%c\n", answers[last_black_index]);
            } else {
                printf("*\n");
            }
        }
    }
    return 0;
}

