#include <stdio.h>

int main() {
    int T1, T2, T3, T4;
    scanf("%d %d %d %d", &T1, &T2, &T3, &T4);

    // Calculate the total available outlets
    // T1 + T2 - 1 (for connecting T1 and T2)
    // + T3 - 1 (for connecting the combined T1/T2 to T3)
    // + T4
    // This simplifies to T1 + T2 + T3 + T4 - 3
    int total_outlets = T1 + T2 + T3 + T4 - 3;

    printf("%d\n", total_outlets);

    return 0;
}
