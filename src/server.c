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
#include "pins.h"


void
server_initialize(Server *server, unsigned long baudrate)
{ 
    usart_initialize(baudrate);
    server->buffer = (char *) malloc(sizeof(char) * MAX_BUFFER_LENGHT);
    server->message_complete = false;
    server->char_pointer = 0;
    command_initialize(&(server->command));
    
    char buf[64];
    mjson_snprintf(buf, sizeof(buf), "{%Q:%Q, %Q:%Q}", "device", "lock", "method", "lock_init");
    usart_println_str(buf);
    server->wait_resp = true;
}


Method
server_update(Server *server)   
{

    if (server->message_complete)
    {
        server->message_complete = false;
        Method m = server_process(server);
        server->char_pointer = 0;
        return m;
    }
    if (usart_available()) 
    {
        if(server->char_pointer != MAX_BUFFER_LENGHT)
        { 
            char temp = usart_read(); 
            if(temp == '\n')
            {
                server->message_complete = true;
                server->buffer[server->char_pointer] = 0;
                 // '\0'
            }
            server->buffer[server->char_pointer++] = temp;
        }
        
    }
    return None;
}


Method
server_process(Server *server)
{
    // if (server->wait_resp)
    // {
    //     // bool res;
    //     // mjson_get_bool(server->buffer, server->char_pointer, "$.result", &res);
    //     // server->wait_resp = false;
    //     // if (!res) 
    //     // {
    //     //     // TODO error handling
    //     // }   
    // } 
    // if 
    // {

        char buf[MAX_BUFFER_LENGHT];
        Method my_method;
        //double val;
        //int res = mjson_get_string(server->buffer, server->char_pointer, "$.method", buf, sizeof(buf));
        if(strcmp(buf, "open") == 0)
        {
            my_method = Open;
        } 
        else if(strcmp(buf, "close") == 0)
        {
            my_method = Close;
            
        }
        else
        {
            my_method = None;
        }

        return my_method;
    }

    // return None;
// }


void
server_response(Server *server, bool re)
{
    char buff[256];
    mjson_snprintf(buff, sizeof(buff), "{%Q:%Q, %Q:%Q, %Q:{%Q:%u}}", "device", "lock", "method", "result", "value", "result", re);
    usart_println_str(buff);
} 
