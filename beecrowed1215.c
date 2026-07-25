#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 10005
#define MAX_LEN 205

// Comparison function for qsort to sort words alphabetically
int compare(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    char dictionary[MAX_WORDS][MAX_LEN];
    int word_count = 0;
    char current_word[MAX_LEN];
    int len = 0;
    int c;

    // Read input character by character until End-Of-File (EOF)
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            // Build the word and convert it to lowercase
            current_word[len++] = tolower(c);
        } else {
            // Non-alphabetical character marks the end of a word
            if (len > 0) {
                current_word[len] = '\0';

                // Check if the word is already in the dictionary
                int exists = 0;
                for (int i = 0; i < word_count; i++) {
                    if (strcmp(dictionary[i], current_word) == 0) {
                        exists = 1;
                        break;
                    }
                }

                // If it is a new unique word, add it
                if (!exists && word_count < MAX_WORDS) {
                    strcpy(dictionary[word_count], current_word);
                    word_count++;
                }
                len = 0; // Reset length for the next word
            }
        }
    }

    // Handle the last word if the file didn't end with a non-alpha character
    if (len > 0) {
        current_word[len] = '\0';
        int exists = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(dictionary[i], current_word) == 0) {
                exists = 1;
                break;
            }
        }
        if (!exists && word_count < MAX_WORDS) {
            strcpy(dictionary[word_count], current_word);
            word_count++;
        }
    }

    // Sort the unique words alphabetically
    qsort(dictionary, word_count, MAX_LEN, compare);

    // Print the sorted dictionary
    for (int i = 0; i < word_count; i++) {
        printf("%s\n", dictionary[i]);
    }

    return 0;
}

