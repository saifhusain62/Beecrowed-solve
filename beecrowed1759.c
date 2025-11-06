#include <stdio.h>

int main() {
    int n, i;

    // Read the input integer N
    scanf("%d", &n);

    // Loop N times to print "Ho"
    for (i = 0; i < n; i++) {
        printf("Ho");
        // If it's not the last "Ho", print a space
        if (i < n - 1) {
            printf(" ");
        }
    }

    // After the loop, print the exclamation mark
    printf("!\n");

    return 0;
}
