#include "LRU.h"
#include "utils.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

int is_cache_empty(Cache cache[])
{
    for (int i = 0; i < 4; ++i)
    {
        if (cache[i].op == 0)
            return i + 1;
    }
    return 0;
}

int is_cache_hit(Cache cache[], int num)
{
    for (int i = 0; i < 4; ++i)
    {
        if (num == cache[i].op)
        {
            cache[i].timeSet = 0;
            return i + 1;
        }
    }
    return 0;
}


int print_cache_content(Cache cache[])
{
    for (int i = 0; i < 4; ++i)
    {
        if (cache[i].op == 0)
            printf("Cache %d: No data ", i + 1);
        else
            printf("Cache %d: %d", i + 1, cache[i + 1].op);
    }
}

int get_low_prior_pos(Cache cache[])
{
    int j = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (cache[j].timeSet < cache[i].timeSet)
            j = i;
    }
    cache[j].timeSet = 0;
    return j;
}

void calc_result(int num[], int n, int recordMatrix[][12], Cache cache[])
{
    int i,j;
    for(j=0;j<12;j++){
            //判断命中-((不命中)-判断是否为空-(不为空)-判断优先级来换出--最后一行打上标记
            if(is_cache_hit(cache,num[j])){
                    for(i=0;i<4;i++){
                       recordMatrix[i][j] = cache[i].op; //op中的0 之后输出为空
                    }
                    recordMatrix[4][j] = 1; //1 标记为命中
                //命中 
            }
            else{
                int pos =is_cache_empty(cache)-1;
                if(pos+1){//未满
                   cache[pos].op = num[j];
                   for(i=0;i<4;i++){
                       recordMatrix[i][j] = cache[i].op; //op中的0 之后输出为空
                   }
                   recordMatrix[4][j] = 2; //2 标记为装入
                }
                else{
                    pos = get_low_prior_pos(cache);
                    cache[pos].op = num[j]; 
                    for(i=0;i<4;i++){
                       recordMatrix[i][j] = cache[i].op; //op中的0 之后输出为空
                   }
                   recordMatrix[4][j] = 3; //3 标记为置换
                }

            }
            for(i=0;i<4;i++){
                if(cache[i].op != 0) cache[i].timeSet++;
            }//每循环一次 时间设置加1;
    }
}

void print_show_UI(int num[], int n, int recordMatrix[][12], Cache cache[])
{
    printf("\nSequence\t");
    int i,j;
    for(i=0;i<n;i++){
        printf("%d\t",num[i]);
    }
    for(i=0;i<4;i++){
        printf("\nCache Block%d\t",i);
        for(j=0;j<12;j++){
            printf("%d\t",recordMatrix[i][j]);
            
        }
    }
    printf("\n\nResult\t\t");
    for(j=0;j<12;j++){
        if(recordMatrix[4][j]==1){
            set_background_color(GREEN);
            printf("Hit\t");
            reset_color();
        }
        if(recordMatrix[4][j]==2){
            set_background_color(BLUE);
            printf("Install\t");
            reset_color();
        }
        if(recordMatrix[4][j]==3){
            set_background_color(RED);
            printf("Replace\t");
            reset_color();
        }
    }
    printf("\n");
}

