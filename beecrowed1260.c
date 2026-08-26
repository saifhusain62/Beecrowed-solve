#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREES 10005
#define MAX_NAME_LEN 35

// Comparison function for qsort to sort tree names alphabetically
int compare(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int test_cases;
    char line[MAX_NAME_LEN];
    // Dynamic allocation of 2D array to stay safely within memory limits
    char (*trees)[MAX_NAME_LEN] = malloc(MAX_TREES * sizeof(*trees));

    if (scanf("%d", &test_cases) != 1) {
        free(trees);
        return 0;
    }

    // Consume the newline character after reading the test case count
    getchar();
    // Consume the initial blank line before the first test case
    getchar();

    for (int t = 0; t < test_cases; t++) {
        int total_trees = 0;

        // Read all tree names for the current test case
        while (fgets(line, sizeof(line), stdin)) {
            // A blank line signifies the end of the current testcase block
            if (line[0] == '\n' || line[0] == '\r') {
                break;
            }

            // Remove trailing newline character standard to fgets()
            line[strcspn(line, "\n\r")] = '\0';

            // Store the tree name in our tracking array
            strcpy(trees[total_trees], line);
            total_trees++;
        }

        // Sort the entire list of collected trees alphabetically
        qsort(trees, total_trees, MAX_NAME_LEN, compare);

        // Process sorted trees to count duplicates and print percentages
        int i = 0;
        while (i < total_trees) {
            int count = 1;
            // Count all occurrences of identical consecutive names
            while (i + 1 < total_trees && strcmp(trees[i], trees[i + 1]) == 0) {
                count++;
                i++;
            }

            // Calculate and display population percentage to 4 decimal places
            double percentage = (double)count * 100.0 / total_trees;
            printf("%s %.4f\n", trees[i], percentage);
            i++;
        }

        // Print a separating blank line between test cases (but not after the last one)
        if (t < test_cases - 1) {
            printf("\n");
        }
    }

    free(trees);
    return 0;
}

