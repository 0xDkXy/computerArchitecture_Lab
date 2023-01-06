#ifndef HUFFMAN_CODING
#define HUFFMAN_CODING

#include <iostream>
#include <cmath>

#define N 8

class huff_p
{
public:
    huff_p *r_child; // the point of high probility
    huff_p *l_child; // the point of low probility
    char op_mask[3]; // label of instruction
    float p;         // the probility of using instruction
};

class f_min_p
{
public:
    f_min_p *next;
    char op_mask[3]; // label of instruction
    float p;         // the probility of using instruction
    huff_p *huf_p;
};

// huff_man code
class huff_code
{
public:
    huff_code *next;
    float p;
    char op_mask[3];
    char code[N]; // huffman encode
};

f_min_p* input_instruct_set(); // get instructions

huff_p* creat_huffman_tree(f_min_p* head); // construct huffman tree
f_min_p* fin_min(f_min_p* h);
f_min_p* del_min(f_min_p* h, f_min_p* p);
void insert_n(f_min_p* h, f_min_p* p);
huff_p* creat_huffp(f_min_p* p);

void creat_huffman_code(huff_p* h1, huff_code* h);// generate huffman encoding
void r_find(huff_p* p1, char code[], int i, huff_code* h);
void output_huffman(huff_code* head); // output huffman encoding
void cal_sort_length(huff_code* head);// computing the average length of
// huffman encoding of instruction
#endif
