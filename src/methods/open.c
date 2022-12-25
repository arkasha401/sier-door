#include "methods/open.h"
#include "methods/method.h"
#include <servoc.h>
#include "pins.h"
#include "Arduino.h"
#include "usart.h"
#include "stdio.h"


bool 
method_open(Command *command)
{
    command->value = 100;
    command->method = Open;
    printf("%d", 1);
    digitalWrite(13, HIGH);
    write(OPEN_POSITION);
    return true;
}

