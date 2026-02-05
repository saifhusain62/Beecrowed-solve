#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int C, N;
    // Read C and N, ensuring valid input
    while (scanf("%d %d", &C, &N) != EOF) {
        char key1[100], key2[100];
        getchar(); // consume newline
        fgets(key1, sizeof(key1), stdin);
        fgets(key2, sizeof(key2), stdin);
        // Remove newline characters from fgets
        key1[strcspn(key1, "\r\n")] = 0;
        key2[strcspn(key2, "\r\n")] = 0;

        for (int i = 0; i < N; i++) {
            char message[10005];
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\r\n")] = 0;

            for (int j = 0; message[j] != '\0'; j++) {
                char current = message[j];
                char mapped = current;

                // Check against both keys for swapping
                for (int k = 0; k < C; k++) {
                    if (toupper(current) == toupper(key1[k])) {
                        mapped = isupper(current) ? toupper(key2[k]) : tolower(key2[k]);
                        break;
                    } else if (toupper(current) == toupper(key2[k])) {
                        mapped = isupper(current) ? toupper(key1[k]) : tolower(key1[k]);
                        break;
                    }
                }
                printf("%c", mapped);
            }
            printf("\n");
        }
        printf("\n"); // Blank line after each test case, if required
    }
    return 0;
}

