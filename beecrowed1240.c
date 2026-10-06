#include <stdio.h>
#include <string.h>

int main() {
    int n;
    // Read the number of test cases
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        char a[32], b[32];
        scanf("%s %s", a, b);

        int len_a = strlen(a);
        int len_b = strlen(b);

        // If B is longer than A, A cannot contain B at the end
        if (len_b > len_a) {
            printf("nao encaixa\n");
        } else {
            // Compare the end of string A with string B
            if (strcmp(&a[len_a - len_b], b) == 0) {
                printf("encaixa\n");
            } else {
                printf("nao encaixa\n");
            }
        }
    }

    return 0;
}
