#include "lock.h"
#include <stdlib.h>
#include "servoc.h"
#include "mjson.h"
#include "methods/method.h"
#include "server.h"
#include "methods/close.h"
#include "methods/open.h"

#include "usart.h"


void
lock_initialize(Lock *lock, uint8_t pin_button, unsigned long baudrate, int pin_servo)
{
    lock->pin_button = pin_button;   
    lock->state = 0; 
    server_initialize(&(lock->server), baudrate);
    servo_attach(pin_servo);
    write(CLOSE_POSITION);
}

void
lock_update(Lock *lock)
{
    Command command;
    bool re;
    Method e = server_update(&(lock->server));
    switch (e)
    {
        case Open:
            re = method_open(&command);
            break;
        case Close:
            re = method_close(&command);
            break;
        default:
            return;
    }
    server_response(&(lock->server), re);
}