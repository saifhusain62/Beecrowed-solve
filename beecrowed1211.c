#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_LEN 205

// Structure to hold each phone number
typedef struct {
    char num[MAX_LEN];
} PhoneNumber;

// Comparison function for qsort to sort lexicographically
int compare(const void *a, const void *b) {
    return strcmp(((PhoneNumber *)a)->num, ((PhoneNumber *)b)->num);
}

PhoneNumber phonebook[MAX_N];

int main() {
    int n;

    // Read input until End-Of-File (EOF)
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%s", phonebook[i].num);
        }

        // Sort the phone numbers to bring identical prefixes together
        qsort(phonebook, n, sizeof(PhoneNumber), compare);

        int saved_characters = 0;

        // Compare each phone number with the previous one
        for (int i = 1; i < n; i++) {
            int j = 0;
            // Count matching characters from the beginning
            while (phonebook[i].num[j] != '\0' && phonebook[i].num[j] == phonebook[i - 1].num[j]) {
                saved_characters++;
                j++;
            }
        }

        // Print the total number of saved characters for the test case
        printf("%d\n", saved_characters);
    }

    return 0;
}

