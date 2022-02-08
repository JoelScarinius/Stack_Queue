//the interface for the FIFO queue ADT
#include "task.h"

#ifndef QUEUE_H_ /* Include guard */
#define QUEUE_H_

typedef struct node { // This struct is used to create the nodes in the linkedlist.
	struct node *next; // This is the next node in the linkedlist.
	Task *t; // This is a pointer to the task structure.
} Node;
//declare queue
typedef struct queue { // This struct is representing the queue of nodes containing the tasks.
	Node *front, *rear; // Front is the starting node of the queue and rear is the end of the queue.
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