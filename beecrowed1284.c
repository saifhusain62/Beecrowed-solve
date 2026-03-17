#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int count_children;
    int is_end;
} TrieNode;

TrieNode* create_node() {
    TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));
    node->is_end = 0;
    node->count_children = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

void insert(TrieNode *root, char *word) {
    TrieNode *curr = root;
    while (*word) {
        int idx = *word - 'a';
        if (!curr->children[idx]) {
            curr->children[idx] = create_node();
            curr->count_children++;
        }
        curr = curr->children[idx];
        word++;
    }
    curr->is_end = 1;
}

int count_keystrokes(TrieNode *root, char *word) {
    int keystrokes = 1; // First character always requires a press
    TrieNode *curr = root->children[*word - 'a'];
    word++;

    while (*word) {
        // Press key if:
        // 1. Multiple paths exist (count_children > 1)
        // 2. Current path is an end of a word but continues (is_end == 1)
        if (curr->count_children > 1 || curr->is_end) {
            keystrokes++;
        }
        curr = curr->children[*word - 'a'];
        word++;
    }
    return keystrokes;
}

void delete_trie(TrieNode *root) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) delete_trie(root->children[i]);
    }
    free(root);
}

int main() {
    int N;
    char words[100005][85];
    while (scanf("%d", &N) != EOF) {
        TrieNode *root = create_node();
        for (int i = 0; i < N; i++) {
            scanf("%s", words[i]);
            insert(root, words[i]);
        }

        long long total_keystrokes = 0;
        for (int i = 0; i < N; i++) {
            total_keystrokes += count_keystrokes(root, words[i]);
        }

        printf("%.2f\n", (double)total_keystrokes / N);
        delete_trie(root);
    }
    return 0;
}

