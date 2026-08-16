#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store each T-Shirt order details
typedef struct {
    char name[100];
    char color[20];
    char size;
} Shirt;

// Custom comparison function for qsort
int compare(const void *a, const void *b) {
    Shirt *s1 = (Shirt *)a;
    Shirt *s2 = (Shirt *)b;

    // 1. Sort by color in ascending order ("branco" before "vermelho")
    int color_diff = strcmp(s1->color, s2->color);
    if (color_diff != 0) {
        return color_diff;
    }

    // 2. Sort by size in descending order ('P' > 'M' > 'G')
    if (s1->size != s2->size) {
        // In ASCII: 'G' (71) < 'M' (77) < 'P' (80)
        // Since we want P first, then M, then G, we reverse the natural order.
        return (s2->size - s1->size);
    }

    // 3. Sort by owner's name in ascending alphabetical order
    return strcmp(s1->name, s2->name);
}

int main() {
    int N;
    int first_case = 1;

    while (scanf("%d", &N) == 1 && N != 0) {
        // Format newline between output cases, but not after the last case
        if (!first_case) {
            printf("\n");
        }
        first_case = 0;

        Shirt shirts[N];

        for (int i = 0; i < N; i++) {
            // Consume the newline left over from the previous input
            scanf(" %[^\n]", shirts[i].name);
            scanf("%s %c", shirts[i].color, &shirts[i].size);
        }

        // Sort using standard qsort
        qsort(shirts, N, sizeof(Shirt), compare);

        // Print sorted results
        for (int i = 0; i < N; i++) {
            printf("%s %c %s\n", shirts[i].color, shirts[i].size, shirts[i].name);
        }
    }

    return 0;
}

