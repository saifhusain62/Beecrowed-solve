#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Helper to check if characters match case-insensitively
int match_case_insensitive(char *s1, char *s2, int len) {
    for (int i = 0; i < len; i++) {
        if (tolower(s1[i]) != tolower(s2[i])) return 0;
    }
    return 1;
}

void solve(char *tag, int num, char *line) {
    int i = 0, j = 0;
    int tag_len = strlen(tag);
    int line_len = strlen(line);
    char result[10000]; // Buffer for the output
    int res_idx = 0;
    int in_tag = 0;

    while (line[i] != '\0' && line[i] != '\r' && line[i] != '\n') {
        if (line[i] == '<') {
            in_tag = 1;
            result[res_idx++] = line[i++];
        } else if (line[i] == '>') {
            in_tag = 0;
            result[res_idx++] = line[i++];
        } else if (in_tag) {
            // Inside tag: check for match
            if (strncasecmp(&line[i], tag, tag_len) == 0) {
                // Match found, replace with number
                char num_str[15];
                sprintf(num_str, "%d", num);
                for (int k = 0; num_str[k]; k++) {
                    result[res_idx++] = num_str[k];
                }
                i += tag_len;
            } else {
                result[res_idx++] = line[i++];
            }
        } else {
            // Outside tag
            result[res_idx++] = line[i++];
        }
    }
    result[res_idx] = '\0';
    printf("%s\n", result);
}

int main() {
    char tag[20], line[5000];
    int num;
    // Read tag and number, then read the rest of the line including spaces
    while (scanf("%s %d%*c", tag, &num) != EOF) {
        if (fgets(line, sizeof(line), stdin)) {
            solve(tag, num, line);
        }
    }
    return 0;
}

