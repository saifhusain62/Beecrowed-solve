#include <stdio.h>

int main() {
    int n;

    // Read input until End-Of-File (EOF)
    while (scanf("%d", &n) != EOF) {
        int vote;
        int favor_votes = 0;

        // Count the number of favorable votes
        for (int i = 0; i < n; i++) {
            scanf("%d", &vote);
            if (vote == 1) {
                favor_votes++;
            }
        }

        // Check if votes meet or exceed the 2/3 requirement using integer math
        if (favor_votes * 3 >= n * 2) {
            printf("impeachment\n");
        } else {
            printf("acusacao arquivada\n");
        }
    }

    return 0;
}

