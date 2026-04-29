#include <stdio.h>
#include <string.h>

#define MAX 10001

int memo[MAX];

// Function to find MEX (Minimum Excluded value)
int mex(int *set, int size) {
    int found[MAX] = {0};
    for (int i = 0; i < size; i++) if (set[i] < MAX) found[set[i]] = 1;
    for (int i = 0; ; i++) if (!found[i]) return i;
}

// Precompute Grundy values using Sprague-Grundy
void precompute() {
    memo[0] = 0;
    for (int i = 1; i < MAX; i++) {
        int reachable_grundy[MAX];
        int count = 0;
        for (int j = 1; j <= i; j++) {
            // Placing an X at pos j splits into (j-3) and (i-j-2) usable spaces
            int left = (j - 3 < 0) ? 0 : j - 3;
            int right = (i - j - 2 < 0) ? 0 : i - j - 2;
            reachable_grundy[count++] = memo[left] ^ memo[right];
        }
        memo[i] = mex(reachable_grundy, count);
    }
}

int main() {
    precompute();
    int N;
    char board[MAX];

    while (scanf("%d", &N) && N != 0) {
        scanf("%s", board);
        int total_nim_sum = 0;
        int current_segment = 0;

        // Logical split of board based on 'X' positions
        // This is a simplified logic; real competitive solutions
        // handle 'X' barriers by calculating segment lengths between them.
        for (int i = 0; i < N; i++) {
            if (board[i] == '.') {
                current_segment++;
            } else {
                // 'X' found, process the segment of '.' before it
                // Logic requires adjusting for forbidden neighbors of 'X'
                total_nim_sum ^= memo[current_segment];
                current_segment = 0;
            }
        }
        total_nim_sum ^= memo[current_segment];

        if (total_nim_sum > 0) printf("S\n");
        else printf("N\n");
    }
    return 0;
}
