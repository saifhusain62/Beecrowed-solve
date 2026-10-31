#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, d;
    double x1, x2;
    
    // Read coefficients or limits depending on the exact test cases of problem 1230
    // Example structure for numerical integration / polynomial evaluation
    while (scanf("%lf %lf %lf %lf", &a, &b, &c, &d) != EOF) {
        // Compute the definite integral or area based on the problem formula
        // Example: ∫ (ax^3 + bx^2 + cx + d) dx from x1 to x2
        double result = (a * pow(x2, 4) / 4.0 + b * pow(x2, 3) / 3.0 + c * pow(x2, 2) / 2.0 + d * x2) 
                      - (a * pow(x1, 4) / 4.0 + b * pow(x1, 3) / 3.0 + c * pow(x1, 2) / 2.0 + d * x1);
        
        printf("%.4f\n", result);
    }
    
    0;
}
