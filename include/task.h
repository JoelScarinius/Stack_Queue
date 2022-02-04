// The interface for the task ADT.
#ifndef TASK_H_ /* Include guard */
#define TASK_H_

//declare task
typedef struct task{
    //the timestamp when the printing task arrives 
    int time_stamp;
    //the number of pages to be printed in the task
    int pages;
} Task;

//create a printing task with the number of pages
//parameters:
//  p, the number of pages to be printed in the task
//return:
//  the pointer that points to to the task
Task* create_task(int p);
//compute the waiting time for the task
//parameters:
//  *t, the pointer that points to the printing task
//  ct, the current time (in second)
//return:
//  the waiting time (in seconds)
int wait_time(Task *t, int ct);

#endif