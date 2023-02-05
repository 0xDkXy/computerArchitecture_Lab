#include "pipeline.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    pthread_t th_cpu;
    pthread_t th_pipe;

    while(timeClip){
        pthread_create(&th_cpu,NULL,cpu_running,"cpu: ");
        printf("emmm\n");
        // pthread_join(th_cpu,NULL);
        printf("timeClip: %d\n", timeClip);

        printf("connrun: %d\n", connrun);
        // 此时cpu与通道并行
        if(connrun == 1){
            printf("enter\n"); 
            pthread_create(&th_cpu,NULL,cpu_running,"cpu:");
            pthread_create(&th_pipe,NULL,pipe_exchange,"th_pipe:");
        }
 
        timeClip++;
        sleep(1);

    }
    

    return 0;
}
