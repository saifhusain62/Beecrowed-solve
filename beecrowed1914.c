#include <stdio.h>
#include <string.h>

int main() {
    int num_test_cases;
    scanf("%d", &num_test_cases);

    for (int i = 0; i < num_test_cases; i++) {
        char player1_name[100], player1_choice[10];
        char player2_name[100], player2_choice[10];
        long long int num1, num2;

        scanf("%s %s %s %s", player1_name, player1_choice, player2_name, player2_choice);
        scanf("%lld %lld", &num1, &num2);

        long long int sum = num1 + num2;

        if (strcmp(player1_choice, "PAR") == 0) { // Player 1 chose PAR (Even)
            if (sum % 2 == 0) { // Sum is even
                printf("%s\n", player1_name);
            } else { // Sum is odd
                printf("%s\n", player2_name);
            }
        } else { // Player 1 chose IMPAR (Odd)
            if (sum % 2 == 0) { // Sum is even
                printf("%s\n", player2_name);
            } else { // Sum is odd
                printf("%s\n", player1_name);
            }
        }
    }

    return 0;
}
