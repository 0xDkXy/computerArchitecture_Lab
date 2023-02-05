#include "utils.h"
#include <stdio.h>

void set_background_color(int c)
{
    char buf[10];
    snprintf(buf, sizeof(buf), "\e[1;4%dm", c);
    printf("%s", buf);
}

void set_frontground_color(int c)
{
    char buf[10];
    snprintf(buf, sizeof(buf), "\e[1;3%dm", c);
    printf("%s", buf);
}

void reset_color() {printf("\e[0m");}
