#include <stdio.h>

int main() {
    int N, I;

    // Read N (number of gameplays) and I (player's ID) until EOF
    while (scanf("%d %d", &N, &I) != EOF) {
        int count = 0;

        for (int k = 0; k < N; k++) {
            int i, j;
            scanf("%d %d", &i, &j);

            // Check if the gameplay ID matches the player's ID
            // and if the game type is CS:GO (j == 0)
            if (i == I && j == 0) {
                count++;
            }
        }

        // Print the total count for the current test case
        printf("%d\n", count);
    }

    return 0;
}

