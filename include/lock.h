#ifndef __LOCK_H__
#define __LOCK_H__

#include "server.h"
#include "stdint.h"

typedef struct Lock_S 
{
    uint8_t pin_button;
    uint8_t state;
    Server server;    
} Lock;

void
lock_initialize(Lock *lock, uint8_t pin_button, unsigned long baudrate, int pin_servo);

void
lock_update(Lock *lock);

#endif /* __LOCK_H__ */ 
