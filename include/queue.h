//the interface for the FIFO queue ADT
#include "task.h"

#ifndef QUEUE_H_ /* Include guard */
#define QUEUE_H_

typedef struct node Node;

//declare queue
typedef struct queue {
	Node *front, *rear, *next;
} Queue;

//create a queue
//return the pointer that points to the queue 
Queue* create_queue();
//add a task into the queue 
//parameters:
//  *q, the pointer that points to queue 
//  *t, the pointer that points to the printing task
void enqueue(Queue *q, Task *t);
//delete a task from the queue 
//parameters:
//  *q, the pointer that points to the queue 
//return the dequeued task
Task* dequeue(Queue *q);
//display all the tasks in the queue 
//parameters:
//  *q, the pointer that points to the queue 
void display_queue(Queue *q);
//check whether the queue is empty
//parameters:
//  *q, the pointer that points to the queue 
int is_empty(Queue *q);


#endif