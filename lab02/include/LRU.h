#ifndef _LRU
#define _LRU

typedef struct Cache
{
    int op;
    int timeSet;
} Cache;

int is_cache_empty(Cache cache[]);
int is_cache_hit(Cache cache[], int num);
int print_cache_content(Cache cache[]);
int get_low_prior_pos(Cache cache[]);
void calc_result(int num[], int n, int recordMatrix[][12], Cache cache[]);
void print_show_UI(int num[], int n, int recordMatrix[][12], Cache cache[]);


#endif