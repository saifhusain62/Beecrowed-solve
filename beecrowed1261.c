#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20

// Structure to hold the Hay Point word and its value
typedef struct {
    char word[MAX_WORD_LEN + 1];
    long long value;
} HayPoint;

// Comparison function for sorting and binary searching
int comparePoints(const void *a, const void *b) {
    return strcmp(((HayPoint *)a)->word, ((HayPoint *)b)->word);
}

int main() {
    int m, n;

    // Read M (number of words) and N (number of descriptions)
    if (scanf("%d %d", &m, &n) != 2) return 0;

    // Allocate memory for the dictionary array
    HayPoint *dictionary = (HayPoint *)malloc(m * sizeof(HayPoint));
    if (dictionary == NULL) return 1;

    // Populate the dictionary
    for (int i = 0; i < m; i++) {
        scanf("%s %lld", dictionary[i].word, &dictionary[i].value);
    }

    // Sort the dictionary alphabetically to enable binary search
    qsort(dictionary, m, sizeof(HayPoint), comparePoints);

    // Process each of the N job descriptions
    char currentWord[MAX_WORD_LEN + 1];
    for (int i = 0; i < n; i++) {
        long long totalSalary = 0;

        // Read strings word-by-word until a single dot "." is encountered
        while (scanf("%s", currentWord) == 1 && strcmp(currentWord, ".") != 0) {
            HayPoint key;
            strcpy(key.word, currentWord);

            // Perform binary search on the sorted dictionary
            HayPoint *found = (HayPoint *)bsearch(&key, dictionary, m, sizeof(HayPoint), comparePoints);

            // If the word exists in the dictionary, add its value to the total salary
            if (found != NULL) {
                totalSalary += found->value;
            }
        }

        // Print the calculated salary for the description
        printf("%lld\n", totalSalary);
    }

    // Free dynamically allocated memory
    free(dictionary);

    return 0;
}

