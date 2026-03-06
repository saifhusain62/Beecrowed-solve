#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void solve() {
    char diet[300], breakfast[300], lunch[300];

    // Using fgets to handle potential empty lines
    fgets(diet, 300, stdin);
    fgets(breakfast, 300, stdin);
    fgets(lunch, 300, stdin);

    // Remove trailing newline characters
    diet[strcspn(diet, "\n")] = 0;
    breakfast[strcspn(breakfast, "\n")] = 0;
    lunch[strcspn(lunch, "\n")] = 0;

    int freq[256] = {0};
    bool cheater = false;

    // Map the diet plan
    for (int i = 0; diet[i] != '\0'; i++) {
        freq[(int)diet[i]]++;
    }

    // Process breakfast
    for (int i = 0; breakfast[i] != '\0'; i++) {
        if (freq[(int)breakfast[i]] == 0) cheater = true;
        else freq[(int)breakfast[i]]--;
    }

    // Process lunch
    for (int i = 0; lunch[i] != '\0'; i++) {
        if (freq[(int)lunch[i]] == 0) cheater = true;
        else freq[(int)lunch[i]]--;
    }

    if (cheater) {
        printf("CHEATER\n");
    } else {
        // Print remaining letters in alphabetical order
        for (int i = 'A'; i <= 'Z'; i++) {
            if (freq[i] > 0) {
                printf("%c", i);
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    char buffer[10];
    if (fgets(buffer, 10, stdin)) {
        sscanf(buffer, "%d", &n);
        while (n--) {
            solve();
        }
    }
    return 0;
}

