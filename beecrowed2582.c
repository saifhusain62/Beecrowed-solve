#include <stdio.h>

int main() {
    int x, y, T;
    // Define an array of strings corresponding to the song titles
    char s[11][30] = {"PROXYCITY", "P.Y.N.G.", "DNSUEY!", "SERVERS", "HOST!", "CRIPTONIZE", "OFFLINE DAY", "SALT", "ANSWER!", "RAR?", "WIFI ANTENNAS"};

    // Read the number of test cases
    scanf("%d", &T);

    while (T--) {
        // Read the two input integers for each test case
        scanf("%d %d", &x, &y);
        // Print the string at the index which is the sum of x and y
        printf("%s\n", s[x + y]);
    }

    return 0;
}

