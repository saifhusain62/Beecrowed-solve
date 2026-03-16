#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void format_string(char *str, char *result) {
    char *token;
    char *temp = (char*)malloc(strlen(str) + 1);
    strcpy(temp, str);
    result[0] = '\0';
    token = strtok(temp, " \t\n\r");
    while (token != NULL) {
        if (strlen(result) > 0) strcat(result, " ");
        strcat(result, token);
        token = strtok(NULL, " \t\n\r");
    }
    free(temp);
}

int main() {
    int n, first = 1;
    while (scanf("%d", &n) == 1 && n != 0) {
        if (!first) printf("\n");
        first = 0;

        char lines[n][100];
        char formatted[n][100];
        int max_len = 0;

        getchar(); // consume newline
        for (int i = 0; i < n; i++) {
            fgets(lines[i], 100, stdin);
            lines[i][strcspn(lines[i], "\n")] = 0; // remove newline
            format_string(lines[i], formatted[i]);
            int len = strlen(formatted[i]);
            if (len > max_len) max_len = len;
        }

        for (int i = 0; i < n; i++) {
            printf("%*s\n", max_len, formatted[i]);
        }
    }
    return 0;
}

