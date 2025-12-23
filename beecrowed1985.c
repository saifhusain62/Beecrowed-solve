#include <stdio.h>

int main() {
    int t, c, q, i;
    float total = 0;

    // Read the number of purchases (t)
    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        // Read the product code (c) and quantity (q) for each purchase
        scanf("%d %d", &c, &q);

        // Use a switch statement to determine the price based on the product code
        switch (c) {
            case 1001:
                total = total + (1.50 * q);
                break;
            case 1002:
                total = total + (2.50 * q);
                break;
            case 1003:
                total = total + (3.50 * q);
                break;
            case 1004:
                total = total + (4.50 * q);
                break;
            case 1005:
                total = total + (5.50 * q);
                break;
        }
    }

    // Print the total amount with two digits after the decimal point
    printf("%.2f\n", total);

    return 0;
}

