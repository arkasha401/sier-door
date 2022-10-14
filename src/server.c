#include <stdlib.h>
#include "server.h"
#include "usart.h"

void
server_initialize(Server *server, unsigned long baudrate)
{ 
    usart_initialize(baudrate);
    server->buffer = (char *) malloc(sizeof(char) * MAX_BUFFER_LENGHT);

}

void
server_update(Server *server)
{

}
