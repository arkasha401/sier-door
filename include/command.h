#ifndef __COMMAND_H__
#define __COMMAND_H__

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

#endif