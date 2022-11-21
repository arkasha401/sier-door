#include "methods/open.h"
#include "methods/method.h"

void servo_open_pos(Command *command)
{
    command->value = OPEN_POSITION;
    command->method = Open; 
}

