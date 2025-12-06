#include <stdio.h>
#include <string.h> // Required for string operations if needed, though not strictly for this problem

int main() {
    int N;
    char course[100]; // Buffer to store the input course names

    // Read the number of test cases
    scanf("%d", &N);

    // Loop N times to read each course name
    for (int i = 0; i < N; i++) {
        scanf("%s", course); // Read the course name (string)
    }

    // Print the fixed output string
    printf("Ciencia da Computacao\n");

    return 0;
}
