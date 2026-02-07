#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    // Read n (rows) and m (cols) until EOF
    while (scanf("%d %d", &n, &m) != EOF) {
        int x1, y1, x2, y2, temp;

        // Iterate through the city grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &temp);
                // Locate Pokémon (1)
                if (temp == 1) {
                    x1 = i;
                    y1 = j;
                }
                // Locate Ash (2)
                else if (temp == 2) {
                    x2 = i;
                    y2 = j;
                }
            }
        }

        // Calculate Manhattan distance: |x1 - x2| + |y1 - y2|
        int distance = abs(x1 - x2) + abs(y1 - y2);
        printf("%d\n", distance);
    }
    return 0;
}

