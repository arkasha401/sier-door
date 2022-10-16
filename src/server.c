#define formatBool(b) ((b) ? "true" : "false")
#include <stdlib.h>
#include "server.h"
#include "usart.h"
#include "stdbool.h"


void
server_initialize(Server *server, unsigned long baudrate)
{ 
    usart_initialize(baudrate);
    server->buffer = (char *) malloc(sizeof(char) * MAX_BUFFER_LENGHT);

}

void
server_update(Server *server)
    {
    if (formatBool(usart_available())) {
        char temp = usart_read(); 
        if(temp == *"\n") {
           
        } 
        usart_read();        
    }      
}
