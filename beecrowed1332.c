#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char word[10];

    // Read the number of test cases
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        scanf("%s", word);

        if (strlen(word) == 5) {
            // "three" is the only word with 5 letters
            printf("3\n");
        } else {
            // Check if it's "one" by matching at least 2 characters
            int count = 0;
            if (word[0] == 'o') count++;
            if (word[1] == 'n') count++;
            if (word[2] == 'e') count++;

            if (count >= 2) {
                printf("1\n");
            } else {
                printf("2\n");
            }
        }
    }

    return 0;
}

