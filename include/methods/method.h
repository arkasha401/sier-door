#ifndef __COMMAND_H__
#define __COMMAND_H__
#define MAX_BUFFER_LENGHT 256
#include "stdbool.h"

typedef enum 
{
    Open, 
    Close,
    None
} Method; 

typedef struct Command_S
{
    int value;
    Method method;
} Command;

void
command_initialize(Command *command);

bool
status_check(Command *command, Method method, int pin); 
#endif