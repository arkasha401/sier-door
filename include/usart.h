#ifndef __USART_H__
#define __USART_H__


#include "stdbool.h"


void
usart_initialize(unsigned long baud);

int
usart_print_str(const char *str);

int
usart_println_str(const char *str);

bool
usart_available();

char
usart_read();

#endif /* __USART_H__ */
