#include "methods/close.h"


void servo_close_pos(Command *command)
{
    command->value = CLOSE_POSITION;
    command->method = Close; 
}