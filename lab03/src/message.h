#ifndef MESSAGE_H
#define MESSAGE_H

#include <string.h>
#include <stdlib.h>

#define MESSAGE_LEN 64

typedef struct Message {
    int did; // the id of device;
    char chr;
} Message;

typedef struct MessageItem {
    Message val;
    struct MessageItem *next;
} MessageItem;

typedef struct MessageQueue {
    int length; // the length of message queue;
    MessageItem *head; // head pointer 
    MessageItem *tail; // tail pointer
} MessageQueue;

Message *malloc_new_message();

MessageItem *malloc_new_MessageItem(); 

void init_MessageItem(MessageItem *msgi, Message msg);

void write_message(Message *msg, int did, char chr);

MessageQueue *init_new_MessageQueue(); 

void MessageQueue_append(MessageQueue *msgQue, Message msg);

char *Message_to_str(Message *msg);

void print_MessageQueue(MessageQueue *);

Message MessageQueue_pop(MessageQueue *);

int MessageQueue_empty(MessageQueue *);



#endif
