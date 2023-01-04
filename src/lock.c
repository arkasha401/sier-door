#include "lock.h"
#include <stdlib.h>
#include "servoc.h"
#include "mjson.h"
#include "methods/method.h"
#include "server.h"
#include "methods/close.h"
#include "methods/open.h"
#include "Arduino.h"
#include "usart.h"
#include "pins.h"


void
lock_initialize(Lock *lock, uint8_t pin_button, unsigned long baudrate, int pin_servo)
{
    lock->pin_button = pin_button;   
    lock->cb_state = true;
    lock->is_lock_opened= false;
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
    if (digitalRead(PIN_BUTTON)) 
    {
        method_open(&command);
        lock->is_lock_opened = true;
    } 
    if (lock->is_lock_opened) 
    {
        
        if(!digitalRead(STATE_BUTTON)) 
        {
            lock->cb_state = true;
        }
        if (lock->cb_state) 
        {
            if(digitalRead(STATE_BUTTON))
            {
                method_close(&command);
                lock->cb_state = false;
                lock->is_lock_opened = false;
            }
        }
    }

    
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
