#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char line[1000];
    while (fgets(line, sizeof(line), stdin)) {
        long long result = 0;
        int hasDigits = 0;
        int error = 0;
        int i = 0;

        // Clean and parse the string
        for (i = 0; line[i] != '\0' && line[i] != '\n' && line[i] != '\r'; i++) {
            char c = line[i];
            if (isdigit(c)) {
                result = result * 10 + (c - '0');
                hasDigits = 1;
            } else if (c == 'o' || c == 'O') {
                result = result * 10 + 0;
                hasDigits = 1;
            } else if (c == 'l') {
                result = result * 10 + 1;
                hasDigits = 1;
            } else if (c == ',' || c == ' ') {
                continue; // Ignore commas and spaces
            } else {
                error = 1; // Invalid character
                break;
            }

            if (result > 2147483647) {
                error = 1;
                break;
            }
        }

        if (error || !hasDigits) {
            printf("error\n");
        } else {
            printf("%lld\n", result);
        }
    }
    return 0;
}

