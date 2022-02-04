#include "queue.h"
#include <stdlib.h>


//create a queue
//return the pointer that points to the queue 
Queue* create_queue() {
    Queue *q;
    q->front = q->rear = NULL;
    return q;
}

//add a task into the queue 
//parameters:
//  *q, the pointer that points to queue 
//  *t, the pointer that points to the printing task
void enqueue(Queue *q, Task *t) {
    Node *ptr;
    // ptr = (Node*)malloc(sizeof(Node));
    // ptr -> data = val;
    if(q->front == NULL) {
        q->front = ptr;
        q->rear = ptr;
        q->front->next = q->rear->next = NULL;
    }
    else {
        q->rear->next = ptr;
        q->rear = ptr;
        q->rear->next = NULL;
    }
    return q;
}

//delete a task from the queue 
//parameters:
//  *q, the pointer that points to the queue 
//return the dequeued task
Task* dequeue(Queue *q) {

}

//display all the tasks in the queue 
//parameters:
//  *q, the pointer that points to the queue 
void display_queue(Queue *q) {

}

//check whether the queue is empty
//parameters:
//  *q, the pointer that points to the queue 
int is_empty(Queue *q) {

}
