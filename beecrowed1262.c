#include <stdio.h>
#include <string.h>

int main() {
    char trace[1000];
    int p;

    // Read trace string and process limit until EOF
    while (scanf("%s %d", trace, &p) != EOF) {
        int cycles = 0;
        int i = 0;
        int len = strlen(trace);

        while (i < len) {
            if (trace[i] == 'W') {
                // Write takes 1 cycle
                cycles++;
                i++;
            } else if (trace[i] == 'R') {
                // Read: count consecutive reads
                int read_count = 0;
                while (i < len && trace[i] == 'R' && read_count < p) {
                    read_count++;
                    i++;
                }
                // Group of reads takes 1 cycle
                cycles++;
            }
        }
        printf("%d\n", cycles);
    }
    return 0;
}

