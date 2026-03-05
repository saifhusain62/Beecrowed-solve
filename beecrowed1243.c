#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int is_valid_word(char *word, int len) {
    if (len == 0) return 0;
    for (int i = 0; i < len; i++) {
        if (!isalpha(word[i])) {
            return 0; // Contains non-letter characters (numbers, etc.)
        }
    }
    return 1;
}

int main() {
    char line[1000005]; // Large buffer for input lines
    while (fgets(line, sizeof(line), stdin)) {
        long long total_length = 0;
        long long word_count = 0;
        char *token = strtok(line, " \n\r\t");

        while (token != NULL) {
            int len = strlen(token);
            // Handle trailing '.' specifically
            if (token[len - 1] == '.') {
                token[len - 1] = '\0';
                len--;
            }

            if (is_valid_word(token, len)) {
                total_length += len;
                word_count++;
            }
            token = strtok(NULL, " \n\r\t");
        }

        int avg = 0;
        if (word_count > 0) {
            avg = floor(total_length / word_count);
        }

        if (avg <= 3) printf("250\n");
        else if (avg <= 5) printf("500\n");
        else printf("1000\n");
    }
    return 0;
}

