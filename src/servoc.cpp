#include <Servo.h>

extern Servo servo;
extern "C"
uint8_t
servo_attach(int pin)
{
	return servo.attach(pin);
}

extern "C"
void
servo_detach()
{
    servo.detach();
}

extern "C"
void
write(int value)
{
    servo.write(value);
}

extern "C"
int
read()
{
    return servo.read();
}