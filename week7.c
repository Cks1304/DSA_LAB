#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

bool isEmpty() {
    return top == NULL;
}

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    struct Node* temp = top;
    int poppedValue = temp->data;
    top = top->next;
    free(temp);
    return poppedValue;
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
    return top->data;
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Top element: %d\n", peek());

    while (!isEmpty()) {
        printf("%d ", pop());
    }
    printf("\n");

    return 0;
}
