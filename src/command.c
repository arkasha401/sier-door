#include "command.h"

void
command_initialize(Command *command)
{
    command->value = 0;
    command->method = None;
}