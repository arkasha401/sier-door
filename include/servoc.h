#ifndef __SERVOC_H__
#define __SERVOC_H__

#include <stdbool.h>
#include "stdint.h"

uint8_t
servo_attach(int pin);

void
servo_detach();

void
write(int value);

int
read();

#endif /* __SERVO_H__ */