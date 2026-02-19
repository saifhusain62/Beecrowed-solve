#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // Consume the newline character left after reading 'n'

    for (int i = 0; i < n; i++) {
        char line[100];
        fgets(line, sizeof(line), stdin); // Read the line, which can be discarded

        printf("I am Toorg!\n");
    }

    return 0;
}

