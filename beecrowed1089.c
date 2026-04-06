#include <stdio.h>

int main() {
    int N;
    // Read N; the loop terminates when N is 0
    while (scanf("%d", &N) && N != 0) {
        int H[N];
        int peaks = 0;

        for (int i = 0; i < N; i++) {
            scanf("%d", &H[i]);
        }

        for (int i = 0; i < N; i++) {
            // Use modulo operator to handle the circular wrap-around
            int prev = (i - 1 + N) % N;
            int next = (i + 1) % N;

            // Check if H[i] is a local maximum or minimum
            if ((H[i] > H[prev] && H[i] > H[next]) ||
                (H[i] < H[prev] && H[i] < H[next])) {
                peaks++;
            }
        }

        printf("%d\n", peaks);
    }
    return 0;
}

