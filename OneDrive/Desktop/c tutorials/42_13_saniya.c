#include <stdio.h>
#include <stdlib.h>

// Structure for the circular queue
struct CircularQueue {
    int* array;
    int front, rear, size;
};

// Function to create a circular queue of given size
struct CircularQueue* createQueue(int size) {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->size = size;
    queue->array = (int*)malloc(queue->size * sizeof(int));
    queue->front = queue->rear = -1;
    return queue;
}

// Function to check if the queue is full
int isFull(struct CircularQueue* queue) {
    return ((queue->front == 0 && queue->rear == queue->size - 1) ||
            (queue->rear == (queue->front - 1) % (queue->size - 1)));
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1);
}

// Function to enqueue an element into the circular queue
void enqueue(struct CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear = (queue->rear + 1) % queue->size;
    queue->array[queue->rear] = item;
    printf("%d enqueued to the queue.\n", item);
}

// Function to dequeue an element from the circular queue
int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int item = queue->array[queue->front];

    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % queue->size;

    return item;
}

// Function to display the contents of the circular queue
void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    int i;
    printf("Elements in the queue: ");
    if (queue->front <= queue->rear) {
        for (i = queue->front; i <= queue->rear; i++)
            printf("%d ", queue->array[i]);
    } else {
        for (i = queue->front; i < queue->size; i++)
            printf("%d ", queue->array[i]);

        for (i = 0; i <= queue->rear; i++)
            printf("%d ", queue->array[i]);
    }
    printf("\n");
}

// Function to free the allocated memory for the circular queue
void destroyQueue(struct CircularQueue* queue) {
    free(queue->array);
    free(queue);
}

int main() {
    int size, choice, item;

    printf("Enter the size of the circular queue: ");
    scanf("%d", &size);

    struct CircularQueue* queue = createQueue(size);

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                item = dequeue(queue);
                if (item != -1)
                    printf("Dequeued element: %d\n", item);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                destroyQueue(queue);
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
