#include "pipeline.h"
#include "utils.h"
#include <stdio.h>


int main(int argc, char **argv)
{
    printf("input the number of instructions: ");
    int number;
    scanf("%d", &number);
    Instruction *instArray = init_instruction(number);
    int loop = 4 + number;
    printf("time\t");
    for (int i = 0; i < 4; ++i)
    {
        printf("S%d\t", i);
    }
    printf("\n");
    for (int i = 0; i < loop; ++i)
    {
        step(instArray, number);
        printf("T%d\t", i);
        print_stage(instArray, number);
    }
    printf("Tasks finished!\n");
    set_frontground_color(2);
    float tp = (float)(number) / (float)(loop - 1);
    printf("The Though Put of Pipeline: %f\n", tp);
    float sp = (float)(number * 4) / (float)(loop - 1);
    printf("The Speedup of the Pipeline: %f\n", sp);
    float eff = (float)(number * 4) / (float)((loop - 1) * 4);
    printf("The Efficiency of the Pipeline: %f\n", eff);
    reset_color();

    return 0;
}
