#include <stdio.h>
#include <string.h>

int main() {
    char alphabet_map[1001]; // Buffer for the alphabet string (max length ~1000)
    int num_indices;
    int index_value;

    // Loop to read input until the end of the file (EOF)
    while (scanf("%s", alphabet_map) != EOF) {
        scanf("%d", &num_indices);

        // Loop to process each index
        for (int i = 0; i < num_indices; i++) {
            scanf("%d", &index_value);
            // The problem uses 1-based indexing, so we access index_value - 1
            printf("%c", alphabet_map[index_value - 1]);
        }
        // Print a newline character after each complete message
        printf("\n");
    }

    return 0;
}

