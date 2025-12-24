#include <stdio.h>

int main() {
    int h, m, maximum_delay;

    // Loop to read multiple test cases until End Of File (EOF)
    while (scanf("%d:%d", &h, &m) != EOF) {
        printf("Atraso maximo: ");

        // Check if the arrival time is before or at the scheduled time (8:00 AM)
        if (h < 7 || (h == 7 && m == 0)) {
            maximum_delay = 0;
        } else {
            // Calculate delay in minutes
            // The base delay is from 7:00 AM to the hour before arrival
            // e.g., if arrival is 8:00 AM, h+1 is 9, (9-8)*60 = 60 minutes
            maximum_delay = ((h + 1) - 8) * 60 + m;
        }

        printf("%d\n", maximum_delay);
    }

    return 0;
}

