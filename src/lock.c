#include "lock.h"
#include <stdlib.h>
#include "servoc.h"


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
    server_update(&(lock->server));
}