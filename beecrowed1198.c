#include <stdio.h>

int main() {
    long long hashmat_army, opponent_army, difference;

    // Read inputs until the End of File (EOF) is reached
    while (scanf("%lld %lld", &hashmat_army, &opponent_army) != EOF) {

        // Calculate the absolute difference
        if (hashmat_army > opponent_army) {
            difference = hashmat_army - opponent_army;
        } else {
            difference = opponent_army - hashmat_army;
        }

        // Print the result followed by a newline
        printf("%lld\n", difference);
    }

    return 0;
}

