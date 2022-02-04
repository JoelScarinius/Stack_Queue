#include "task.h"
#include <stdlib.h>
#include <stdio.h>

//create a printing task with the number of pages
//parameters:
//  p, the number of pages to be printed in the task
//return:
//  the pointer that points to to the task
Task* create_task(int p) {
    // Task *t = (Task*)malloc(sizeof(Task)); // Allocates memory for a task on the heap.
    Task *t;
    if (t == NULL) { // If memory wasn't possible to allocate for any reason.
        puts("Failed to allocate memory on the heap!");
        exit(-1);
    }
    t->time_stamp = 1;
    t->pages = p;
    return t;
}

//compute the waiting time for the task
//parameters:
//  *t, the pointer that points to the printing task
//  ct, the current time (in second)
//return:
//  the waiting time (in seconds)
int wait_time(Task *t, int ct) {
    return (ct - t->time_stamp);
}