#include "printer.h"









//do one second of printing, 
//i.e. the remaning time to complete the current task is subtracted one. 
//parameters:
//  *p, the pointer points to the printer
void tick(Printer *p) {
    p->time_remaining--;
}

//check whehter the printer is printing
//parameters:
//  *p, the pointer points to the printer
//return 1 (true) or 0 (false)
int is_busy(Printer *p) {
    retrun (p->current_task->pages == 0) ? 1 : 0;
}

//start the next printing task
//parameters:
//  *p, the pointer points to the printer
//  *t, the pointer points to the printing task
void start_next(Printer *p, Task *t) {
    
}

//display the printer's current status
//  *p, the pointer points to the printer
void printer_status(Printer *p) {
    
}