#include <stdio.h>
#include <math.h>

int main() {
    int A, B, C;

    while (scanf("%d", &A) == 1 && A != 0) {
        scanf("%d %d", &B, &C);

        double area_rect = (double)A * B;
        double area_building = (area_rect * 100.0) / C;
        int side_length = (int)sqrt(area_building);

        printf("%d\n", side_length);
    }

    return 0;
}
