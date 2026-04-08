#include <stdio.h>
#include <string.h>

// Helper to map card descriptions to an index (0-8)
int get_index(int n, char *shape) {
    int s;
    if (strcmp(shape, "circulo") == 0) s = 0;
    else if (strcmp(shape, "quadrado") == 0) s = 1;
    else s = 2; // triangulo
    return (n - 1) * 3 + s;
}

int main() {
    int N;
    while (scanf("%d", &N) && N != 0) {
        int cards[9] = {0};
        char num_str[10], shape[20];

        for (int i = 0; i < N; i++) {
            scanf("%s %s", num_str, shape);
            int n;
            if (strcmp(num_str, "um") == 0) n = 1;
            else if (strcmp(num_str, "dois") == 0) n = 2;
            else n = 3;
            cards[get_index(n, shape)]++;
        }

        int total_sets = 0;

        // 1. Sets of 3 identical cards
        for (int i = 0; i < 9; i++) {
            total_sets += cards[i] / 3;
            cards[i] %= 3;
        }

        // 2. Sets with same count, different shapes
        // (Indices: 0,1,2 | 3,4,5 | 6,7,8)
        for (int i = 0; i < 9; i += 3) {
            int min = cards[i];
            if (cards[i+1] < min) min = cards[i+1];
            if (cards[i+2] < min) min = cards[i+2];
            total_sets += min;
            cards[i] -= min; cards[i+1] -= min; cards[i+2] -= min;
        }

        // 3. Sets with same shape, different counts
        // (Indices: 0,3,6 | 1,4,7 | 2,5,8)
        for (int i = 0; i < 3; i++) {
            int min = cards[i];
            if (cards[i+3] < min) min = cards[i+3];
            if (cards[i+6] < min) min = cards[i+6];
            total_sets += min;
            cards[i] -= min; cards[i+3] -= min; cards[i+6] -= min;
        }

        // 4. Sets where both attributes are different (Latin Square permutations)
        // Two possible combinations of indices:
        // (0,4,8), (0,5,7), (1,3,8), (1,5,6), (2,3,7), (2,4,6)
        int combinations[6][3] = {
            {0, 4, 8}, {0, 5, 7}, {1, 3, 8},
            {1, 5, 6}, {2, 3, 7}, {2, 4, 6}
        };

        for (int i = 0; i < 6; i++) {
            int min = cards[combinations[i][0]];
            if (cards[combinations[i][1]] < min) min = cards[combinations[i][1]];
            if (cards[combinations[i][2]] < min) min = cards[combinations[i][2]];
            total_sets += min;
            cards[combinations[i][0]] -= min;
            cards[combinations[i][1]] -= min;
            cards[combinations[i][2]] -= min;
        }

        printf("%d\n", total_sets);
    }
    return 0;
}

