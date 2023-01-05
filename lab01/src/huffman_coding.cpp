#include "huffman_coding.h"

// huff_man tree point
class huff_p{
public:
    huff_p* r_child;
    huff_p* l_child;
    char op_mask[3];
    float p;
};
