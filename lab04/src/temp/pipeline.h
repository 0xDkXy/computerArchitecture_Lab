#ifndef PIPELINE_H
#define PIPELINE_H

extern int time; 

typedef struct process {
    int process_n;
    int mission_n;
} process;

typedef struct steprecord {
    struct steprecord *next;
    int onerecord[4];
} steprecord;

int is_flowline_empty(process *);

void shift_to_next(process *, int);


void record_onestep(process *, steprecord *);

void print_record(steprecord *, int );

#endif
