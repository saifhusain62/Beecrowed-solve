#include <stdio.h>
#include <string.h>

void reverse(char *str, int length) {
    int i, j;
    char temp;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    int n, len, half_len;
    char line[110];

    // Read the number of test cases
    if (scanf("%d", &n) != 1) return 1;

    // Consume the newline character left in the buffer by scanf
    getchar();

    while (n--) {
        // Read the entire line including spaces
        fgets(line, sizeof(line), stdin);

        // Remove the newline character at the end of the line
        len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }

        half_len = len / 2;

        // Reverse the first half of the string
        reverse(line, half_len);

        // Reverse the second half of the string (starting from the middle)
        reverse(line + half_len, half_len);

        // Print the result
        printf("%s\n", line);
    }

    return 0;
}

