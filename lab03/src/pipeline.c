#include "pipeline.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


// define global var
int cpuRequestPipeBit = 0; //为1时请求访管
int cpuResponseInterruptBit = 0; //为1时进行中断响应
int cpuTranstoPipeMessage = 0; //指定设备号
int onPipe = 0; //通道状态
int timeClip = 1; //时间片
int connrun = 0;

//内存单元 设备读取内容
char memory1[13] = "inpulge";
char memory2[13] = "diffuse";
char memory3[13] = "anitipute";
// implement of functions
void *pipe_manager(int i)
{
    if (i == 1)
    {
        printf("\n连接设备,正准备数据...\n");
        connrun = 1;
        printf("请求I/O操作\n");
        sleep(1);

        pthread_exit(NULL);
    }
    if (i == 2)
    {
        printf("递交数据给cpu...\n");
        sleep(1);
        printf("结束\n");
        pthread_exit(NULL);
    }
}

void *pipe_exchange()
{
    int point = timeClip; //模拟每次交换一波数据
    int connObjectNumber = cpuTranstoPipeMessage;//可以指定对应的设备号 为方便演示 此变量不使用
    int i;
    printf("connecting...\n");
    char device1[14];
    char device2[14];
    char device3[14];

    for(i=0;i<point;i++){
        device1[i] = memory1[i];
        device2[i] = memory2[i];
        device3[i] = memory3[i];
        device1[i+1] = '\0';
        device2[i+1] = '\0';
        device3[i+1] = '\0';
    }
    printf("设备1:%s\n",device1);
    printf("设备2:%s\n",device2);
    printf("设备3:%s\n",device3);
    cpuResponseInterruptBit = 1;
    if(i>=14) onPipe = 0;
}

void *cpu_running()
{
    while(timeClip){
        printf("cpu正在正常运行\n");
        if(rand()%100<5 || onPipe == 0){
            //模拟cpu运行时需要访管的情况
            cpuRequestPipeBit = 1;
        }
        if(cpuRequestPipeBit == 1 || onPipe == 1){//在管中直接运行
            printf("cpu正执行管理程序\n");    
            printf("处理数据中...\n");   
            sleep(1);   
            cpuTranstoPipeMessage = timeClip;
            onPipe = 1; 
            cpuRequestPipeBit = 0; //恢复到初始位           
            pthread_t th_pipeM;
            pthread_create(&th_pipeM,NULL,pipe_manager(1),"th_pipeManager");
            pthread_exit("cpu works done!");
        }
        if(cpuResponseInterruptBit == 1){
            pthread_t th_pipeM;
            pthread_create(&th_pipeM,NULL,pipe_manager(2),"th_pipeManager");

        }
        sleep(1);
    }
}
