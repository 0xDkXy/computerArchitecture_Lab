#ifndef TUNNEL_H
#define TUNNEL_H

#include "message.h"
#include <pthread.h>

typedef struct Tunnel {
    pthread_mutex_t mtx;
    MessageQueue *msgq;
} Tunnel;

Tunnel *new_tunnel();

void write_to_tunnel(Tunnel *destine, char chr, int did);

Message get_from_tunnel(Tunnel *);

int tunnel_empty(Tunnel *);
#endif
