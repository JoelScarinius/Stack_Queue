#include "queue.h"
#include <stdlib.h>


//create a queue
//return the pointer that points to the queue 
Queue* create_queue() {
    Queue *q = (Queue*)malloc(sizeof(Queue)); // Allocates memmory on the heap for the queue;
    // q->front = (Node*)malloc(sizeof(Node));
    // q->rear = (Node*)malloc(sizeof(Node));
    q->front = q->rear = NULL;
    return q;
}

//add a task into the queue 
//parameters:
//  *q, the pointer that points to queue 
//  *t, the pointer that points to the printing task
void enqueue(Queue *q, Task *t) {
    // Node *front = (Node*)malloc(sizeof(Node));
    // Node *rear = (Node*)malloc(sizeof(Node));
    if(q->front == NULL || q->rear == NULL) {
        q->front->time_stamp = q->rear->time_stamp = t->time_stamp; PROMBLEMS WITH MEMORY HERE!!
        q->front->time_stamp = q->rear->time_stamp = t->pages;
        q->front->next = q->rear->next = NULL;
    }
    else {
        q->rear->next = t;
        q->rear = t;
        q->rear->next = NULL;
    }
}

//delete a task from the queue 
//parameters:
//  *q, the pointer that points to the queue 
//return the dequeued task
Task* dequeue(Queue *q) {
    if(q->front == NULL) printf("\n UNDERFLOW");
    else q->front = q->front->next;
    return q->front;
}

//display all the tasks in the queue 
//parameters:
//  *q, the pointer that points to the queue 
void display_queue(Queue *q) {
    if(q->front == NULL && q->rear == NULL) printf("\n QUEUE IS EMPTY");
    else {
        Node *ptr = q->front;
        printf("\n");
        while(ptr->next != NULL) {
            printf("[arravies at %d second, %d pages]", ptr->time_stamp, ptr->pages);
            ptr = ptr->next;
        }
        printf("[arravies at %d second, %d pages]", ptr->time_stamp, ptr->pages);
        // Task *t = ptr;
        // printf("\n");
        // while(ptr->next != NULL) {
        //     printf("[arravies at %d second, %d pages]", t->time_stamp, t->pages);
        //     ptr = ptr->next;
        //     t = ptr;
        // }
        // printf("[arravies at %d second, %d pages]", t->time_stamp, t->pages);
    }
}

//check whether the queue is empty
//parameters:
//  *q, the pointer that points to the queue 
int is_empty(Queue *q) {

}
