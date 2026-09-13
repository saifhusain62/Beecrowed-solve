#include <stdio.h>

int main() {
    int v, t;

    // Read input until End of File (EOF)
    while (scanf("%d %d", &v, &t) != EOF) {
        // Calculate and print the displacement at 2t
        printf("%d\n", 2 * v * t);
    }

    return 0;
}

