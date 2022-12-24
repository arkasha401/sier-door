#include "lock.h"
#include <stdlib.h>
#include "servoc.h"
#include "methods/method.h"
#include "server.h"
#include "methods/close.h"
#include "methods/open.h"

void
lock_initialize(Lock *lock, uint8_t pin_button, unsigned long baudrate, int pin_servo)
{
    lock->pin_button = pin_button;   
    lock->state = 0; 
    server_initialize(&(lock->server), baudrate);
    servo_attach(pin_servo);
}

void
lock_update(Lock *lock)
{
    Command command;
    Server server;
    Method e = server_update(&server);
    switch (e)
    {
    case Open:
        servo_open_pos(&command);
        break;
    case Close:
        servo_close_pos(&command);
    default:
        break;
    }
    // if was a cmd :
    //     server_response(c)
}   
