#include <stdio.h>

int main() {
    int h1, m1, h2, m2;

    // Read input until all zeros
    while (scanf("%d %d %d %d", &h1, &m1, &h2, &m2) && (h1 != 0 || m1 != 0 || h2 != 0 || m2 != 0)) {

        // Convert time to total minutes from 00:00
        int start = h1 * 60 + m1;
        int end = h2 * 60 + m2;

        int diff = end - start;

        // If difference is negative, it means it crosses midnight
        if (diff < 0) {
            diff += 24 * 60; // Add 1440 minutes
        }

        printf("%d\n", diff);
    }

    return 0;
}

