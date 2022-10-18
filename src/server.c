#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "server.h"
#include "usart.h"
#include "mjson.h"


void
server_initialize(Server *server, unsigned long baudrate)
{ 
    usart_initialize(baudrate);
    server->buffer = (char *) malloc(sizeof(char) * MAX_BUFFER_LENGHT);
    server->message_complete = false;
    server->char_pointer = 0;

}

void
server_update(Server *server)   
{
    if (server->message_complete)
    {
        server_process(server);
        server->message_complete = false;
    }
    if (usart_available()) 
    {
        if(server->char_pointer != MAX_BUFFER_LENGHT)
        { 
            char temp = usart_read(); 
            if(temp == '\n')
            {
                server->message_complete = true;
                server->buffer[server->char_pointer] = 0; // '\0'
            }
            server->buffer[server->char_pointer++] = temp;
        }
        printf("Buffer is overloaded");
    }
}


void
server_process(Server *server)
{
    char buf[server->char_pointer];
    mjson_get_string(server->buffer, server->char_pointer, "$.method", buf, sizeof(buf));
    if (!strcmp(buf,"Open") || !strcmp(buf, "Close")) 
    {
    }

}
