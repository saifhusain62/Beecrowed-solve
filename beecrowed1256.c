#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Function to insert a key at the end of the linked list (FIFO)
void insertEnd(Node** head, int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to free the memory of the linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    for (int t = 0; t < N; t++) {
        int M, C;
        if (scanf("%d %d", &M, &C) != 2) break;

        // Initialize hash table slots to NULL
        Node** hashTable = (Node**)malloc(M * sizeof(Node*));
        for (int i = 0; i < M; i++) {
            hashTable[i] = NULL;
        }

        // Read keys and insert into the correct address
        for (int i = 0; i < C; i++) {
            int key;
            scanf("%d", &key);
            int index = key % M;
            insertEnd(&hashTable[index], key);
        }

        // Print the hash table structure
        for (int i = 0; i < M; i++) {
            printf("%d -> ", i);
            Node* temp = hashTable[i];
            while (temp != NULL) {
                printf("%d -> ", temp->key);
                temp = temp->next;
            }
            printf("\\n");
        }

        // Print blank line between test cases
        if (t < N - 1) {
            printf("\n");
        }

        // Free allocated memory for this test case
        for (int i = 0; i < M; i++) {
            freeList(hashTable[i]);
        }
        free(hashTable);
    }

    return 0;
}

