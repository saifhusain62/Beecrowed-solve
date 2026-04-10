
#include <stdio.h>
#include <math.h>

#define PI 3.14159
#define G 9.80665

int main() {
    double h, p1, p2, alpha, v, vx, vy, t, dist;
    int n;

    // Read initial height and target range [p1, p2]
    while (scanf("%lf", &h) != EOF) {
        scanf("%lf %lf", &p1, &p2);
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &alpha, &v);

            // Convert angle to radians
            double rad = (alpha * PI) / 180.0;

            // Calculate velocity components
            vx = v * cos(rad);
            vy = v * sin(rad);

            // Calculate total flight time using the quadratic formula
            // Derived from: -0.5*g*t^2 + vy*t + h = 0
            t = (vy + sqrt(pow(vy, 2) + 2 * G * h)) / G;

            // Calculate horizontal distance
            dist = vx * t;

            // Output result and check if it hits the target range
            if (dist >= p1 && dist <= p2) {
                printf("%.5lf -> DUCK\n", dist);
            } else {
                printf("%.5lf -> NUCK\n", dist);
            }
        }
    }

    return 0;
}
