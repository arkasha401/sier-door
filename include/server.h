
#ifndef __SERVER_H__
#define __SERVER_H__

#include <stdbool.h>
#include "methods/method.h"
#include "methods/method.h"
#define MAX_BUFFER_LENGHT 256

typedef struct Server_S
{
    char *buffer;
    bool wait_resp;
    bool message_complete;
    int char_pointer;
    Command command;
} Server;


void command_initialize(Command *command); 

void
server_initialize(Server *server, unsigned long baudrate);

Method
server_update(Server *server);

Method
server_process(Server *server);

void 
server_response(Server *server, bool re);


#endif /* __SERVER_H__ */
