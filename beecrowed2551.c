#include <stdio.h>

int main() {
    int n, i;
    double t, d, avg, max_speed;

    // Read the number of training days for each test case
    while (scanf("%d", &n) != EOF) {
        max_speed = 0;

        for (i = 1; i <= n; i++) {
            // Read duration (t) and distance (d)
            scanf("%lf %lf", &t, &d);

            avg = d / t;

            // On the first day or if a new record is set
            if (i == 1 || avg > max_speed) {
                printf("%d\n", i);
                max_speed = avg;
            }
        }
    }

    return 0;
}

