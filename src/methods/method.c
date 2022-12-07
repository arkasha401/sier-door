#include "methods/method.h"
#include "methods/close.h"
#include "methods/open.h"
#include "servoc.h"
void
command_initialize(Command *command)
{
    command->value = 0;
    command->method = None;
};

void 
status_check(Command *command, Method method, int pin)
{
    servo_attach(pin);
    if(method == Open)
    {
        if (read() != OPEN_POSITION) 
        {

        };
    } else if (method == Close)
    {
        if(read() != CLOSE_POSITION) 
        {
            
        }
    }
} 