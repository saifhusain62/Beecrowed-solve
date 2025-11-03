#include <stdio.h>
#include <string.h>

int main() {
    char input_string[10]; // A small buffer is sufficient for "25"

    while (scanf("%s", input_string) != EOF) {
        if (strcmp(input_string, "25") == 0) {
            printf("FELIZ NATAL!\n");
        } else {
            printf("NAO EH NATAL!\n");
        }
    }

    return 0;
}
