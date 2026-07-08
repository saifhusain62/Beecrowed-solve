
#include <stdio.h>
#include <stdlib.h>

// Structure representing a Node in a Circular Queue / Linked List
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure representing the Queue
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to initialize an empty queue
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to push an item to the back of the queue
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to remove and return the item at the front of the queue
int dequeue(Queue* q) {
    if (q->front == NULL) return -1;

    Node* temp = q->front;
    int value = temp->data;

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

int main() {
    int n;

    // Read input until '0' is given
    while (scanf("%d", &n) == 1 && n != 0) {
        Queue q;
        initQueue(&q);

        // Populate the deck with cards from 1 to n
        for (int i = 1; i <= n; i++) {
            enqueue(&q, i);
        }

        printf("Discarded cards:");

        int first_discard = 1;
        // Keep running the operations as long as there are at least two cards
        while (q.front != q.rear) {
            // Step 1: Throw away the top card
            int discarded = dequeue(&q);

            if (first_discard) {
                printf(" %d", discarded);
                first_discard = 0;
            } else {
                printf(", %d", discarded);
            }

            // Step 2: Move the next top card to the bottom
            int top_to_bottom = dequeue(&q);
            enqueue(&q, top_to_bottom);
        }

        // Print the final remaining card
        printf("\nRemaining card: %d\n", q.front->data);

        // Clean up remaining memory for safety
        dequeue(&q);
    }

    return 0;
}
