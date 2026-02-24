#include <stdio.h>
#include <string.h>

int main() {
    int n, l, c;
    // Read n (words), l (lines/page), c (chars/line)
    while (scanf("%d %d %d", &n, &l, &c) != EOF) {
        char word[1005];
        int current_line_chars = 0;
        int current_lines = 1;
        int current_pages = 1;

        for (int i = 0; i < n; i++) {
            scanf("%s", word);
            int word_len = strlen(word);

            // If word fits in the current line
            if (current_line_chars + word_len <= c) {
                current_line_chars += word_len;
                // Add space if not the end of the line
                if (current_line_chars < c) {
                    current_line_chars++;
                }
            }
            // Word needs a new line
            else {
                current_lines++;
                current_line_chars = word_len;
                // Add space if not the end of the line
                if (current_line_chars < c) {
                    current_line_chars++;
                }
            }

            // If lines exceed max lines per page
            if (current_lines > l) {
                current_pages++;
                current_lines = 1;
            }
        }
        printf("%d\n", current_pages);
    }
    return 0;
}

