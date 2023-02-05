#include "pipeline.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

Instruction* init_instruction(int number)
{
    Instruction *instructionArray;
    instructionArray = (Instruction *) malloc(3 * number * sizeof(Instruction));
    //for (int i = 0; i < 3 * number; ++i)
    //    instructionArray[i] = NULL;
    for (int i = 0; i < number; ++i)
    {
        instructionArray[i].stage = ED;
        instructionArray[i].ID = number - i;
    }
    return instructionArray;
}

void step(Instruction *instructionArray, int number)
{
    for (int i = number; i < number + 4; ++i)
    {
        if (!instructionArray[i].stage)
            continue;
        instructionArray[i].stage ++;
    }
    for (int i = 3 * number - 1; i > 0; --i)
    {
        instructionArray[i] = instructionArray[i - 1];
    }
    instructionArray[0].stage = 0;
    instructionArray[0].ID = 0;
}

char *decode(int code)
{
    switch(code)
    {
        case 0:
            return "  ";
        case 1:
            return "ED";
        case 2:
            return "EA";
        case 3:
            return "MA";
        case 4:
            return "NL";
    }
}


void print_stage(Instruction *instructionArray, int number)
{
    for (int i = number; i < number + 4; ++i)
    {
        char *inst = decode(instructionArray[i].stage);
        if (instructionArray[i].ID)
        {
            set_background_color(instructionArray[i].ID);
            printf("%s%d", inst, instructionArray[i].ID);
            reset_color();
            printf("\t");
        }
        else
            printf("%s \t", inst);
    }
    puts("");
}

