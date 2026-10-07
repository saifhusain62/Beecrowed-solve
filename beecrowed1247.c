#include <stdio.h>
#include <math.h>

int main() {
    double d, vf, vg;

    // Read inputs until End-Of-File (EOF)
    while (scanf("%lf %lf %lf", &d, &vf, &vg) != EOF) {
        // Calculate the distance the Coast Guard needs to travel
        double distance_g = sqrt((d * d) + 144.0);

        // Calculate travel times for both
        double time_f = 12.0 / vf;
        double time_g = distance_g / vg;

        // If Coast Guard's time is less than or equal to the fugitive's time
        if (time_g <= time_f) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }

    return 0;
}
