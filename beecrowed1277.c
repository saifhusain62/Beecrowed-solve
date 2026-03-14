#include <stdio.h>
#include <string.h>

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        char names[n][100];
        for (int i = 0; i < n; i++) scanf("%s", names[i]);

        int first = 1;
        for (int i = 0; i < n; i++) {
            char att[1000];
            scanf("%s", att);
            int present = 0, total = 0;
            for (int j = 0; att[j] != '\0'; j++) {
                if (att[j] == 'P' || att[j] == 'A') {
                    total++;
                    if (att[j] == 'P') present++;
                }
            }
            // Check if attendance is less than 75%
            if ((float)present / total < 0.75) {
                if (!first) printf(" ");
                printf("%s", names[i]);
                first = 0;
            }
        }
        printf("\n");
    }
    return 0;
}

