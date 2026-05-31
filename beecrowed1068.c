#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char str[1005];

    // Read lines until End of File (EOF)
    while (scanf("%s", str) != EOF) {
        int balance = 0;
        bool is_correct = true;

        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '(') {
                balance++;
            } else if (str[i] == ')') {
                balance--;
                // If balance drops below 0, a closing parenthesis appeared without a matching open one
                if (balance < 0) {
                    is_correct = false;
                }
            }
        }

        // The expression is only correct if all opened parentheses are closed (balance == 0)
        if (is_correct && balance == 0) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}

