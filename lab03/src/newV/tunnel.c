#include "tunnel.h"
#include "message.h"
#include <pthread.h>

Tunnel *new_tunnel()
{
    Tunnel *tunnel = (Tunnel *) malloc(sizeof(Tunnel));
    tunnel->msgq = init_new_MessageQueue();
    mtx = PTHREAD_MUTeX_INITIALIZER;

    return tunnel;
}

void write_to_tunnel(Tunnel *destine, char chr, int did)
{
    Message *message = malloc_new_message();
    write_message(message, did, chr);
    int s;
    s = pthread_mutex_lock(&(destine->mtx));
    MessageQueue_append(destine->msgq, *message);
    s = pthread_mutex_unlock(&(destine->mtx));
}

Message get_from_tunnel(Tunnel *source)
{
    int s;
    s = pthread_mutex_lock(&(source->mtx));
    Message msg = MessageQueue_pop(source->msgq);
    s = pthread_mutex_unlock(&(source->mtx));
    return msg;
}

int tunnel_empty(Tunnel *tunnel)
{ return MessageQueue_empty(tunnel->msgq); }



