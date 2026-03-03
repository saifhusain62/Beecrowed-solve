#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char line[100];
    // Read input until EOF
    while (fgets(line, sizeof(line), stdin)) {
        bool italic = false;
        bool bold = false;

        for (int i = 0; line[i] != '\0' && line[i] != '\n' && line[i] != '\r'; i++) {
            if (line[i] == '_') {
                if (!italic) {
                    printf("<i>");
                    italic = true;
                } else {
                    printf("</i>");
                    italic = false;
                }
            } else if (line[i] == '*') {
                if (!bold) {
                    printf("<b>");
                    bold = true;
                } else {
                    printf("</b>");
                    bold = false;
                }
            } else {
                printf("%c", line[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

