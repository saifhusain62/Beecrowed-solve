#include <stdio.h>

int main() {
    int N, factorial = 1;

    // Read the input integer N
    scanf("%d", &N);

    // Calculate the factorial using a loop
    for (int i = 1; i <= N; i++) {
        factorial *= i;
    }

    // Print the result
    printf("%d\n", factorial);

    return 0;
}
