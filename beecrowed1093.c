#include <stdio.h>
#include <math.h>

double calculate_probability(int n1, int n2, int at) {
    // If probability is 50% (AT = 3)
    if (at == 3) {
        return (double)n1 / (n1 + n2);
    }

    // General Gambler's Ruin formula
    double p = (double)at / 6.0;
    double q = 1.0 - p;
    double ratio = q / p;

    return (1.0 - pow(ratio, n1)) / (1.0 - pow(ratio, n1 + n2));
}

int main() {
    int ev1, ev2, at, d;

    // Read input until all values are 0
    while (scanf("%d %d %d %d", &ev1, &ev2, &at, &d) && (ev1 != 0)) {
        // Calculate number of hits needed (ceil of EV/D)
        int n1 = 0, n2 = 0;

        int temp = ev1;
        while (temp > 0) { temp -= d; n1++; }

        temp = ev2;
        while (temp > 0) { temp -= d; n2++; }

        double result = calculate_probability(n1, n2, at);
        // Print with 1 decimal place as required
        printf("%.1f\n", result * 100.0);
    }

    return 0;
}

