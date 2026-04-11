#include <stdio.h>
#include <math.h>

int main() {
    int n, cases;
    // Read number of test cases
    if (scanf("%d", &cases) != 1) return 0;

    while (cases--) {
        if (scanf("%d", &n) != 1) break;

        // Total grains formula: 2^x, where x is squares
        // For x=64, 2^64 is > unsigned long long max,
        // but problem constraints (1-64) and kg/12000
        // allows using unsigned long long for 2^n / 12000.

        // pow(2, n) returns double, we calculate directly to avoid precision issues
        unsigned long long total_grains;

        if (n == 64) {
            // Special case 2^64 exceeds unsigned long long
            // 2^64 / 12000 = 1537228672809129.3
            printf("1537228672809129 kg\n");
        } else {
            total_grains = (unsigned long long)pow(2, n);
            printf("%llu kg\n", total_grains / 12000);
        }
    }

    return 0;
}

