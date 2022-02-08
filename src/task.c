#include "task.h"
#include <stdlib.h>
#include <stdio.h>

Task* create_task(int p) { // Creates a printing task with a random number of pages.
    Task *t = (Task*)malloc(sizeof(Task)); // Allocates memory for a task on the heap.
    if (t == NULL) { // If memory wasn't possible to allocate for any reason.
        puts("Failed to allocate memory on the heap!");
        exit(-1);
    }
    t->pages = 1 + rand() % p; // Generates a random number of pages from 1-40 for the task.
    return t;
}
int wait_time(Task *t, int ct) { // Compute the waiting time for the task
    return (ct - t->time_stamp);
}