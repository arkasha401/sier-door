#include "methods/close.h"
#include "stdbool.h"
#include "pins.h"
#include "servoc.h"
#include <Arduino.h>

bool 
method_close(Command *command)
{
    command->value = CLOSE_POSITION;
    command->method = Close;
    digitalWrite(13, HIGH);
    write(CLOSE_POSITION);
    return true;
}

