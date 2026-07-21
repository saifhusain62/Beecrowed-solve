#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, k, m;

    // Read input until n = 0, k = 0, m = 0
    while (scanf("%d %d %d", &n, &k, &m) && (n != 0 || k != 0 || m != 0)) {
        bool in_queue[25] = {false}; // Tracks if a person is already chosen
        int remaining = n;

        // Start positions:
        // Clockwise starts at 1 (moves to 1 on first count)
        // Counter-clockwise starts at n (moves to n on first count)
        int p1 = 1;
        int p2 = n;

        while (remaining > 0) {
            // 1. Move clockwise k times
            int count1 = 0;
            while (count1 < k) {
                if (!in_queue[p1]) {
                    count1++;
                }
                if (count1 < k) {
                    p1 = (p1 % n) + 1; // Move to next person clockwise
                }
            }

            // 2. Move counter-clockwise m times
            int count2 = 0;
            while (count2 < m) {
                if (!in_queue[p2]) {
                    count2++;
                }
                if (count2 < m) {
                    p2 = p2 - 1;
                    if (p2 == 0) p2 = n; // Wrap around counter-clockwise
                }
            }

            // 3. Process the chosen people
            if (p1 == p2) {
                printf("%3d", p1);
                in_queue[p1] = true;
                remaining--;
            } else {
                printf("%3d%3d", p1, p2);
                in_queue[p1] = true;
                in_queue[p2] = true;
                remaining -= 2;
            }

            // 4. Print commas between groups, or a newline at the end
            if (remaining > 0) {
                printf(",");
            } else {
                printf("\n");
            }

            // 5. Advance pointers to the next available spots for the next round
            if (remaining > 0) {
                while (in_queue[p1]) {
                    p1 = (p1 % n) + 1;
                }
                while (in_queue[p2]) {
                    p2 = p2 - 1;
                    if (p2 == 0) p2 = n;
                }
            }
        }
    }
    return 0;
}

