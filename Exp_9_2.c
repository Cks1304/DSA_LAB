//9.2
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return -1;
    }
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

void printJosephusPositions(int count, int position) {
    struct Queue queue;
    queue.front = NULL;
    queue.rear = NULL;
    for (int i = 0; i < count; i++) {
        enqueue(&queue, i);
    }
    while (!isEmpty(&queue)) {
        for (int i = 1; i <= position; i++) {
            int eliminatedPosition = dequeue(&queue);
            if (i == position) {
                printf("%d ", eliminatedPosition);
                break;
            }
            enqueue(&queue, eliminatedPosition);
        }
    }
}

int main(int argc, char* argv[]) {
    int position = atoi(argv[1]);
    int count = atoi(argv[2]);
    printJosephusPositions(count, position);
    return 0;
}
