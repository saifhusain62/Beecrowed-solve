#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100005

typedef struct {
    int children[26];
} Node;

Node prefixTrie[MAX_NODES];
Node suffixTrie[MAX_NODES];
int p_count, s_count;

// Count nodes starting with a specific character
long long p_char_count[26], s_char_count[26];

int newNode(Node trie[], int *cnt) {
    memset(trie[*cnt].children, 0, sizeof(int) * 26);
    return (*cnt)++;
}

void insertPrefix(char *s) {
    int curr = 0;
    for (int i = 0; s[i]; i++) {
        int c = s[i] - 'a';
        if (!prefixTrie[curr].children[c]) {
            prefixTrie[curr].children[c] = newNode(prefixTrie, &p_count);
            if (i > 0) p_char_count[c]++; // Ignore root-level starts for subtraction logic
        }
        curr = prefixTrie[curr].children[c];
    }
}

void insertSuffix(char *s) {
    int len = strlen(s);
    int curr = 0;
    for (int i = len - 1; i >= 0; i--) {
        int c = s[i] - 'a';
        if (!suffixTrie[curr].children[c]) {
            suffixTrie[curr].children[c] = newNode(suffixTrie, &s_count);
            if (i < len - 1) s_char_count[c]++;
        }
        curr = suffixTrie[curr].children[c];
    }
}

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M) && (N || M)) {
        p_count = 0; s_count = 0;
        memset(p_char_count, 0, sizeof(p_char_count));
        memset(s_char_count, 0, sizeof(s_char_count));
        newNode(prefixTrie, &p_count);
        newNode(suffixTrie, &s_count);

        char word[1005];
        for (int i = 0; i < N; i++) {
            scanf("%s", word);
            insertPrefix(word);
        }
        for (int i = 0; i < M; i++) {
            scanf("%s", word);
            insertSuffix(word);
        }

        // Total unique non-empty prefixes * total unique non-empty suffixes
        long long total = (long long)(p_count - 1) * (s_count - 1);

        // Subtract overlaps: (prefix + char) + suffix == prefix + (char + suffix)
        for (int i = 0; i < 26; i++) {
            total -= p_char_count[i] * s_char_count[i];
        }

        printf("%lld\n", total);
    }
    return 0;
}

