#include <HardwareSerial.h>


extern "C"
void
usart_initialize(unsigned long baud)
{
    Serial.begin(baud);
}

extern "C"
int
usart_print_str(const char *str)
{
	return Serial.print(str);
}

extern "C"
int
usart_println_str(const char *str)
{
	return Serial.print(str);
}

extern "C"
int
usart_available()
{
	return Serial.available();
}

extern "C"
char
usart_read()
{
	return (char)Serial.read();
}
