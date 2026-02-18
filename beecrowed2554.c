#include <stdio.h>
#include <string.h>

int main() {
    int N, D;
    // Read N (people) and D (dates) until EOF
    while (scanf("%d %d", &N, &D) != EOF) {
        char bestDate[15] = "";
        int found = 0;

        for (int i = 0; i < D; i++) {
            char currentDate[15];
            scanf("%s", currentDate);

            int allCan = 1;
            for (int j = 0; j < N; j++) {
                int canAttend;
                scanf("%d", &canAttend);
                if (canAttend == 0) {
                    allCan = 0;
                }
            }

            // Keep the first date where everyone can attend
            if (allCan && !found) {
                strcpy(bestDate, currentDate);
                found = 1;
            }
        }

        if (found) {
            printf("%s\n", bestDate);
        } else {
            printf("Pizza antes de FdM\n");
        }
    }
    return 0;
}

