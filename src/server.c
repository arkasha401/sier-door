#include <stdlib.h>
#include "server.h"
#include "usart.h"
#include "stdbool.h"


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
        // server_process(server);
        server->message_complete = false;
    }

    if (usart_available()) 
    {
        char temp = usart_read(); 
        if(temp == '\n')
        {
            server->message_complete = true;
        }
        server->buffer[server->char_pointer] = temp;
        server->char_pointer++;
    }
}
