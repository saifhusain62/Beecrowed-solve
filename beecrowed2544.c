#include <stdio.h>
#include <math.h>

int main() {
    int n;
    // Read input until EOF
    while (scanf("%d", &n) != EOF) {
        // Since n = 2^x, x is log2(n)
        // log2() is available in math.h
        printf("%d\n", (int)log2(n));
    }
    return 0;
}

