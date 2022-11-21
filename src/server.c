#define MAX_VAL 32
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "server.h"
#include "methods/close.h"
#include "methods/open.h"
#include "usart.h"
#include "methods/method.h"
#include "mjson.h"


void
server_initialize(Server *server, unsigned long baudrate)
{ 
    usart_initialize(baudrate);
    server->buffer = (char *) malloc(sizeof(char) * MAX_BUFFER_LENGHT);
    server->message_complete = false;
    server->char_pointer = 0;
    command_initialize(&(server->command));
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
    char buf[MAX_VAL];
    double val;
    mjson_get_string(server->buffer, server->char_pointer, "$.method", buf, sizeof(buf));
    mjson_get_number(server->buffer, server->char_pointer, "$.value", &val);
    int value = (int) val;
    if ((strcmp(buf,"Open") == 0 || strcmp(buf, "Close") == 0) && value > 0) 
    {
        server->command.value = value;
        if(strcmp(buf, "Open") == 0)
        {
            servo_open_pos(&(server->command));
            //sender();
            //server->command.method = Open;

        } 
        else if(strcmp(buf, "Close") == 0)
        {
            servo_close_pos(&(server->command));
            //server->command.method = Close;
        }
        else 
        {
            server->command.method = None;
        }
    }

}
