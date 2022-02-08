#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "task.h"
#include "queue.h"
#include "printer.h"

static void printWelcomeMessage(); // This function prints a short welcome message.

void main() { // LOOP s decrement by 1 second for every loop
    // One print task in n seconds. Length of print tasks ranges from 1 to m pages.
    int n = 2, m = 5, pages = 0, ct = 1;
    printWelcomeMessage();
    srand(time(NULL));
    Queue *q = create_queue();
    Task *t = create_task(m);
    Printer *p = (Printer*)malloc(sizeof(Printer));
    p->page_rate = 40;
    p->time_remaining = 0;
    while (ct != 10) {
        printer_status(p);
        if ((1 + rand() % 10) > 5 && pages < p->page_rate) {
            t = create_task(m);
            t->time_stamp = ct;
            pages += t->pages;
            enqueue(q, t);
        }
        if (p->time_remaining > 0) printf("%d seconds to complete the current task\n", p->time_remaining);
        display_queue(q);
        if (is_empty(q) == 0 && is_busy(p) == 0) {
            t = dequeue(q);
            start_next(p, t);
            p->time_remaining = t->pages + n;
        }
        if (p->time_remaining > 0) tick(p);
        ct++;
    }
    puts("\nSIMULATION ENDS");
    fflush(stdin);
    getchar();
}

static void printWelcomeMessage() { // Prints welcome message to the screen.
    puts("****************************************************************************************************\n"
        "Welcome!\n"
        "This is a program that uses a queue implemented as a linkedlist to create a simulation of a printer.\n"
        "Please enjoy!\n"
        "****************************************************************************************************");
}
