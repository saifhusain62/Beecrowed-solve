#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to group an ASCII value and its frequency
typedef struct {
    int ascii;
    int freq;
} CharFreq;

// Custom sorting function for qsort
int compare(const void *a, const void *b) {
    CharFreq *cA = (CharFreq *)a;
    CharFreq *cB = (CharFreq *)b;

    // 1. Sort by frequency in ascending order
    if (cA->freq != cB->freq) {
        return cA->freq - cB->freq;
    }
    // 2. If frequencies match, sort by ASCII value in descending order
    return cB->ascii - cA->ascii;
}

int main() {
    char line[1005];
    int first_case = 1;

    // Read input line by line until End-Of-File (EOF)
    while (fgets(line, sizeof(line), stdin)) {

        // Print a blank line between output blocks (but not before the first block)
        if (!first_case) {
            printf("\n");
        }
        first_case = 0;

        // Initialize tracking arrays
        int count[256] = {0};
        CharFreq unique_chars[256];
        int total_unique = 0;

        // Count character frequencies
        for (int i = 0; line[i] != '\0'; i++) {
            // Ignore newline and carriage return characters
            if (line[i] == '\n' || line[i] == '\r') {
                continue;
            }
            count[(unsigned char)line[i]]++;
        }

        // Populate the structure array with present characters
        for (int i = 0; i < 256; i++) {
            if (count[i] > 0) {
                unique_chars[total_unique].ascii = i;
                unique_chars[total_unique].freq = count[i];
                total_unique++;
            }
        }

        // Sort using the custom comparison rules
        qsort(unique_chars, total_unique, sizeof(CharFreq), compare);

        // Print results
        for (int i = 0; i < total_unique; i++) {
            printf("%d %d\n", unique_chars[i].ascii, unique_chars[i].freq);
        }
    }

    return 0;
}

