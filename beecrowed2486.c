#include <stdio.h>
#include <string.h>

int main() {
    int T; // Number of test cases/items in a single consumption report
    int total_vitamin_c, quantity;
    char food_name[50]; // Buffer to store the food name. Use a reasonable size.
    int vitamin_c_per_unit;

    // The problem involves multiple test cases, terminated by T = 0
    while (scanf("%d", &T) && T != 0) {
        total_vitamin_c = 0;

        for (int i = 0; i < T; ++i) {
            scanf("%d", &quantity);
            // Read the rest of the line, including leading spaces, into food_name
            // This is crucial to handle multi-word food names correctly.
            scanf("%[^\n]", food_name);

            // Determine Vitamin C content based on the food name
            if (strcmp(food_name, " suco de laranja") == 0) {
                vitamin_c_per_unit = 120;
            } else if (strcmp(food_name, " morango fresco") == 0) {
                vitamin_c_per_unit = 85;
            } else if (strcmp(food_name, " mamao") == 0) {
                vitamin_c_per_unit = 85;
            } else if (strcmp(food_name, " goiaba vermelha") == 0) {
                vitamin_c_per_unit = 70;
            } else if (strcmp(food_name, " manga") == 0) {
                vitamin_c_per_unit = 56;
            } else if (strcmp(food_name, " laranja") == 0) {
                vitamin_c_per_unit = 50;
            } else if (strcmp(food_name, " brocolis") == 0) {
                vitamin_c_per_unit = 34;
            } else {
                vitamin_c_per_unit = 0; // Should not happen with given inputs
            }

            total_vitamin_c += quantity * vitamin_c_per_unit;
        }

        // Output the result
        if (total_vitamin_c > 130) {
            printf("Menos %d mg\n", total_vitamin_c - 130);
        } else if (total_vitamin_c < 110) {
            printf("Mais %d mg\n", 110 - total_vitamin_c);
        } else {
            printf("%d mg\n", total_vitamin_c);
        }
    }

    return 0;
}

