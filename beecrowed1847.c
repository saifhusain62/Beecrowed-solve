#include <stdio.h>

int main() {
    int A, B, C;

    // Read the three temperature readings
    scanf("%d %d %d", &A, &B, &C);

    // Check the conditions to determine the mood
    if (A > B) {
        // Temperature decreased from day 1 to day 2
        if (B < C) {
            printf(":)\n");
        } else {
            // Temperature also decreased or stayed the same from day 2 to day 3
            if ((B - C) < (A - B)) { // Check if the decrease slowed down
                printf(":)\n");
            } else {
                printf(":(\n");
            }
        }
    } else if (A < B) {
        // Temperature increased from day 1 to day 2
        if (B > C) {
            printf(":(\n");
        } else {
            // Temperature also increased or stayed the same from day 2 to day 3
            if ((C - B) < (B - A)) { // Check if the increase slowed down
                printf(":(\n");
            } else {
                printf(":)\n");
            }
        }
    } else {
        // Temperature stayed the same from day 1 to day 2
        if (B < C) { // Increased from day 2 to day 3
            printf(":)\n");
        } else { // Decreased or stayed the same from day 2 to day 3
            printf(":(\n");
        }
    }

    return 0;
}

