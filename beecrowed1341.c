#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char a[1001], b[1001];

    // Read number of test cases
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        scanf("%s %s", a, b);

        int len_a = strlen(a);
        int len_b = strlen(b);

        // B cannot fit if it is longer than A
        if (len_b > len_a) {
            printf("nao encaixa\n");
        } else {
            // Compare the end of A with B
            // strcmp returns 0 if strings match
            if (strcmp(&a[len_a - len_b], b) == 0) {
                printf("encaixa\n");
            } else {
                printf("nao encaixa\n");
            }
        }
    }

    return 0;
}
