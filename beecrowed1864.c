#include <stdio.h>
#include <string.h>

int main() {
    int N;
    // The given phrase
    char phrase[] = "LIFE IS NOT A PROBLEM TO BE SOLVED";

    // Read the input integer N
    scanf("%d", &N);

    // Print the first N characters of the phrase
    for (int i = 0; i < N; i++) {
        printf("%c", phrase[i]);
    }

    // Print a newline character at the end of the output
    printf("\n");

    return 0;
}

