#include <stdio.h>
#include <math.h>

int main() {
    int n;
    // Read n until EOF for multiple test cases
    while (scanf("%d", &n) != EOF) {
        int i, vote, votes_for = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &vote);
            if (vote == 1) {
                votes_for++; // Count '1' as a vote for impeachment
            }
        }

        // Calculate 2/3 of total voters (double for precision)
        double needed = (double)n * (2.0 / 3.0);

        // If votes_for >= 2/3 * n, it passes
        if (votes_for >= needed) {
            printf("impeachment\n");
        } else {
            printf("acusacao arquivada\n");
        }
    }
    return 0;
}

