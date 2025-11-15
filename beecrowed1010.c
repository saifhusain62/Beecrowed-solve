#include <stdio.h>

int main() {
    int code1, units1, code2, units2;
    float price1, price2;
    double total_value; // Use double for better precision in calculations

    // Read input for the first product
    scanf("%d %d %f", &code1, &units1, &price1);

    // Read input for the second product
    scanf("%d %d %f", &code2, &units2, &price2);

    // Calculate the total value
    total_value = (double)units1 * price1 + (double)units2 * price2;

    // Print the result formatted to two decimal places
    printf("VALOR A PAGAR: R$ %.2f\n", total_value);

    return 0;
}
