#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue* create_queue() { // Creates the queue where tasks will be stored.
    Queue *q = (Queue*)malloc(sizeof(Queue)); // Allocates memmory on the heap for the queue;
    if (q == NULL) { // If memory wasn't possible to allocate for any reason.
        puts("Failed to allocate memory on the heap!");
        exit(-1);
    }
    q->front = q->rear = NULL; // Initializes the queue to NULL, because at first the queue is empty.
    return q;
}
void enqueue(Queue *q, Task *t) { // Inserts a task at the end of the queue.
    Node *ptr = (Node*)malloc(sizeof(Node));
    if (ptr == NULL) { // If memory wasn't possible to allocate for any reason.
        puts("Failed to allocate memory on the heap!");
        exit(-1);
    }
    ptr->t = t;
    if(q->front == NULL) { // If queue is empty insert the task as the first task in the queue.
        q->front = q->rear = ptr;
        q->front->next = q->rear->next = NULL;
    }
    else { // Else insert the task at the end of the queue.
        q->rear->next = ptr;
        q->rear = ptr;
        q->rear->next = NULL;
    }
}
Task* dequeue(Queue *q) { // Delete a task from the queue.
    Node *ptr = q->front; // Dont need to check for underflow condition because this function will not be called if queue is empty.
    if (q->front == q->rear) { // If only 1 task is in the queue both front and rear is changed to be NULL beacuse now queue is empty. 
        q->front = q->rear = NULL;
    }
    else q->front = q->front->next; // Else front is changed to be the second task in the queue and the old front is returned.
    return ptr->t;
}
void display_queue(Queue *q) { // Displays all the tasks in the queue.
    if(is_empty(q) == 1) puts("QUEUE IS EMPTY");
    else {
        Node *ptr = q->front;
        puts("TASKS IN QUEUE:");
        while(ptr->next != NULL) {
            printf("TASK [arravies at %d second, %d pages]\n", ptr->t->time_stamp, ptr->t->pages);
            ptr = ptr->next;
        }
        printf("TASK [arravies at %d second, %d pages]\n", ptr->t->time_stamp, ptr->t->pages);
    }
}
int is_empty(Queue *q) { // Checks whether the queue is empty
    return (q->front == NULL && q->rear == NULL) ? 1 : 0;
}