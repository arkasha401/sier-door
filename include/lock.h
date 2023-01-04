#ifndef __LOCK_H__
#define __LOCK_H__

#include "server.h"
#include "stdint.h"
#include "stdbool.h"

typedef struct Lock_S 
{
    uint8_t pin_button;
    Server server;   
    bool cb_state; 
    bool is_lock_opened;
} Lock;

void
lock_initialize(Lock *lock, uint8_t pin_button, unsigned long baudrate, int pin_servo);

void
lock_update(Lock *lock);


#endif /* __LOCK_H__ */ 
