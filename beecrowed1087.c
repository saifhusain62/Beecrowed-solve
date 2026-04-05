#include <stdio.h>
#include <stdlib.h>

int main() {
    int x1, y1, x2, y2;

    // Read input until all values are 0
    while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) && (x1 != 0 || y1 != 0 || x2 != 0 || y2 != 0)) {

        if (x1 == x2 && y1 == y2) {
            // Already at the destination
            printf("0\n");
        }
        else if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) {
            // Same row, column, or diagonal
            printf("1\n");
        }
        else {
            // Any other square on the board
            printf("2\n");
        }
    }

    return 0;
}

