#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to hold a word and its original index for stable sorting
typedef struct {
    char text[51];
    int original_index;
    int length;
} Word;

// Comparison function for qsort
int compare(const void *a, const void *b) {
    Word *wordA = (Word *)a;
    Word *wordB = (Word *)b;

    // Sort by length in descending order
    if (wordA->length != wordB->length) {
        return wordB->length - wordA->length;
    }
    // If lengths are equal, maintain original input order (stable sort)
    return wordA->original_index - wordB->original_index;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // Consume the newline character left in the buffer after reading N
    getchar();

    char line[2600]; // Max 50 words * 50 chars + spaces

    while (n--) {
        if (!fgets(line, sizeof(line), stdin)) break;

        // Remove trailing newline if present
        line[strcspn(line, "\n")] = '\0';

        Word words[50];
        int word_count = 0;

        // Tokenize the input string by spaces
        char *token = strtok(line, " ");
        while (token != NULL) {
            strcpy(words[word_count].text, token);
            words[word_count].length = strlen(token);
            words[word_count].original_index = word_count;
            word_count++;
            token = strtok(NULL, " ");
        }

        // Sort the words using the stable comparison logic
        qsort(words, word_count, sizeof(Word), compare);

        // Print the sorted words separated by a single space
        for (int i = 0; i < word_count; i++) {
            printf("%s", words[i].text);
            if (i < word_count - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

