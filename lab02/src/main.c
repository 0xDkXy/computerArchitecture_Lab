#include "LRU.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    //初始化
    Cache cache[4];
    int i,j;
    for(i=0;i<4;i++){
        cache[i].op = 0;
        cache[i].timeSet= 0;
    }
    // printf("cache3 %d\n",cache[3].op);

    //大循环
    int num[12],recordMatrix[5][12],n;
    //样例 
    // 1 1 2 4 3 5 2 1 6 7 1 3
    printf("输入指令数: ");
    scanf("%d",&n);
    printf("请输入访问序列:");
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);//1 1 1 3 2 1 3 4 3 5 5 2
    }
    calc_result(num,n,recordMatrix,cache);//实现将结果放在recordMatrix中
    print_show_UI(num,n,recordMatrix,cache);//输出结果
    // for(j=0;j<=i;j++){
    //     // printf("%d\n",num[j]);
        
    // }
}