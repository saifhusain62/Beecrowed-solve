#include <stdio.h>
#include <math.h>

int main() {
    int n, city_count = 1;
    int first_city = 1;

    while (scanf("%d", &n) && n != 0) {
        if (!first_city) printf("\n");
        first_city = 0;

        int residents_at_consumption[201] = {0};
        long long total_residents = 0;
        long long total_consumption = 0;

        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            int consumption_per_person = y / x;
            residents_at_consumption[consumption_per_person] += x;
            total_residents += x;
            total_consumption += y;
        }

        printf("Cidade# %d:\n", city_count++);

        int first_print = 1;
        for (int i = 0; i <= 200; i++) {
            if (residents_at_consumption[i] > 0) {
                if (!first_print) printf(" ");
                printf("%d-%d", residents_at_consumption[i], i);
                first_print = 0;
            }
        }

        // Truncate to two decimal places
        double average = (double)total_consumption / total_residents;
        // Using floor to manually format the decimal parts
        int integer_part = (int)average;
        int decimal_part = (int)(average * 100) % 100;

        printf("\nConsumo medio: %d.%02d m3.\n", integer_part, decimal_part);
    }

    return 0;
}

