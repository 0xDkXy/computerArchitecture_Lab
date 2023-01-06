#include <iostream>
#include "huffman_coding.h"

int main(int argc, char **argv)
{
    	f_min_p *h,*h1;
    huff_p  *root;
	huff_code* head,*pl;
	
	int i=0;
//输入对应指令
	h=input_instruct_set();
	
/*
	p1=h;
	while(p1)
	{
		cout<<p1->p<<',';
		p1=p1->next;
	}
*/
    h1=h;
    root=creat_huffman_tree(h1);

    head=new huff_code;
	head->next=NULL;

    creat_huffman_code(root,head);
	//输出对应的操作数和编码
    output_huffman(head);
	//计算
    cal_sort_length(head);

//释放内存 new和delete配套使用
	pl=head->next;
	while(pl)
	{
		delete head;
		head=pl;
		pl=pl->next;
	}
        return 0;
}
