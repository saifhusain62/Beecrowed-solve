#include <stdio.h>

int main() {
    int n, m, l;
    // Loop to handle multiple test cases until EOF
    while (scanf("%d", &n) != EOF) {
        scanf("%d %d", &m, &l);

        // Declare 2D arrays to store card attributes
        int marcos_cards[m][n];
        int leo_cards[l][n];

        // Read Marcos' cards
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &marcos_cards[i][j]);
            }
        }

        // Read Leonardo's cards
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &leo_cards[i][j]);
            }
        }

        int marcos_chosen_card_idx, leo_chosen_card_idx, chosen_attribute_idx;
        scanf("%d %d %d", &marcos_chosen_card_idx, &leo_chosen_card_idx, &chosen_attribute_idx);

        // Adjust indices to be 0-based for array access
        int marcos_attribute = marcos_cards[marcos_chosen_card_idx - 1][chosen_attribute_idx - 1];
        int leo_attribute = leo_cards[leo_chosen_card_idx - 1][chosen_attribute_idx - 1];

        // Compare the attributes and print the result
        if (marcos_attribute > leo_attribute) {
            printf("Marcos\n");
        } else if (marcos_attribute < leo_attribute) {
            printf("Leonardo\n");
        } else {
            printf("Empate\n");
        }
    }
    return 0;
}

