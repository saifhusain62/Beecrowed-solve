#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int T, case_num = 1;
    scanf("%d", &T);

    while (T--) {
        char sheldon[10], raj[10];
        scanf("%s %s", sheldon, raj);

        int winner = 0; // 0 for draw, 1 for Sheldon, 2 for Raj

        if (strcmp(sheldon, raj) == 0) {
            winner = 0;
        } else if (
            (strcmp(sheldon, "tesoura") == 0 && strcmp(raj, "papel") == 0) ||
            (strcmp(sheldon, "papel") == 0 && strcmp(raj, "pedra") == 0) ||
            (strcmp(sheldon, "pedra") == 0 && strcmp(raj, "lagarto") == 0) ||
            (strcmp(sheldon, "lagarto") == 0 && strcmp(raj, "Spock") == 0) ||
            (strcmp(sheldon, "Spock") == 0 && strcmp(raj, "tesoura") == 0) ||
            (strcmp(sheldon, "tesoura") == 0 && strcmp(raj, "lagarto") == 0) ||
            (strcmp(sheldon, "lagarto") == 0 && strcmp(raj, "papel") == 0) ||
            (strcmp(sheldon, "papel") == 0 && strcmp(raj, "Spock") == 0) ||
            (strcmp(sheldon, "Spock") == 0 && strcmp(raj, "pedra") == 0) ||
            (strcmp(sheldon, "pedra") == 0 && strcmp(raj, "tesoura") == 0)
        ) {
            winner = 1; // Sheldon wins
        } else {
            winner = 2; // Raj wins
        }

        printf("Caso #%d: ", case_num++);
        if (winner == 0) {
            printf("De novo!\n");
        } else if (winner == 1) {
            printf("Bazinga!\n");
        } else {
            printf("Raj trapaceou!\n");
        }
    }

    return 0;
}
