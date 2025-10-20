#include <stdio.h>
#include <string.h>

int main() {
    int T; // Number of test cases
    scanf("%d", &T);
    getchar(); // Consume the newline character after reading T

    while (T--) {
        char str[1001]; // Array to store the input string
        fgets(str, sizeof(str), stdin); // Read the entire line including spaces
        str[strcspn(str, "\n")] = 0; // Remove the trailing newline character

        int len = strlen(str);

        // Step 1: Shift letters
        for (int i = 0; i < len; i++) {
            if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
                str[i] += 3;
            }
        }

        // Step 2: Reverse the string
        char temp_str[1001];
        int j = 0;
        for (int i = len - 1; i >= 0; i--) {
            temp_str[j++] = str[i];
        }
        temp_str[j] = '\0'; // Null-terminate the reversed string

        // Step 3: Shift second half
        for (int i = len / 2; i < len; i++) {
            temp_str[i] -= 1;
        }

        printf("%s\n", temp_str);
    }

    return 0;
}
