#ifndef PIPELINE
#define PIPELINE

// declare global var
extern int cpuRequestPipeBit;
extern int cpuResponseInterruptBit;
extern int cpuTranstoPipeMessage;
extern int onPipe;
extern int timeClip;
extern int connrun;

extern char memory1[13];
extern char memory2[13];
extern char memory3[13];

void *pipe_manager(int);
void *pipe_exchange();
void *cpu_running();

#endif