#include "methods/close.h"
#include "stdbool.h"


bool servo_close_pos(Command *command)
{
    command->value = CLOSE_POSITION;
    command->method = Close;
    return true;
}

