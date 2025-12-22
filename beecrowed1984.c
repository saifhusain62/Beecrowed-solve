#include <stdio.h>
#include <string.h>

int main() {
    char num[25]; // A character array large enough to hold the input number as a string
    int i, j;
    char temp;

    // Read the input number as a string
    scanf("%s", num);

    // Get the length of the string
    int lnth = strlen(num);

    // Reverse the string by swapping characters from the ends inwards
    for (i = 0, j = lnth - 1; i < lnth / 2; i++, j--) {
        temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }

    // Print the reversed string followed by a newline
    printf("%s\n", num);

    return 0;
}

