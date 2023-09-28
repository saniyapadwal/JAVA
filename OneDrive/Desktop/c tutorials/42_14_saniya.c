#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Deque {
    int arr[MAX_SIZE];
    int front, rear;
};

void initializeDeque(struct Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
}

int isEmpty(struct Deque *deque) {
    return (deque->front == -1 && deque->rear == -1);
}

int isFull(struct Deque *deque) {
    return ((deque->rear + 1) % MAX_SIZE == deque->front);
}

void insertFront(struct Deque *deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    deque->arr[deque->front] = data;
}

void insertRear(struct Deque *deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }

    deque->arr[deque->rear] = data;
}

int deleteFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete.\n");
        return -1;
    }

    int data = deque->arr[deque->front];

    if (deque->front == deque->rear) {
        deque->front = deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }

    return data;
}

int deleteRear(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete.\n");
        return -1;
    }

    int data = deque->arr[deque->rear];

    if (deque->front == deque->rear) {
        deque->front = deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }

    return data;
}

void display(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    int i = deque->front;
    while (1) {
        printf("%d ", deque->arr[i]);
        if (i == deque->rear) {
            break;
        }
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    struct Deque deque;
    initializeDeque(&deque);

    insertFront(&deque, 1);
    insertFront(&deque, 2);
    insertRear(&deque, 3);
    insertRear(&deque, 4);

    printf("Deque elements: ");
    display(&deque);

    printf("Deleted from front: %d\n", deleteFront(&deque));
    printf("Deleted from rear: %d\n", deleteRear(&deque));

    printf("Deque elements after deletion: ");
    display(&deque);


}
