#ifndef __COMMAND_H__
#define __COMMAND_H__
#include "stdbool.h"

/*#define OPEN_POSITION


*/

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
    bool flag;
} Command;

void
command_initialize(Command *command);

bool 
command_check(Command *command, Method method, int pin); 
#endif