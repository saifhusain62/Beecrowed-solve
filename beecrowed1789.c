#include <stdio.h>

int main() {
    int n, speed, max_speed;

    while (scanf("%d", &n) != EOF) {
        max_speed = 0; // Initialize max_speed for each test case

        for (int i = 0; i < n; i++) {
            scanf("%d", &speed);
            if (speed > max_speed) {
                max_speed = speed;
            }
        }

        if (max_speed < 10) {
            printf("1\n");
        } else if (max_speed >= 10 && max_speed < 20) {
            printf("2\n");
        } else { // max_speed >= 20
            printf("3\n");
        }
    }

    return 0;
}
