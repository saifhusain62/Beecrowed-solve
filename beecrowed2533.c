#include <stdio.h>

int main() {
    int m;
    // Read the number of subjects, continue until EOF
    while (scanf("%d", &m) != EOF) {
        double total_nc = 0; // Sum of Grade * Workload
        double total_c = 0;  // Sum of Workload

        for (int i = 0; i < m; ++i) {
            double n, c;
            scanf("%lf %lf", &n, &c);
            total_nc += (n * c);
            total_c += c;
        }

        // Calculate IRA: Sum(N*C) / (Sum(C) * 100)
        double ira = total_nc / (total_c * 100.0);

        // Print result with 4 decimal places
        printf("%.4lf\n", ira);
    }

    return 0;
}

