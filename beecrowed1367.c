#include <stdio.h>
#include <string.h>

int main() {
    int n;
    
    while (scanf("%d", &n) && n != 0) {
        int penalty[26] = {0};
        int solved[26] = {0};
        int total_solved = 0;
        int total_time = 0;

        for (int i = 0; i < n; i++) {
            char problem;
            int time;
            char status[15];

            scanf(" %c %d %s", &problem, &time, status);
            int idx = problem - 'A';

            if (strcmp(status, "correct") == 0) {
                // Only count the first time a problem is solved
                if (!solved[idx]) {
                    solved[idx] = 1;
                    total_solved++;
                    total_time += time + penalty[idx];
                }
            } else {
                // Add 20 minutes penalty if not yet solved
                if (!solved[idx]) {
                    penalty[idx] += 20;
                }
            }
        }

        printf("%d %d\n", total_solved, total_time);
    }

    return 0;
}
