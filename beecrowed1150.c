#include <stdio.h>

int main() {
    int X, Z;
    int sum = 0;
    int count = 0;

    // Read X
    scanf("%d", &X);

    // Read Z, ensuring Z is greater than X
    do {
        scanf("%d", &Z);
    } while (Z <= X);

    // Calculate the sum and count
    int current_num = X;
    while (sum <= Z) {
        sum += current_num;
        current_num++;
        count++;
    }

    // Print the count
    printf("%d\n", count);

    return 0;
}
