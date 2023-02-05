#include "pipeline.h"


int is_flowline_empty(process *pro){//非空判断
    int i;
    for(i=0;i<4;i++){
        if(pro[i].mission_n!=0) 
            return 0; 
    }
    
    return 1;
}

void shift_to_next(process *pro, int input){ //数组操作 模拟流水线
    //operate & control
    int i;
    for(i=2;i>=0;i--){
        pro[i+1].mission_n = pro[i].mission_n;
    }
    pro[0].mission_n = input;
}

void record_onestep(process *pro,steprecord *head){ //记录每一步
    //实现从结构体数组取数据 放入链表
    //用新建链表
    steprecord *temp = head;
    steprecord *p = (steprecord *)malloc(sizeof(steprecord));
    
    p->next=temp->next;
    temp->next=p;//很重要 一定要记住
    int i;
    
    for(i=0;i<4;i++){
        p->onerecord[i] = pro[i].mission_n;
        
    }
    for(i=0;i<4;i++){
    printf("%d",p->onerecord[i]);
    }
   
    printf("\n");
}
    


void print_record(steprecord *head, int n){
    int i;
    double count = 0;
    for(i=3;i>=0;i--){
        steprecord *p = head;
        for(p = p->next ;p->next != NULL;p = p->next){
            if(p->onerecord[i] == 0){//no mission
                printf("    "); 
            }
            else{
                switch (i)
                {
                case 0:/* constant-expression */
                    printf("ED%d ",p->onerecord[i]);
                    break;
                case 1:
                    printf("EA%d ",p->onerecord[i]);
                    break;
                case 2:
                    printf("MA%d ",p->onerecord[i]);
                    break;
                case 3:
                    printf("NL%d ",p->onerecord[i]);
                    break;
                }
                // printf(" ");
            }
            if(i==0) count++;

        }
        printf("\n");
    }
    double throughout = n/count;
    double speed = 4*n/count;
    double efficiency = n/count;
    // printf("count %d  n %d\n",count,n);
    printf("吞吐率:%lf\n",throughout);
    printf("加速比:%lf\n",speed);
    printf("效率:%lf\n",efficiency);
}
