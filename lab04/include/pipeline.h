#ifndef PIPELINE_H
#define PIPELINE_H

enum Stage {ED = 1, EA, MA, NL};

typedef struct Instruction {
    enum Stage stage;
    int ID;
} Instruction;

Instruction* init_instruction(int);

void step(Instruction *, int);

char *decode(int code);

void print_stage(Instruction *instructionArray, int number);

void set_color(int);

void reset_color();


#endif
