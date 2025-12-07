#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Check all possible combinations of three sticks
    if ( (a + b > c && a + c > b && b + c > a) || // a, b, c
         (a + b > d && a + d > b && b + d > a) || // a, b, d
         (a + c > d && a + d > c && c + d > a) || // a, c, d
         (b + c > d && b + d > c && c + d > b) )  // b, c, d
    {
        printf("S\n"); // "S" for Sim (Yes)
    } else {
        printf("N\n"); // "N" for Nao (No)
    }

    return 0;
}
