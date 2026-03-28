#include <stdio.h>

// Function to calculate the remaining region using the Josephus formula
int remaining(int n, int k) {
    int r = 0;
    // The formula simulates the process more efficiently than a linked list
    for (int i = 1; i < n; i++) {
        r = (r + k) % i;
    }
    return r;
}

int main() {
    int ncities, jump;
    while (1) {
        // Read the number of regions
        scanf("%d", &ncities);
        // Break the loop if the input is 0
        if (ncities == 0) break;

        // Start checking jump values from 1
        jump = 1;
        while (1) {
            // Check if the remaining region (plus 1 for 1-based indexing) is the "safe" region (13)
            if (remaining(ncities, jump) + 1 != 13) {
                jump++;
            } else {
                break;
            }
        }
        // Print the first valid jump value found
        printf("%d\n", jump);
    }
    return 0;
}

