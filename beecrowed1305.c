#include <stdio.h>
#include <math.h>

int main() {
    char num_str[100], cutoff_str[100];

    // Read input until EOF (End of File)
    while (scanf("%s %s", num_str, cutoff_str) != EOF) {
        double num, cutoff;

        // Convert strings to double
        sscanf(num_str, "%lf", &num);
        sscanf(cutoff_str, "%lf", &cutoff);

        // Get the integer part and the fractional part
        int integer_part = (int)num;
        double fractional_part = num - integer_part;

        // Rounding logic
        if (fractional_part > cutoff) {
            printf("%d\n", integer_part + 1);
        } else {
            printf("%d\n", integer_part);
        }
    }

    return 0;
}

