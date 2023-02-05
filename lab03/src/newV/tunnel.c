#include "tunnel.h"
#include "message.h"
#include <pthread.h>
#include <stdio.h>

Tunnel *new_tunnel()
{
    Tunnel *tunnel = (Tunnel *) malloc(sizeof(Tunnel));
    tunnel->msgq = init_new_MessageQueue();
	int s = pthread_mutex_init(&(tunnel->mtx), NULL);
	if ( s != 0 )
		printf("Error: mutex init failed!\n");

    return tunnel;
}

void write_to_tunnel(Tunnel *destine, char chr, int did)
{
    Message *message = malloc_new_message();
    write_message(message, did, chr);
	printf("write_to_tunnel %d\n", did);
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



