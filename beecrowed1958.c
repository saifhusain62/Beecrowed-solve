#include <stdio.h>

int main() {
    long double number;

    // Use %LE for long double input
    scanf("%LE", &number);

    // Use %+.4LE for formatted output:
    // + ensures a sign is always printed (+ or -)
    // .4 specifies exactly four decimal places
    // L indicates long double
    // E indicates scientific notation with an uppercase 'E'
    printf("%+.4LE\n", number);

    return 0;
}

