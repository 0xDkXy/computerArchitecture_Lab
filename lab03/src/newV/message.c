#include "message.h"
#include <string.h>
#include <stdio.h>


Message *malloc_new_message()
{
    return (Message *) malloc(sizeof(Message));
    // Message *val = (Message *) malloc(sizeof(Message));
}


MessageItem *malloc_new_MessageItem() { return (MessageItem *) malloc(sizeof(MessageItem)); }

void init_MessageItem(MessageItem *msgi, Message msg)
{
    msgi->val = msg;
    msgi->next = NULL;
}

void write_message(Message *msg, int did, char chr)
{
    msg->did = did;
    msg->chr = chr;
}

MessageQueue *init_new_MessageQueue() 
{
    MessageQueue *msgQue = (MessageQueue *) malloc(sizeof(MessageQueue));
    msgQue->tail = (MessageItem *) malloc(sizeof(MessageItem));
    msgQue->tail->next = NULL;
    msgQue->head = msgQue->tail;
    msgQue->length = 0;
    return msgQue;
}

void MessageQueue_append(MessageQueue *msgQue, Message msg)
{
    msgQue->length ++;
    // MessageItem *hold = msgQue->tail;
    MessageItem *tmp_val = malloc_new_MessageItem();
#ifdef TEST
    puts("MessageItem malloced");
#endif
    init_MessageItem(tmp_val, msg);
#ifdef TEST
    puts(Message_to_str(&(tmp_val->val)));
    puts("MessageItem inited");
#endif
    (msgQue->tail)->next = tmp_val;
    msgQue->tail = tmp_val;
#ifdef TEST
    puts("message append all done");
#endif
}

char *Message_to_str(Message *msg)
{
    char *str = (char *) malloc(64); // max value  64 bytes
    char *tmp_str = (char *) malloc(64);
    sprintf(str, "The device ID: %d\t", msg->did);
    sprintf(tmp_str, "char: %c", msg->chr);
    strcat(str, tmp_str);
    return str;
}

void print_MessageQueue(MessageQueue *msgq)
{
#ifdef TEST
    puts("enter print_Mess");
#endif
    MessageItem *pointer;
    pointer = msgq->head->next;
    printf("Message Queue Print:\n");
    while ( pointer != NULL )
    {
        char *MessageStr = Message_to_str(&(pointer->val));
        puts(MessageStr);
        free(MessageStr);
        pointer = pointer->next;
    }
    puts("All Item printed!");
}

#ifdef TEST_MESSAGE
int main(int argc, char *argv[])
{
    // test message Queue
    MessageQueue *msgq = init_new_MessageQueue();
    if ( msgq )
        puts("message queue created!");
    char chr = 'a';
    for (int i = 0; i < 5; ++i)
    {
        Message *msg = malloc_new_message();
#ifdef TEST
        puts("message created");
#endif
        write_message(msg, i, chr + i);
#ifdef TEST
        puts("message wrote");
#endif
        MessageQueue_append(msgq, *msg);
#ifdef TEST
        puts("message appended");
#endif
        free(msg);
    }
    print_MessageQueue(msgq);
}
#endif
