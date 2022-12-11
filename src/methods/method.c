#include "methods/method.h"
#include "methods/close.h"
#include "methods/open.h"
#include "servoc.h"
#include "mjson.h"
#include "stdbool.h"

void
command_initialize(Command *command)
{
    command->value = 0;
    command->method = None;
};

bool
status_check(Command *command, Method method, int pin)
{
    servo_attach(pin);
    if(method == Open)
    {
        if (read() == OPEN_POSITION) 
        {
            return true;
        };
    } else if (method == Close)
    {
        if(read() == CLOSE_POSITION) 
        {
            return true;
        }
    }
    return false;
} 