#include <stdio.h>
#include <string.h>

int main() {
    int G, P; // G: Number of races, P: Number of pilots

    // Read input until G and P are both 0
    while (scanf("%d %d", &G, &P) && (G != 0 || P != 0)) {
        int results[G][P];

        // Store results for each race
        // results[race][pilot_index] = finishing_position
        for (int i = 0; i < G; i++) {
            for (int j = 0; j < P; j++) {
                scanf("%d", &results[i][j]);
            }
        }

        int S; // Number of scoring systems
        scanf("%d", &S);

        while (S--) {
            int K; // Last finishing position that receives points
            scanf("%d", &K);
            int points_table[101] = {0};

            for (int i = 1; i <= K; i++) {
                scanf("%d", &points_table[i]);
            }

            int pilot_scores[P];
            memset(pilot_scores, 0, sizeof(pilot_scores));
            int max_points = 0;

            // Calculate total points for each pilot
            for (int i = 0; i < G; i++) {
                for (int j = 0; j < P; j++) {
                    int finish_pos = results[i][j];
                    if (finish_pos <= K) {
                        pilot_scores[j] += points_table[finish_pos];
                    }
                }
            }

            // Find the maximum score achieved
            for (int i = 0; i < P; i++) {
                if (pilot_scores[i] > max_points) {
                    max_points = pilot_scores[i];
                }
            }

            // Print all pilots who achieved the maximum score
            int first = 1;
            for (int i = 0; i < P; i++) {
                if (pilot_scores[i] == max_points) {
                    if (!first) printf(" ");
                    printf("%d", i + 1);
                    first = 0;
                }
            }
            printf("\n");
        }
    }
    return 0;
}

