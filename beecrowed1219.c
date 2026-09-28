#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897

int main() {
    double a, b, c;

    // Read inputs until the End Of File (EOF)
    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
        // Semi-perimeter of the triangle
        double s = (a + b + c) / 2.0;
        
        // Area of the triangle using Heron's Formula
        double area_triangle = sqrt(s * (s - a) * (s - b) * (s - c));
        
        // Inner circle (Roses) radius and area
        double r_inner = area_triangle / s;
        double area_roses = PI * r_inner * r_inner;
        
        // Outer circle (Sunflowers) radius and area
        double r_outer = (a * b * c) / (4.0 * area_triangle);
        double area_outer_circle = PI * r_outer * r_outer;
        
        // Calculations for final regions
        double area_violets = area_triangle - area_roses;
        double area_sunflowers = area_outer_circle - area_triangle;
        
        // Print the results with 4 decimal places
        printf("%.4lf %.4lf %.4lf\n", area_sunflowers, area_violets, area_roses);
    }

    return 0;
}
