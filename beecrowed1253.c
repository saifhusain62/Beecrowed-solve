#include <stdio.h>
#include <string.h>

int main() {
    int i, j, k, l, t;
    scanf("%d", &t); // number of test cases

    for (i = 0; i < t; i++) {
        char str[51]; // string buffer
        int offset;
        scanf("%s", str); // read the encrypted string
        scanf("%d", &offset); // read the offset value

        // consume the newline character left by the second scanf
        // getchar();

        l = strlen(str); // get the length of the string

        for (k = 0; k < l; k++) {
            char converted_char = str[k] - offset; // perform the shift

            if (converted_char < 65) {
                // wrap around the alphabet if the shift goes below 'A' (ASCII 65)
                converted_char += 26;
            }
            printf("%c", converted_char); // print the decrypted character
        }
        printf("\n"); // print a newline after each test case output
    }
    return 0;
}

