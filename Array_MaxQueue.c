#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct node {
    int priority;
    int data;
};

struct node pq[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int data, int priority) {
    struct node newItem;
    newItem.data = data;
    newItem.priority = priority;

    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (front == -1 && rear == -1) {
        front = rear = 0;
        pq[rear] = newItem;
        return;
    }

    int i;
    for (i = rear; i >= front; i--) {
        if (newItem.priority > pq[i].priority) {
            pq[i + 1] = pq[i];
        } else {
            break;
        }
    }

    pq[i + 1] = newItem;
    rear++;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    printf("Dequeued item: %d (Priority: %d)\n", pq[front].data, pq[front].priority);
    front++;

    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Priority Queue:\n");
    printf("Priority\tData\n");
    int i;
    for (i = front; i <= rear; i++) {
        printf("%d\t\t%d\n", pq[i].priority, pq[i].data);
    }
}

int main() {
    int choice, data, priority;

    printf("\nPriority Queue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");

    while (1) {
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(data, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
