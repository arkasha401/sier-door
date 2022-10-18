
#ifndef __SERVER_H__
#define __SERVER_H__

#include <stdbool.h>
#define MAX_BUFFER_LENGHT 256

typedef struct Server_S
{
    char *buffer;
    bool message_complete;
    int char_pointer;
} Server;


typedef enum 
{
    Open, 
    Close
} Method; 


typedef struct Command_S
{
    int value;
    Method method;
} Command;


void
server_initialize(Server *server, unsigned long baudrate);

void
server_update(Server *server);

void
server_process(Server *server);

#endif /* __SERVER_H__ */