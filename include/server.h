
#ifndef __SERVER_H__
#define __SERVER_H__

#include <stdbool.h>
#include <command.h>
#define MAX_BUFFER_LENGHT 256

typedef struct Server_S
{
    char *buffer;
    bool message_complete;
    int char_pointer;
    Command command;
} Server;


void command_initialize(Command *command); 

void
server_initialize(Server *server, unsigned long baudrate);

void
server_update(Server *server);

void
server_process(Server *server);

#endif /* __SERVER_H__ */