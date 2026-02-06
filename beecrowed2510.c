#include <stdio.h>

int main() {
    int num_test_cases;
    // Read the number of test cases from input
    scanf("%d", &num_test_cases);

    // Loop through each test case
    for (int i = 0; i < num_test_cases; i++) {
        // Create a buffer for the villain name. The problem implies the name exists, but we can ignore it.
        // We read a string just to consume the input line for the current test case.
        char villain_name[101];
        scanf("%s", villain_name);
        // Print "Y" for each case, as the answer is always yes
        printf("Y\n");
    }

    return 0;
}

